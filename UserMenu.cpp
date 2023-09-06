//
// Created by samuele on 04/09/23.
//

#include "UserMenu.h"
#include "FileHandlers/UserHandler.h"
#include "Listone.h"

UserMenu::UserMenu(AppState state) : state(state){
    std::string string;
    switch(state){
        case AppState::LogIn:
            string = "LogIn";
            break;
        case AppState::Register:
            string = "Register";
            break;
        default:
            throw std::runtime_error("");
    }
    State::printCharacter();
    State::printToCenter(string,'.');
    State::printCharacter();

}

State::AppState UserMenu::getStateName() {
    return state;
}

void UserMenu::draw() {
    std::string string;
    if(inputError){
        if(emailInput){
            switch(state){
                case AppState::LogIn:
                    string = "No email corresponding";
                    break;
                case AppState::Register:
                    string = "Not valid email";
                    break;
            }
        }else{
            if(state == AppState::LogIn)
                string= "Wrong password";
        }
        printErrorMessage(string);
        inputError = false;
    }
    if(emailInput){
        switch(state){
            case AppState::LogIn:
                string = "LogIn with email:";
                break;
            case AppState::Register:
                string = "Register with email:";
                break;
        }
    }else {
        switch (state) {
            case AppState::LogIn:
                string = "Insert password:";
                break;
            case AppState::Register:
                string = "Create a password:";
                break;
        }
    }
    std::cout << string <<  std::endl;
}

void UserMenu::handleInput(const std::string &line) {
    UserHandler handler;
    if(emailInput){
        if(handler.userExist(line)){
            switch(state){
                case AppState::LogIn:
                    emailInput = false;
                    username = line;
                    break;
                case AppState::Register:
                    inputError = true;
                    break;
            }
        }else{//not exists
            switch(state){
                case AppState::LogIn:
                    inputError = true;
                    break;
                case AppState::Register:
                    emailInput = false;
                    username = line;
                    break;
            }
        }
    }else{//password
        User* user = nullptr;
        switch(state){
            case AppState::LogIn:
               try{
                   user = handler.loadUser(username,line);
               }catch(ApplicationException& e){
                   if(e.getErrorType() == ApplicationException::ErrorType::LoadingFile)
                       printErrorMessage("Error occurred while loading the files");
               }
                break;
            case AppState::Register:
                try{
                    user = handler.createUser(username,line);
                }catch(ApplicationException& e){
                    if(e.getErrorType() == ApplicationException::ErrorType::LoadingFile)
                        printErrorMessage("Error occurred while loading the files");
                }
                break;
        }
        if(user != nullptr){
            Listone::getInstance()->setUser(*user);
            this->changeState(State::AppState::MainMenu);
        }
    }
}

//
// Created by samuele on 25/07/23.
//

#include "StartMenu.h"

StartMenu::StartMenu() {
    std::cout << "-----------------------------------------------" <<  std::endl;
    std::cout << "              Welcome to Listone!              " << std::endl;
    std::cout << "-----------------------------------------------" <<  std::endl;
    std::cout << "-----------------------------------------------" <<  std::endl;
}


void StartMenu::handleInput(const std::string& line) {
    int selection;
    try{
        selection = std::stoi(line);
    }catch(const std::invalid_argument & e){
        inputError = true;
    }
    switch(selection){
        case MenuIndex::Login:
            this->changeState(AppState::LogIn);
            break;
        case MenuIndex::Register:
            this->changeState(AppState::Register);
            break;
        case MenuIndex::Exit:
            //TODO exit
            break;
        default:
            inputError = true;
            break;
    }
}

State::AppState StartMenu::getStateName() {
    return AppState::StartMenu;
}

void StartMenu::draw() {
    if(inputError){
        std::cout << "!!!WARNING!!!" <<  std::endl;
        std::cout << "!!!Selection error!!!" <<  std::endl;
        inputError = false;
    }
    std::cout << "Select one of these option:" <<  std::endl;
    std::cout << "1)Log in" <<  std::endl;
    std::cout << "2)Register" <<  std::endl;
    std::cout << "3)Exit" <<  std::endl;
}

//
// Created by samuele on 25/07/23.
//

#include "StartMenu.h"

StartMenu::StartMenu() {
    State::printCharacter();
    State::printToCenter("Welcome to Listone!",'.');
    State::printCharacter();
    State::printCharacter();
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
        printErrorMessage("Selezione errata");
        inputError = false;
    }
    std::cout << "Select one of these option:" <<  std::endl;
    std::cout << "1)Log in" <<  std::endl;
    std::cout << "2)Register" <<  std::endl;
    std::cout << "3)Exit" <<  std::endl;
}

//
// Created by samuele on 25/07/23.
//

#include "StartMenu.h"

StartMenu::StartMenu() {
//TODO does all the initial stamp
}


void StartMenu::handleInput(const std::string &input) {

}

State::AppState StartMenu::getStateName() {
    return AppState::StartMenu;
}

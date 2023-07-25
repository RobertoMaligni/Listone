//
// Created by samuele on 25/07/23.
//

#include "StartMenu.h"

StartMenu::StartMenu() {
//TODO does all the initial stamp
}


void StartMenu::handleInput(const std::string &input) {
    int choice = std::stoi(input);
}

State::AppState StartMenu::getStateName() {
    return AppState::StartMenu;
}

void StartMenu::draw() {
//TODO draws menu
    std::cout << "-----------------------------------------------" <<  std::endl;
    std::cout << "              Welcome to Listone!              " << std::endl;
    std::cout << "-----------------------------------------------" <<  std::endl;
    std::cout << "-----------------------------------------------" <<  std::endl;
}

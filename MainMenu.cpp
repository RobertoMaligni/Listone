//
// Created by samuele on 06/09/23.
//

#include "MainMenu.h"
#include "Listone.h"

MainMenu::MainMenu() {
    //Listone::getInstance()->getCurrentUser().
    State::printToCenter("Welcome ",'-');
}

void MainMenu::draw() {

}

void MainMenu::handleInput(const std::string &line) {

}

State::AppState MainMenu::getStateName() {
    return State::AppState::ListView;
}

//
// Created by samuele on 03/07/23.
//

#include "Listone.h"
#include "Exceptions/ApplicationException.h"
#include "StartMenu.h"
#include "UserMenu.h"

//singleton stuff
Listone* Listone::instance = nullptr;

Listone *Listone::getInstance() {
    static Listone theInstance;
    instance = &theInstance;
    return instance;
}

Listone::Listone(const Listone& rs) {
    instance = rs.getInstance();
}

Listone& Listone::operator= (const Listone& rs) {
    if (this != &rs) {
        instance = rs.getInstance();
    }
    return *this;
}

Listone::Listone() {
    this->setNewState(State::AppState::StartMenu);
    running = true;
}

//state stuff
void Listone::setNewState(State::AppState newState){
    delete currentState;
    switch(newState){
        case State::AppState::StartMenu:
            currentState =  new StartMenu();
            break;
        case State::AppState::LogIn:
            currentState =  new UserMenu(State::AppState::LogIn);
            break;
        case State::AppState::Register:
            currentState =  new UserMenu(State::AppState::LogIn);
            break;
        case State::AppState::MainMenu:
            currentState = new MainMenu();
            break;
        case State::AppState::ListView:
            currentState =  nullptr;
            break;
        default:
            throw ApplicationException(ApplicationException::ErrorType::CorruptedAppState);
    }
}

State *Listone::getCurrentState() {
    return currentState;
}

bool Listone::isRunning() {
    return running;
}

void Listone::handleInput(const std::string &line) {
    currentState->handleInput(line);
}

void Listone::draw() {
    currentState->draw();
}

void Listone::setUser(User &user) {
    this->currentUser = new User(user);
}





//
// Created by samuele on 03/07/23.
//

#include "Listone.h"

void Listone::setNewState(State::AppState newState){
    delete currentState;
    switch(newState){
        case State::AppState::StartMenu:
            currentState =  nullptr;
            break;
        case State::AppState::LogIn:
            currentState =  nullptr;
            break;
        case State::AppState::Register:
            currentState =  nullptr;
            break;
        case State::AppState::MainMenu:
            currentState = nullptr;
            break;
        case State::AppState::ListCreator:
            currentState =  nullptr;
            break;
        case State::AppState::ListModify:
            currentState =  nullptr;
            break;
        default:
            throw std::runtime_error("");
    }
}





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




//
// Created by samuele on 25/07/23.
//

#ifndef LISTONE_STATE_H
#define LISTONE_STATE_H


#include <string>
#include <iostream>
#include <menu.h>

class State {
public:
    enum class AppState : short{
        StartMenu = 1,
        LogIn,
        Register,
        MainMenu,
        ListCreator,
        ListModify
    };
    virtual ~State() = default;
    virtual void changeState(AppState nextState);
    virtual void draw() = 0;
    virtual void handleInput(const std::string& input) = 0;
    virtual AppState getStateName() = 0;

};


#endif //LISTONE_STATE_H

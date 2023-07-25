//
// Created by samuele on 25/07/23.
//

#ifndef LISTONE_STARTMENU_H
#define LISTONE_STARTMENU_H


#include "State.h"

class StartMenu : public State{
public:
    StartMenu();

    //override
    ~StartMenu() override = default;
    void handleInput(const std::string &input) override;
    AppState getStateName() override;
};


#endif //LISTONE_STARTMENU_H

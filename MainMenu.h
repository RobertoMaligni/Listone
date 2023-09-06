//
// Created by samuele on 06/09/23.
//

#ifndef LISTONE_MAINMENU_H
#define LISTONE_MAINMENU_H


#include "State.h"

class MainMenu : public State{
public:
    MainMenu();

    //override
    ~MainMenu() override = default;
    void draw() override;
    void handleInput(const std::string& line) override;
    AppState getStateName() override;
};


#endif //LISTONE_MAINMENU_H

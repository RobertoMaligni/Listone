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
    void draw() override;
    void handleInput(const std::string &input) override;
    AppState getStateName() override;
private:

    enum MenuIndex : short{
        Login = 1,
        Register
    };

};


#endif //LISTONE_STARTMENU_H

//
// Created by samuele on 04/09/23.
//

#ifndef LISTONE_USERMENU_H
#define LISTONE_USERMENU_H


#include "State.h"
#include "User.h"

class UserMenu : public State{
public:
    UserMenu(AppState state);

    //override
    ~UserMenu() override = default;
    void draw() override;
    void handleInput(const std::string& line) override;
    AppState getStateName() override;

private:
    AppState state;
    bool emailInput = true;
    std::string username;
};


#endif //LISTONE_USERMENU_H

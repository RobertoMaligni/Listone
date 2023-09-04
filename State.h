//
// Created by samuele on 25/07/23.
//

#ifndef LISTONE_STATE_H
#define LISTONE_STATE_H

#include <string>
#include <iostream>
#include <menu.h>

#define CENTER_CHARACTERS 50

class State {
public:
    enum class AppState : short{
        StartMenu = 1,
        LogIn,
        Register,
        MainMenu,
        ListView,
    };
    virtual ~State() = default;
    virtual void changeState(AppState nextState);
    virtual void draw() = 0;
    virtual void handleInput(const std::string& line) = 0;
    virtual AppState getStateName() = 0;

protected:
    static void printErrorMessage(const std::string& error, bool warning = true);
    static void printToCenter(const std::string& string,char character = ' ');
    static void printCharacter(char character = '-', unsigned int quantity = CENTER_CHARACTERS );

    bool inputError = false;

};


#endif //LISTONE_STATE_H

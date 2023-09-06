//
// Created by samuele on 03/07/23.
//

#ifndef LISTONE_LISTONE_H
#define LISTONE_LISTONE_H

#include <string>
#include "User.h"
#include "FileHandlers/UserHandler.h"
#include "State.h"

class Listone {
public:
    static Listone* getInstance();

    //State utils
    void setNewState(State::AppState state);
    State* getCurrentState();
    bool isRunning();
    void handleInput(const std::string& line);
    void draw();

    /*//File utils
    void save();
    static bool savedFileExists();
    void loadSaves();*/

    void setCurrentUser(User& user);
    const User *getCurrentUser() const;

private:
    Listone();
    Listone(const Listone& rs);
    Listone& operator= (const Listone& rs);

    //TODO
    bool running;
    User* currentUser;
    State* currentState;
    static Listone* instance;
};

#endif //LISTONE_LISTONE_H

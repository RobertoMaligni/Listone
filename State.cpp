#include "State.h"
#include "Listone.h"

void State::changeState(AppState nextState) {
    Listone::getInstance()->setNewState(nextState);
}

void State::printErrorMessage(const std::string &error, bool warning) {
    if(warning)
        std::cout << "!!!WARNING!!!" << std::endl;
    std::cout << "!!!" << error << "!!!" << std::endl;
    std::cout << std::endl;
}

void State::printToCenter(const std::string &string, char character) {
    if(string.size() > CENTER_CHARACTERS)
        throw std::runtime_error("");
    int center = (CENTER_CHARACTERS - (int)string.size())/2;
    while(center != 0){
        std::cout << character;
        center--;
    }
    std::cout << string << std::endl;
    center = (CENTER_CHARACTERS + (int)string.size())/2;
    while(center != CENTER_CHARACTERS){
        std::cout << character;
        center++;
    }
}

void State::printCharacter(char character, unsigned int quantity) {
    while(quantity != 0){
        std::cout << character;
        quantity--;
    }
    std::cout << std::endl;
}

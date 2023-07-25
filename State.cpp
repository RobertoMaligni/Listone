#include "State.h"
#include "Listone.h"

void State::changeState(AppState nextState) {
    Listone::getInstance()->setNewState(nextState);
}
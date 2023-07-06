//
// Created by samuele on 02/07/23.
//

#ifndef LISTONE_SUBJECT_H
#define LISTONE_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() const = 0;
    virtual ~Subject() = default;
};


#endif //LISTONE_SUBJECT_H

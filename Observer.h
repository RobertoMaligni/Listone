//
// Created by samuele on 02/07/23.
//

#ifndef LISTONE_OBSERVER_H
#define LISTONE_OBSERVER_H


#include <string>

class Observer {
public:
    virtual void update(int listID, std::string& itemName,int quantity) = 0;
    virtual ~Observer() = default;
};


#endif //LISTONE_OBSERVER_H

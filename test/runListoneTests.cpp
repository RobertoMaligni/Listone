#include "gtest/gtest.h"
#include "../Listone.h"

TEST(Listone,Instantiation){
    //TODO
    Listone* listone = Listone::getInstance();
    ASSERT_TRUE(listone->isRunning());
}

TEST(Listone, LoginUser){
    Listone* listone = Listone::getInstance();
    listone->loginUser("","");
    listone->loginUser("FrancescoTotti","password"); //correct
    listone->loginUser("FrancescoTotti","passwordsbagliata");
    listone->loginUser("FrancescoTotti","");
    listone->loginUser("","password");
}
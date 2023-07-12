#include "gtest/gtest.h"
#include "../Listone.h"

TEST(ListoneTest,Instantiation){
    //TODO
    Listone* listone = Listone::getInstance();
    ASSERT_TRUE(listone->isRunning());
}

TEST(ListoneTest, LoginUser){
    Listone* listone = Listone::getInstance();
    try {
        EXPECT_ANY_THROW(listone->loginUser("", ""));
    }catch(std::runtime_error& e){
        EXPECT_STREQ("Parameters cannot be empty", e.what());
    }
    try{
        EXPECT_ANY_THROW(listone->loginUser("FrancescoTotti", ""));
    }catch(std::runtime_error& e){
        EXPECT_STREQ("Parameters cannot be empty", e.what());
    }
    try{
        EXPECT_ANY_THROW(listone->loginUser("", "password"));
    }catch(std::runtime_error& e){
        EXPECT_STREQ("Parameters cannot be empty", e.what());
    }
    try {
        EXPECT_ANY_THROW(listone->loginUser("FrancescoTotti", "passwordsbagliata"));
    }catch(std::runtime_error& e){}
    ASSERT_NO_FATAL_FAILURE(listone->loginUser("FrancescoTotti","password")); //correct
}


/*
TEST(Listone,RegisterUser){
    Listone* listone = Listone::getInstance();
    listone->registerUser("","");
    listone->registerUser("FrancescoTotti","");
    listone->registerUser("","password");
    listone->registerUser("FrancescoTotti","password");
    listone->registerUser("FrancescoTotti","passwordDiversa");
    listone->registerUser("NewUser","password");//correct
}
*/
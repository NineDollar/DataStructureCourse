//
// Created by NineDollar on 2022/4/22.
//
#include "gtest.h"
#include "prim.h"

TEST(test, test){
    EXPECT_EQ(add(1,2),4);
}

TEST(test2,test2){
    EXPECT_EQ(1,1);
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
//
// Created by NineDollar on 2022/4/22.
// Copyright (c) 2020年 NineDollar. All rights reserved.

#include "../googletest/include/gtest/gtest.h"
#include <boost/format.hpp>

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"  // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h" // support for user defined types

using namespace std;
using namespace spdlog;
TEST(test, test) {

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
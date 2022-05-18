//
// Created by NineDollar on 2022/4/22.
// Copyright (c) 2020年 NineDollar. All rights reserved.

#include "../googletest/include/gtest/gtest.h"
#include <boost/format.hpp>

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"  // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h" // support for user defined types
#include <boost/lambda/lambda.hpp>

using namespace std;
using namespace spdlog;

#include "boost/format.hpp"


TEST(test, test) {
    int a[] = {1, 2, 3, 4, 5};
    std::for_each(a, a + 5, [](int i) {
        std::cout << i << std::endl;
    });
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
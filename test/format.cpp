//
// Created by NineDollar on 2022/4/24.
//
#include "../googletest/include/gtest/gtest.h"
#include <boost/format.hpp>

using namespace std;

TEST(test, format) {
  using boost::format;  // 使用format

// 使用一
  format fmt("%1%    ,    %2%  !!!");  // 先定义对象
  fmt % 123;
  fmt % "hello";
  cout << fmt << endl;

// 使用二， 可以不按顺序，可以重复指定
  format fmt2(" %2%  ----- %1% -----   %2%  !!!");  // 先定义对象
  fmt2 % 123;
  fmt2 % "hello";
  cout << fmt2 << endl;

// 使用三， 可以重复使用
  format fmt3(" %2%  ----- %1% -----   %2%  !!!");
  fmt3 % 123;
  fmt3 % "hello";
  cout << fmt3 << endl;

  fmt3 % 1.23456;
  fmt3 % 'C';
  cout << __LINE__ << fmt3 << endl;

// 用法四，链式使用
  cout << format("****%1%****%2%!!!") % "hello" % 1.2345f << endl;
  cout << (format("****%1%****%2%!!!") % "hello") % 1.2345f << endl;

// 用法五，可以使用printf中的格式符
  cout << format(" %d   ,    %c   ,%f ,  %s") % 666 % 'A' % 1.2345f % "Boost" << endl;

// N$指定用哪个参数
  cout << format("---%2$s -----%1$s---") % "Boost" % "Hello" << endl;

// 用法六，直接转为string
  int age = 20;
  const char *name = "zhangsan";

// 替代sprintf
  format fmt6("name: %1%   age %2%");
  fmt6 % name % age;

  string strStu = fmt6.str();  // 直接转为字符串
  cout << strStu << endl;
}

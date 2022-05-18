// Created by NineDollar on 2022/4/26.
// Copyright (c) 2020年 NineDollar. All rights reserved.

#include<iostream>

using namespace std;

#include "../googletest/include/gtest/gtest.h"
#include<boost/typeof/typeof.hpp>
#include<boost/tokenizer.hpp>

using namespace boost;

TEST(tokenizer, test) {
    cout << "--------char_delimiters_separator分词--------" << endl;
    // string str = "My Name  is  Mr  Huang!";
    string str = "My!Name,is.Mr?Huang";
    tokenizer<> tok(str);  // 使用默认参数，采用空格或者标点符号分词
    for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it) {
        cout << *it << endl;
    }

    // 演示char_separator分词对象
    cout << "--------char_separator分词--------" << endl;
    string str2 = "My<Name>is<Mr<<Huang!";
    char_separator<char> sep(">" , "<",
                             keep_empty_tokens);
    tokenizer<char_separator<char>> tok2(str2, sep);
    for (BOOST_AUTO(it, tok2.begin()); it != tok2.end(); ++it) {
        cout << *it << endl;
    }

    // 演示escaped_list_separator
    cout << "--------escaped_list_separator分词--------" << endl;
    escaped_list_separator<char> sep3;  // 默认以，号分词
    string str3 = "My,Name,Is,Mr,\\\"Huang!\\\"";
    tokenizer<escaped_list_separator<char> > tok3(str3, sep3);
    for (BOOST_AUTO(it, tok3.begin()); it != tok3.end(); ++it) {
        cout << *it << endl;
    }

    // offset_separator分词
    cout << "--------offset_separator分词--------" << endl;

    // int  arr[3] = {2,3,4};
    // string  str4 = "22333444455555";
    // offset_separator   sep4(arr, arr + 3, false/*偏移量用完后继续分词*/);

    int arr[3] = {2, 3, 10};
    string str4 = "223334444";
    offset_separator sep4(arr, arr + 3, false, false/*是否返回分词不足的部分*/);

    tokenizer<offset_separator> tok4(str4, sep4);
    for (BOOST_AUTO(it, tok4.begin()); it != tok4.end(); ++it) {
        cout << *it << endl;
    }
}
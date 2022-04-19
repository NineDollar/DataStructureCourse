//
// Created by NineDollar on 2022/4/16.
// Copyright © 2020年 NineDollar. All rights reserved.

#include <cstdlib>
#include <iostream>
#include "1_1SqList.h"

using namespace std;

// 递归删除最大值
void RemoveMax(SqList &L, ElemType max=-1) {
    int indexMax; // 最大值的位置
    int flag = -1;
    if (max == -1) {
        max = L.data[0];  // 如果没有指定最大值，则默认为第一个元素
    }
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= max) {     // 找到最大值
            max = L.data[i];
            indexMax = i;
            flag = 1;
        }
    }
    if (flag == 1) { // 如果找到了最大值
        for (int i = indexMax; i < L.length; i++) {
            L.data[i] = L.data[i + 1];
        }
        L.length--;
    }else { // 没有找到最大值
        return;
    }
    RemoveMax(L, max);  // 递归删除
}

// 测试
void test2_2() {
    SqList L;
    InitList(L);
    InsElem(L, 10, 1);
    InsElem(L, 5, 2);
    InsElem(L, 6, 3);
    InsElem(L, 10, 4);
    InsElem(L, 4, 5);
    cout << "Before remove max:" << endl;
    DispList(L);

    RemoveMax(L);
    cout << "After remove max:" << endl;
    DispList(L);
}
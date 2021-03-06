//
// Created by NineDollar on 2022/4/16.
// Copyright © 2020年 NineDollar. All rights reserved.

#include <iostream>
#include "2_6_1_merge.h"
#include "1_1_sqList.h"

using namespace std;

// 合并两个有顺序表
void Merge(SqList &L1, SqList &L2, SqList &L3) {
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] < L2.data[j]) {  // 将L1的元素插入到L3中
            L3.data[k++] = L1.data[i++];
        } else { // 将L2的元素插入到L3中
            L3.data[k++] = L2.data[j++];
        }
    }
    while (i < L1.length) { // 将L1中剩余的元素插入到L3中
        L3.data[k++] = L1.data[i++];
    }
    while (j < L2.length) { // 将L2中剩余的元素插入到L3中
        L3.data[k++] = L2.data[j++];
    }
    L3.length = k; // 更新L3的长度
}

// 测试数据
void test2_6_1() {
    SqList L1, L2,L3;
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10};
    InitList(L1);
    InitList(L2);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L1, a[i], i + 1);
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        InsElem(L2, b[i], i + 1);
    }
    cout << "Before merge: " << endl;
    cout << "L1: ";
    DispList(L1);
    cout << "L2: ";
    DispList(L2);
//    合并
    Merge(L1, L2, L3);
    cout << "After merge: " << endl;
    cout << "L1: ";
    DispList(L3);
}
//
// Created by NineDollar on 2022/4/17.
// Copyright © 2020年 NineDollar. All rights reserved.
#include <iostream>
#include "1_2_slinkNode.h"

using namespace std;

// 合并两个有序链表
void CrossMerge(SLinkNode *&L1, SLinkNode *&L2, SLinkNode *&L3) {
    SLinkNode *p1 = L1->next, *p2 = L2->next, *p3 = L3;
    while (p1 != nullptr && p2 != nullptr) { // 当两个链表都不为空时
        p3->next = p1; // 将p1插入到p3的后面
        p1 = p1->next; // p1后移
        p3 = p3->next; // p3后移
        p3->next = p2; // 将p2插入到p3的后面
        p2 = p2->next; // p2后移
        p3 = p3->next; // p3后移
    }
    if (p1 == nullptr) { // 当p1为空时，将p2插入到p3的后面
        p3->next = p2;
    } else {
        p3->next = p1; // 当p2为空时，将p1插入到p3的后面
    }
}

// 测试数据
void test2_13() {
    SLinkNode *L1, *L2, *L3;
    InitList(L1);
    InitList(L2);
    InitList(L3);
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int b[] = {2, 4, 6, 8, 10};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L1, a[i], i + 1);
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        InsElem(L2, b[i], i + 1);
    }
    cout << "Before Merge:" << endl;
    cout << "L1: ";
    DispList(L1);
    cout << "L2: ";
    DispList(L2);
    cout << "After CrossMerge: " << endl;
    CrossMerge(L1, L2, L3);
    cout << "L3: ";
    DispList(L3);
}
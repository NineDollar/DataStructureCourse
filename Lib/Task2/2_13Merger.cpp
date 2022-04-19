//
// Created by NineDollar on 2022/4/17.
// Copyright © 2020年 NineDollar. All rights reserved.
#include <iostream>
#include "2_13Merger.h"
#include "1_2SLinkNode.h"

using namespace std;

void CrossMerge(SLinkNode *&L1, SLinkNode *&L2, SLinkNode *&L3) {
    SLinkNode *p1 = L1->next, *p2 = L2->next, *p3 = L3;
    while (p1 != nullptr && p2 != nullptr) {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    if (p1 == nullptr) {
        p3->next = p2;
    } else {
        p3->next = p1;
    }
}

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
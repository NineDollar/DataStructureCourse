//
// Created by NineDollar on 2022/4/17.
// Copyright © 2020年 NineDollar. All rights reserved.
#include <iostream>
#include "2_14SeparationNumber.h"
#include "1_2SLinkNode.h"

using namespace std;

// 分解数字
void SeparationNumber(SLinkNode *&L) {
//  创建三个点链表，分别存放小于0，等于0，大于0
    SLinkNode *p = L->next, *L1, *L2, *L3, *q1, *q2, *q3, *t;
    InitList(L1);
    InitList(L2);
    InitList(L3);
    q1 = L1;
    q2 = L2;
    q3 = L3;
    while (p != nullptr) {
        if (p->data < 0) { // 小于0
            q1->next = p;
            q1 = q1->next;
        } else if (p->data == 0) { // 等于0
            q2->next = p;
            q2 = q2->next;
        } else { // 大于0
            q3->next = p;
            q3 = q3->next;
        }
        p = p->next; // 指向下一个结点
    }
    q1->next = nullptr; // 小于0结尾
    q2->next = nullptr; // 等于0结尾
    q3->next = nullptr; // 大于0结尾
    q1->next = L2; // 小于0链表指向等于0链表
    L2->next = L3; // 等于0链表指向大于0链表
    L = L1; // 返回小于0链表
}

// 测试
void test2_14() {
    SLinkNode *L;
    InitList(L);
    int a[] = {9, 0, -1, 0, 0, 3, -1, 456, 78, 0};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L, a[i], i + 1);
    }
    cout << "Before Separation:" << endl;
    DispList(L);
    cout << "After Separation:" << endl;
    SeparationNumber(L);
    DispList(L);
}
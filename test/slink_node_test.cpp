//
// Created by NineDollar on 2022/4/26.
//


#include "../googletest/include/gtest/gtest.h"
#include "../include/task2/1_2_slinkNode.h"
#include <iostream>
using namespace std;

void split(SLinkNode *&A, SLinkNode *&B) {
    SLinkNode *p = A->next, *eq, *oq;
    eq = A;
    B = (SLinkNode *) malloc(sizeof(SLinkNode));
    B->next = nullptr;
    oq = B;
    while (p != nullptr) {
        if (p->data % 2 == 0) {
            eq->next = p;
            eq = p;
        } else {
            oq->next = p;
            oq = p;
        }
        p = p->next;
    }
    eq->next = nullptr;
    oq->next = nullptr;
}

void insert(SLinkNode *&L, ElemType x) {
    SLinkNode *p = L->next, *q = L;
    SLinkNode *data;
    data = (SLinkNode *) malloc(sizeof(SLinkNode));
    data->data = x;
    while (p != nullptr && p->data <= x) {
        q = p;
        p = p->next;
    }
    data->next = p;
    q->next = data;
}

TEST(SlinkNodeTest, test) {
    SLinkNode *L;
    InitList(L);
    InsElem(L, 1, 1);
    InsElem(L, 2, 2);
    InsElem(L, 3, 3);
    InsElem(L, 4, 4);
    InsElem(L, 5, 5);
    InsElem(L, 7, 6);
    InsElem(L, 8, 7);
    InsElem(L, 9, 8);
    cout << "链表为：" << endl;
    DispList(L);
    cout << "插入12后：" << endl;
    insert(L, 6);
    DispList(L);
}
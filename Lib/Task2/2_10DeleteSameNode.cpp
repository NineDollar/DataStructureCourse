//
// Created by NineDollar on 2022/4/17.
// Copyright © 2020年 NineDollar. All rights reserved.
#include <iostream>
#include "2_10DeleteSameNode.h"
#include "1_2SLinkNode.h"
using namespace std;

void DeleteSameNode(SLinkNode *L){
    SLinkNode *p = L;
    SLinkNode *q = L;
    while(p != nullptr){
        while(q->next != nullptr){
            if(p->data == q->next->data){
                q->next = q->next->next;
            }
            else{
                q = q->next;
            }
        }
        p = p->next;
        q = p;
    }
}

// 删除重复值测试
void test2_10(){
    SLinkNode *L;
    InitList(L);
    int a[] = {1,2,4,4,5,10,2,8,9,10};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L, a[i], i + 1);
    }
    cout << "Before delete:" << endl;
    DispList(L);
    cout << "After delete:" << endl;
    DeleteSameNode(L);
    DispList(L);
}
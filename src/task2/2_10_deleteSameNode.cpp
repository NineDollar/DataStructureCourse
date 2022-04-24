//
// Created by NineDollar on 2022/4/17.
// Copyright © 2020年 NineDollar. All rights reserved.
#include <iostream>
#include "1_2_slinkNode.h"

using namespace std;

// 删除链表中重复的节点
void DeleteSameNode(SLinkNode *L){
    SLinkNode *p = L;
    SLinkNode *q = L;
    while(p != nullptr){
        while(q->next != nullptr){
            if(p->data == q->next->data){ // 删除重复节点
                q->next = q->next->next;
            }
            else{
                q = q->next; // 指向下一个节点
            }
        }
        p = p->next; // 指向下一个节点
        q = p;  // 重新开始比较
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
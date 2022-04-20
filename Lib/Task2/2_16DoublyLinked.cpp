//
// Created by NineDollar on 2022/4/18.
// Copyright ? 2020年 NineDollar. All rights reserved.
#include <iostream>
#include <cstdlib>
#include "2_16DoublyLinked.h"

using namespace std;

typedef int ElemType;

typedef struct Node {
    int data; //数据域
    int freq; // 记录该节点的频率
    struct Node *next;  //指向下一个节点
    struct Node *prev;  //指向上一个节点
} DLinkNode;

// 初始化双向链表
void InitList(DLinkNode *&L) {
    L = (DLinkNode *) malloc(sizeof(DLinkNode));
    L->prev = L->next = nullptr;
}

// 销毁双向链表
void DestroyList(DLinkNode *&L) {
    DLinkNode *pre = L, *p = pre->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

// 求双向链表的长度
int GetLength(DLinkNode *&L) {
    int i = 0;
    DLinkNode *p = L->next;
    while (p != nullptr) {
        i++;
        p = p->next;
    }
    return i;
}

// 获取双向链表的第i个节点
int GetElems(DLinkNode *&L, int i, ElemType &e) {
    int j = 0;
    DLinkNode *p = L;
    if (i <= 0) {
        return 0;
    }
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        return 0;
    } else {
        e = p->data;
        return 1;
    }
}

// 按值查找双向链表中的元素
int Locate(DLinkNode *&L, ElemType e) {
    int i = 1;
    DLinkNode *p = L->next;
    while (p != nullptr && p->data != e) {
        p = p->next;
        i++;

    }
    if (p == nullptr) {
        return 0;
    } else {
        return i;
    }
}

// 在双向链表中插入元素
int InsElem(DLinkNode *&L, ElemType x, int i) {
    int j = 0;
    DLinkNode *p = L, *s;
    if (i <= 0) {
        return 0;
    }
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        return 0;
    } else {
        s = (DLinkNode *) malloc(sizeof(DLinkNode));
        s->data = x;
        s->freq = 0;
        s->next = p->next;
        if (s->next != nullptr) {
            s->next->prev = s;
        }
        s->prev = p;
        p->next = s;
        return 1;
    }
}

// 删除双向链表中的第i个元素
int DelElem(DLinkNode *&L, int i) {
    int j = 0;
    DLinkNode *p = L, *pre;
    if (i <= 0) {
        return 0;
    }
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        return 0;
    } else {
        pre = p->prev;
        if (p->next != nullptr) {
            p->next->prev = pre;
        }
        pre->next = p->next;
        free(p);
        return 1;
    }
}

// 打印双向链表
void DispList(DLinkNode *&L) {
    DLinkNode *p = L->next;
    while (p != nullptr) {
        cout << p->data << "-" << p->freq << "  ";
        p = p->next;
    }
    cout << endl;
}

// 按照频率排序
void LocateNode(DLinkNode *&L, ElemType x) {
    DLinkNode *p = L->next, *q = L->next;
    while (p != nullptr) {
        if (p->data == x) { // 找x元素
            p->freq += 1; // 元素频率加1
            while (q != nullptr) {
                if (q->freq > p->freq) { // 找到小于当前元素频率的元素
                    q = q->next;
                } else {
                    break;
                }
            }
            if (q != nullptr && q != p) { // 将x元素插入到q元素之前
                p->prev->next = p->next; // 将x元素的前一个元素的next指向x元素的next
                q->prev->next = p; // 将q元素的前一个元素的next指向x元素
                if (p->next != nullptr) { // 将x元素的next指向q元素
                    p->next->prev = p->prev; // 将x元素的next的prev指向x元素的prev
                }
                p->prev = q->prev; // 将x元素的prev指向q元素的prev
                p->next = q; // 将x元素的next指向q元素
                q->prev = p; // 将q元素的prev指向x元素
            }
            break;
        }
        p = p->next;
    }
}

// 测试
void test2_16() {
    DLinkNode *L;
    InitList(L);
    int a[] = {1, 3, 5, 7, 9};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L, a[i], i + 1);
    }
    DispList(L);
    cout << "After sort:" << endl;
    for (int i = 0; i < 3; ++i) { //访问3次
        LocateNode(L, 5);
    }
    LocateNode(L, 1); //访问1次
    for (int i = 0; i < 8; ++i) { //访问8次
        LocateNode(L, 7);
    }
    DispList(L);
    DestroyList(L);
}

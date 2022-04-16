//
// Created by NineDollar on 2022/4/15.
//
#include <iostream>

using namespace std;

typedef int ElemType;

// 单链表节点
typedef struct SLinkNode {
    ElemType data;
    struct SLinkNode *next;
} SLinkNode;

// 初始化链表
void InitList(SLinkNode *&L) {
    L = (SLinkNode *) malloc(sizeof(SLinkNode));
    L->next = nullptr;
}

// 销毁线性表
void DestroyList(SLinkNode *&L) {
    SLinkNode *pre = L->next, *p = pre->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

// 求线性表长度
int GetLength(SLinkNode *L) {
    int len = 0;
    SLinkNode *p = L->next;
    while (p != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}

// 求线性表中第i个元素
int GetElem(SLinkNode *L, int i, ElemType &e) {
    int j = 0;
    SLinkNode *p = L;
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }
    if (p == nullptr || j > i) {
        return 0;
    } else {
        e = p->data;
        return 1;
    }
}

//按值查找
int Locate(SLinkNode *L, ElemType e) {
    SLinkNode *p = L->next;
    int j = 1;
    while (p != nullptr && p->data != e) {
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        return 0;
    } else {
        return j;
    }
}

//插入元素
int InsElem(SLinkNode *&L, ElemType x, int i) {
    int j = 0;
    SLinkNode *p = L, *s;
    if (i < 0) {
        return 0;
    }
    while (p != nullptr && j < i-1) {
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        return 0;
    } else {
        s = (SLinkNode *) malloc(sizeof(SLinkNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}

// 删除元素
int DelElem(SLinkNode *&L, int i) {
    int j = 0;
    SLinkNode *p = L, *q;
    if (i < 0) {
        return 0;
    }
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        return 0;
    } else {
        q = p->next;
        if (q == nullptr) {
            return 0;
        } else {
            p->next = q->next;
            free(q);
            return 1;
        }
    }
}
// 打印线性表
void DispList(SLinkNode *L) {
    SLinkNode *p = L->next;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

// 测试线性表
void test1_2(){
    int i;
    ElemType e;
    SLinkNode *L;
    InitList(L);
    InsElem(L, 1, 1);
    InsElem(L, 2, 2);
    InsElem(L, 3, 3);
    InsElem(L, 4, 4);
    InsElem(L, 5, 5);
    cout << "链表为：" << endl;
    DispList(L);
    cout << "长度：" << GetLength(L) << endl;
    i = 3;
    GetElem(L, i, e);
    cout << "第" << i << "个元素为：" << e << endl;
    e = 1;
    cout << "查找" << e << "的位置为：" << Locate(L, e) << endl;
    i = 4;
    cout << "删除第" << i << "个元素：" << endl;
    DelElem(L, i);
    cout << "链表为：" << endl;
    DispList(L);
    DestroyList(L);
}



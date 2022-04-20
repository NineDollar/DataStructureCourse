//
// Created by NineDollar on 2022/4/18.
// Copyright ? 2020�� NineDollar. All rights reserved.
#include <iostream>
#include <cstdlib>
#include "2_16DoublyLinked.h"

using namespace std;

typedef int ElemType;

typedef struct Node {
    int data; //������
    int freq; // ��¼�ýڵ��Ƶ��
    struct Node *next;  //ָ����һ���ڵ�
    struct Node *prev;  //ָ����һ���ڵ�
} DLinkNode;

// ��ʼ��˫������
void InitList(DLinkNode *&L) {
    L = (DLinkNode *) malloc(sizeof(DLinkNode));
    L->prev = L->next = nullptr;
}

// ����˫������
void DestroyList(DLinkNode *&L) {
    DLinkNode *pre = L, *p = pre->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

// ��˫������ĳ���
int GetLength(DLinkNode *&L) {
    int i = 0;
    DLinkNode *p = L->next;
    while (p != nullptr) {
        i++;
        p = p->next;
    }
    return i;
}

// ��ȡ˫������ĵ�i���ڵ�
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

// ��ֵ����˫�������е�Ԫ��
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

// ��˫�������в���Ԫ��
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

// ɾ��˫�������еĵ�i��Ԫ��
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

// ��ӡ˫������
void DispList(DLinkNode *&L) {
    DLinkNode *p = L->next;
    while (p != nullptr) {
        cout << p->data << "-" << p->freq << "  ";
        p = p->next;
    }
    cout << endl;
}

// ����Ƶ������
void LocateNode(DLinkNode *&L, ElemType x) {
    DLinkNode *p = L->next, *q = L->next;
    while (p != nullptr) {
        if (p->data == x) { // ��xԪ��
            p->freq += 1; // Ԫ��Ƶ�ʼ�1
            while (q != nullptr) {
                if (q->freq > p->freq) { // �ҵ�С�ڵ�ǰԪ��Ƶ�ʵ�Ԫ��
                    q = q->next;
                } else {
                    break;
                }
            }
            if (q != nullptr && q != p) { // ��xԪ�ز��뵽qԪ��֮ǰ
                p->prev->next = p->next; // ��xԪ�ص�ǰһ��Ԫ�ص�nextָ��xԪ�ص�next
                q->prev->next = p; // ��qԪ�ص�ǰһ��Ԫ�ص�nextָ��xԪ��
                if (p->next != nullptr) { // ��xԪ�ص�nextָ��qԪ��
                    p->next->prev = p->prev; // ��xԪ�ص�next��prevָ��xԪ�ص�prev
                }
                p->prev = q->prev; // ��xԪ�ص�prevָ��qԪ�ص�prev
                p->next = q; // ��xԪ�ص�nextָ��qԪ��
                q->prev = p; // ��qԪ�ص�prevָ��xԪ��
            }
            break;
        }
        p = p->next;
    }
}

// ����
void test2_16() {
    DLinkNode *L;
    InitList(L);
    int a[] = {1, 3, 5, 7, 9};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L, a[i], i + 1);
    }
    DispList(L);
    cout << "After sort:" << endl;
    for (int i = 0; i < 3; ++i) { //����3��
        LocateNode(L, 5);
    }
    LocateNode(L, 1); //����1��
    for (int i = 0; i < 8; ++i) { //����8��
        LocateNode(L, 7);
    }
    DispList(L);
    DestroyList(L);
}

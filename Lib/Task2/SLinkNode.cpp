//
// Created by NineDollar on 2022/4/15.
//
#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct SLinkNode {
    ElemType data;
    struct SLinkNode *next;
} SLinkNode;

// ��ʼ������
void InitList(SLinkNode *&L) {
    L = (SLinkNode *) malloc(sizeof(SLinkNode));
    L->next = nullptr;
}

// �������Ա�
void DestroyList(SLinkNode *&L) {
    SLinkNode *pre = L->next, *p = pre->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

// �����Ա���
int GetLength(SLinkNode *L) {
    int len = 0;
    SLinkNode *p = L->next;
    while (p != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}

// �����Ա��е�i��Ԫ��
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

//��ֵ����
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

//����Ԫ��
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

// ɾ��Ԫ��
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

void DispList(SLinkNode *L) {
    SLinkNode *p = L->next;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}


void testSLinkNode(){
    int i;
    ElemType e;
    SLinkNode *L;
    InitList(L);
    InsElem(L, 1, 1);
    InsElem(L, 2, 2);
    InsElem(L, 3, 3);
    InsElem(L, 4, 4);
    InsElem(L, 5, 5);
    cout << "����Ϊ��" << endl;
    DispList(L);
    cout << "���ȣ�" << GetLength(L) << endl;
    i = 3;
    GetElem(L, i, e);
    cout << "��" << i << "��Ԫ��Ϊ��" << e << endl;
    e = 1;
    cout << "����" << e << "��λ��Ϊ��" << Locate(L, e) << endl;
    i = 4;
    cout << "ɾ����" << i << "��Ԫ�أ�" << endl;
    DelElem(L, i);
    cout << "����Ϊ��" << endl;
    DispList(L);
    DestroyList(L);
}



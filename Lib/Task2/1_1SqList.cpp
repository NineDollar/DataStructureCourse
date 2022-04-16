//
// Created by NineDollar on 2022/4/15.
//
#include <iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;

// ˳������Ͷ���
typedef struct SqList {
    ElemType data[MaxSize];
    int length;
}SqList;

//    ��ʼ��
void InitList(SqList &L) {
    L.length = 0;
}

//    �������Ա�
void DestroyList(SqList &L) {

}

//    ���Ա���
int GetLength(SqList &L) {
    return L.length;
}

//    �����Ա��i��Ԫ��
int GetElem(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) {
        return 0;
    } else {
        e = L.data[i - 1];
        return 1;
    }
}

//    ��ֵ����
int Locate(SqList &L, int x) {
    int i = 0;
    while (i < L.length && L.data[i] != x) {
        i++;
    }
    if (i < L.length) {
        return i + 1;
    } else {
        return 0;
    }
}

//    ����Ԫ��
int InsElem(SqList &L, ElemType x, int i) {
    if (i < 1 || i > L.length + 1) {
        cout << "����λ�ò��Ϸ�" << endl;
        return 0;
    }
    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = x;
    L.length++;
    return 1;
}

// ɾ��Ԫ��
int DelElem(SqList &L, int i) {
    int j;
    if (i < 1 || i > L.length) {
        cout << "ɾ��λ�ò��Ϸ�" << endl;
        return 0;
    }
    for (j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return 1;
}

// ������Ա�
void DispList(SqList &L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// ����
void test1_1() {
    int i;
    ElemType e;
    SqList L;
    InitList(L);
    InsElem(L, 1, 1);
    InsElem(L, 2, 2);
    InsElem(L, 3, 3);
    InsElem(L, 4, 4);
    InsElem(L, 5, 5);
    cout << "˳���" << endl;
    DispList(L);
    cout << "����: " << GetLength(L) << endl;
    i = 3;
    GetElem(L, i, e);
    cout << i << "��Ԫ��Ϊ��" << e << endl;
    e = 1;
    cout << e << "�ڵ�" << Locate(L, e) << "��λ��" << endl;
    DelElem(L, i);
    cout << "ɾ����" << endl;
    DispList(L);
    DestroyList(L);
}

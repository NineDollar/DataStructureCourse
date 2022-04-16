//
// Created by NineDollar on 2022/4/15.
//
#include <iostream>

using namespace std;

#define MaxSize 100
typedef int ElemType;

typedef struct SqList {
    ElemType data[MaxSize];
    int length;
} SqList; // 定义顺序表

//    初始化
void InitList(SqList &L) {
    L.length = 0;
}

//    销毁线性表
void DestroyList(SqList &L) {

}

//    线性表长度
int GetLength(SqList &L) {
    return L.length;
}

//    求线性表第i个元素
int GetElem(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) {
        return 0;
    } else {
        e = L.data[i - 1];
        return 1;
    }
}

//    按值查找
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

//    插入元素
int InsElem(SqList &L, ElemType x, int i) {
    if (i < 1 || i > L.length + 1) {
        cout << "插入位置不合法" << endl;
        return 0;
    }
    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = x;
    L.length++;
    return 1;
}

int DelElem(SqList &L, int i) {
    int j;
    if (i < 1 || i > L.length) {
        cout << "删除位置不合法" << endl;
        return 0;
    }
    for (j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return 1;
}

void DispList(SqList &L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void testSqList() {
    int i;
    ElemType e;
    SqList *L;
    L = (SqList *) malloc(sizeof(SqList));
    InitList(*L);
    InsElem(*L, 1, 1);
    InsElem(*L, 2, 2);
    InsElem(*L, 3, 3);
    InsElem(*L, 4, 4);
    InsElem(*L, 5, 5);
    cout << "顺序表：" << endl;
    DispList(*L);
    cout << "长度: " << GetLength(*L) << endl;
    i = 3;
    GetElem(*L, i, e);
    cout << i << "号元素为：" << e << endl;
    e = 1;
    cout << e << "在第" << Locate(*L, e) << "个位置" << endl;
    DelElem(*L, i);
    cout << "删除后：" << endl;
    DispList(*L);
    DestroyList(*L);
}

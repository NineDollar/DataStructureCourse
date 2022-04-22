//
// Created by NineDollar on 2022/4/16.
//

#ifndef DATASTRUCTURECOURSE_SQLIST_H
#define DATASTRUCTURECOURSE_SQLIST_H

#define MaxSize 100
typedef int ElemType;

typedef struct SqList{
    ElemType data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L);

void DestroyList(SqList &L);

int GetLength(SqList &L);

int GetElem(SqList &L, int i, ElemType &e);

int Locate(SqList &L, int x);

int InsElem(SqList &L, int i, ElemType x);

int DelElem(SqList &L, int i);

void DispList(SqList &L);

void test1_1();

#endif //DATASTRUCTURECOURSE_SQLIST_H

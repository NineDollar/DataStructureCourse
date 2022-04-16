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

//    初始化
void InitList(SqList &L);

//    销毁线性表
void DestroyList(SqList &L);

//    线性表长度
int GetLength(SqList &L);

//    求线性表第i个元素
int GetElem(SqList &L, int i, ElemType &e);

//    按值查找
int Locate(SqList &L, int x);

//    插入元素
int InsElem(SqList &L, int i, ElemType x);

int DelElem(SqList &L, int i);

void DispList(SqList &L);

void test1_1();

#endif //DATASTRUCTURECOURSE_SQLIST_H

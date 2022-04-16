//
// Created by NineDollar on 2022/4/16.
//

#include <cstdlib>
#include <iostream>
#include "1_1SqList.h"

using namespace std;

void RemoveMax(SqList &L, ElemType max=-1) {
    int indexMax; // 存储最大值的位置
    int flag = -1;
    if (max == -1) {
        max = L.data[0];  // 如果没有指定最大值，则默认为第一个元素
    }
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= max) {
            max = L.data[i];
            indexMax = i;
            flag = 1;
        }
    }
    if (flag == 1) {
        for (int i = indexMax; i < L.length; i++) {
            L.data[i] = L.data[i + 1];
        }
        L.length--;
    }else {
        return;
    }
    RemoveMax(L, max);
}

void main2_2() {
    SqList L;
    InitList(L);
    InsElem(L, 10, 1);
    InsElem(L, 5, 2);
    InsElem(L, 6, 3);
    InsElem(L, 10, 4);
    InsElem(L, 4, 5);
    cout << "Before remove max:" << endl;
    DispList(L);

    RemoveMax(L);
    cout << "After remove max:" << endl;
    DispList(L);
}
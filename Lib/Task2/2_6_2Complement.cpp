//
// Created by NineDollar on 2022/4/16.
//
#include <iostream>
#include "2_6_2Complement.h"
#include "1_1SqList.h"

using namespace std;

// 差集
void DifferenceSet(SqList &L1, SqList &L2, SqList &L3) {
    int i, j, k = 0;
    for (i = 0; i < L1.length; i++) {
        for (j = 0; j < L2.length; j++) {
            if (L1.data[i] == L2.data[j]) {
                break;
            }
        }
        if (j == L2.length) {
            L3.data[k++] = L1.data[i];
        }
    }
    L3.length = k;
}

// 测试
void test2_6_2() {
    SqList L1, L2, L3;
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int b[] = {2, 4, 6, 8, 10};
    InitList(L1);
    InitList(L2);
    InitList(L3);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L1, a[i], i + 1);
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        InsElem(L2, b[i], i + 1);
    }
    cout << "Before DifferenceSet: " << endl;
    cout << "L1: ";
    DispList(L1);
    cout << "L2: ";
    DispList(L2);

    DifferenceSet(L1, L2, L3);
    cout << "After DifferenceSet: " << endl;
    DispList(L3);
}

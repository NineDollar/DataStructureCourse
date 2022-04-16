//
// Created by NineDollar on 2022/4/16.
//

#include <iostream>
#include "2_6_1Merge.h"
#include "1_1SqList.h"

using namespace std;

void Merge(SqList &L1, SqList &L2, SqList &L3) {
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] < L2.data[j]) {
            L3.data[k++] = L1.data[i++];
        } else {
            L3.data[k++] = L2.data[j++];
        }
    }
    while (i < L1.length) {
        L3.data[k++] = L1.data[i++];
    }
    while (j < L2.length) {
        L3.data[k++] = L2.data[j++];
    }
    L3.length = k;
}

void test2_6_1() {
    SqList L1, L2,L3;
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10};
    InitList(L1);
    InitList(L2);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L1, a[i], i + 1);
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        InsElem(L2, b[i], i + 1);
    }
    cout << "Before merge: " << endl;
    cout << "L1: ";
    DispList(L1);
    cout << "L2: ";
    DispList(L2);
//    合并
    Merge(L1, L2, L3);
    cout << "After merge: " << endl;
    cout << "L1: ";
    DispList(L3);
}
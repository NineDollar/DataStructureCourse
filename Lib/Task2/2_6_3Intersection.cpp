//
// Created by NineDollar on 2022/4/16.
// Copyright © 2020年 NineDollar. All rights reserved.
#include <iostream>
#include "2_6_3Intersection.h"
#include "1_1SqList.h"
using namespace std;

// 交集
void Intersection(SqList &L1,SqList &L2, SqList &L3){
    int i,j,k;
    i=j=k=0;
    while(i<L1.length && j<L2.length){
        if(L1.data[i]==L2.data[j]){ // 如果两个顺序表中的数据相等
            L3.data[k++]=L1.data[i]; // 将相等的数据放入新的顺序表中
            i++;
            j++;
        }
        else if(L1.data[i]<L2.data[j]){   // 如果L1的数据小于L2的数据
            i++;
        }
        else{  // 如果L1的数据大于L2的数据
            j++;
        }
    }
    L3.length=k; // 更新顺序表的长度
}

void test2_6_3(){
    SqList L1, L2, L3;
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    InitList(L1);
    InitList(L2);
    InitList(L3);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        InsElem(L1, a[i], i + 1);
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        InsElem(L2, b[i], i + 1);
    }
    cout << "Before Intersection: " << endl;
    cout << "L1: ";
    DispList(L1);
    cout << "L2: ";
    DispList(L2);
    cout << "After Intersection: " << endl;
    Intersection(L1, L2, L3);
    DispList(L3);
}



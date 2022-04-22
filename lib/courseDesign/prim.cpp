//
// Created by NineDollar on 2022/4/19.
// Copyright (c) 2020年 NineDollar. All rights reserved.
// Prim普里姆算法求最小生成树

#include <iomanip>
#include "prim.h"
#include "gtest.h"
#include <iostream>

using namespace std;

/**
 * 创建邻接矩阵,并每个顶点赋值为无穷大,然后输入每个顶点的权值
 * @param cost
 * @return
 */
int create_cost(int **cost) {
    int vex_num, arc_num, v1, v2, w;
    cout << "请输入顶点数和边数: ";
    cin >> vex_num >> arc_num;
    for (int i = 1; i < vex_num; ++i) {
        for (int j = 0; j < vex_num; ++j) {
            cost[i][j] = 32767;
        }
    }
    for (int k = 1; k < arc_num; ++k) {
        cout << "v1 v2 w= ";
        cin >> v1 >> v2 >> w;
        cost[v1][v2] = w;
        cost[v2][v1] = w;
    }
    return vex_num;
}

void print_matrix(int **cost, int vex_num) {
    for (int i = 0; i < vex_num * 13; ++i) {
        cout << "-";
    }
    cout << endl;
    for (int j = 0; j < vex_num; ++j) {
        if (j == 0) {
            cout << "|" << setw(13);
            continue;
        }
        cout << "| v" << setw(6) << left << j;
    }
    cout << "|";
    cout << endl;
    for (int i = 1; i <= vex_num; ++i) {
        for (int j = 0; j < vex_num * 13; ++j) {
            cout << "-";
        }
        cout << endl;
        cout << "| v" << setw(7) << left << i;
        for (int j = 1; j <= vex_num; ++j) {
            cout << "| " << setw(7) << right << cost[i][j];
        }
        cout<<"|";
        cout << endl;
    }
    for (int i = 0; i < vex_num * 13; ++i) {
        cout << "-";
    }
}

TEST(prim, test){

}

void testPrim() {
    cout << "testPrim" << endl;
}


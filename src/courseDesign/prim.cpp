//
// Created by NineDollar on 2022/4/19.
// Copyright (c) 2020年 NineDollar. All rights reserved.
// Prim普里姆算法求最小生成树

#include <iomanip>
#include <fstream>
#include "prim.h"
#include "../../googletest/include/gtest/gtest.h"
#include <cstdlib>
#include <iostream>

using namespace std;

using namespace std;

/**
 * 创建邻接矩阵,并每个顶点赋值为无穷大,然后输入每个顶点的权值
 * @param cost
 * @return
 */
int create_cost(int **cost, int file_data[2][2][2]) {
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

/**
 * 打印邻接矩阵
 * @param cost
 * @param vex_num
 */
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
        cout << "|";
        cout << endl;
    }
    for (int i = 0; i < vex_num * 13; ++i) {
        cout << "-";
    }
}

void Prim(int (*cost)[2][2]) {
    cout << cost[0][0];
}

TEST(Prim, create_cost) {
    fstream io_file;
    char buffer[1024];
    string file_path = string(__FILE__);
    string file_dir = file_path.substr(0, file_path.find_last_of('/'));
    io_file.open(file_dir + "/prim.txt");
    if (!io_file.is_open()) {
        FAIL() << "打开文件失败";
    }
    while (io_file.getline(buffer, 1024)) {
        int i = strtol(buffer, nullptr, 10);
        cout << i << endl;
    }

    io_file.close();

//    int p[][2] = {{1, 2},
//                  {3, 4}};
//    Prim(p);
}

void testPrim() {
    cout << "testPrim" << endl;
}


//
// Created by NineDollar on 2022/4/19.
//

#ifndef DATASTRUCTURECOURSE_PRIM_H
#define DATASTRUCTURECOURSE_PRIM_H
#include <fstream>
using namespace std;

int **create_cost_file(fstream &file, int &edge);

int get_file(fstream &file);

void prim(int **cost, int vex_num);

void print_cost(int **cost, int vex_num);
void create_cost(int **cost, int vex_num, int arc_num);

#endif //DATASTRUCTURECOURSE_PRIM_H

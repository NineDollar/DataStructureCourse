//
// Created by NineDollar on 2022/5/24.
//

#ifndef DATASTRUCTURECOURSE_INCLUDE_COURSEDESIGN_KRUSKAL_KRUSKAL_H_
#define DATASTRUCTURECOURSE_INCLUDE_COURSEDESIGN_KRUSKAL_KRUSKAL_H_
#include <fstream>
using namespace std;

struct EDGES;

EDGES * creat_edgeset_file(fstream &file, int &arc_num, int &vex_num);
int get_file(fstream &file);
void print_edges(EDGES *edgeset, int arc_num);
void kruskal(EDGES *edgeset, int arc_num, int vex_num);
int seeks(const int set[], int v);
void sort(EDGES *edgeset, int arc_num);
void creat_edgeset(EDGES *edgeset, int arc_num);

#endif //DATASTRUCTURECOURSE_INCLUDE_COURSEDESIGN_KRUSKAL_KRUSKAL_H_

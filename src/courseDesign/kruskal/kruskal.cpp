//
// Created by Nine_Dollar on 2021/5/1.
//
/**
 * p: Kruskal克鲁斯卡尔求最小生成树,稠密图
 */
#include <fstream>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/lexical_cast.hpp>
#include "kruskal.h"
#include "boost/format.hpp"

using namespace std;
using namespace boost;
using boost::format;

typedef struct EDGES {
  int bv, ev, w;
} EDGES;

void creat_edgeset(EDGES *edgeset, int arc_num) {
  int i;
  for (i = 1; i <= arc_num; i++) {
    cout << "bv,ev,w=";
    cin >> edgeset[i].bv >> edgeset[i].ev >> edgeset[i].w;
  }
}

void sort(EDGES *edgeset, int arc_num) {
  int i, j;
  EDGES t;
  for (i = 1; i <= arc_num - 1; i++) {
    for (j = i + 1; j <= arc_num; j++) {
      if (edgeset[i].w > edgeset[j].w) {
        t = edgeset[i];
        edgeset[i] = edgeset[j];
        edgeset[j] = t;
      }
    }
  }
}

int seeks(const int set[], int v) {
  int i = v;
  while (set[i] > 0) {
    i = set[i];
  }
  return i;
}

int out(string str) {
  fstream file;
  string file_path = string(__FILE__);
  string file_dir = file_path.substr(0, file_path.find_last_of('\\'));
  file.open(file_dir + "/out.txt", ios::out | ios::app);
  if (!file.is_open()) {
    return 1;
  }
  file << str;
  file.close();
  return 0;
}

void kruskal(EDGES *edgeset, int arc_num, int vex_num) {
  int set[vex_num + 1], v1, v2;
  int i;
  cout << "kruskal算法构造的最小生成树" << endl;
  cout << "起点-->终点   权值" << endl;
  for (i = 1; i <= vex_num; i++) {
    set[i] = 0;
  }
  i = 1;
  while (i <= arc_num) {
    v1 = seeks(set, edgeset[i].bv);
    v2 = seeks(set, edgeset[i].ev);
    if (v1 != v2) {
      format text = format(" %1%---->%2%     %3%\n") % edgeset[i].bv % edgeset[i].ev % edgeset[i].w;
      string str = text.str();
      cout << str;
      out(str);
      set[v1] = v2;
    }
    i++;
  }
}

/**
 * 打印邻接矩阵
 * @param cost
 * @param vex_num
 */
void print_edges(EDGES *edgeset, int arc_num) {
  cout << "起点-->终点   权值" << endl;
  for (int i = 1; i <= arc_num; ++i) {
    format text = format(" %1%---->%2%     %3%\n") % edgeset[i].bv % edgeset[i].ev % edgeset[i].w;
    cout << text.str();
  }
}

int get_file(fstream &file) {
  string file_path = string(__FILE__);
  string file_dir = file_path.substr(0, file_path.find_last_of('\\'));
  file.open(file_dir + "/kruskal.txt");
  if (!file.is_open()) {
    cout << "打开文件失败";
    return 1;
  }
  return 0;
}

EDGES *creat_edgeset_file(fstream &file, int &arc_num, int &vex_num) {
  EDGES *edgeset = nullptr;
  char buffer[1024];
  if (!file.is_open()) {
    return nullptr;
  }
  while (file.getline(buffer, 1024)) {
    int line_var[10] = {0}, *p;
    string line = string(buffer);
    tokenizer<> tok(line);
    p = line_var;
    for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it) {
      *p++ = lexical_cast<int>(string(*it));
    }
    if (edgeset == nullptr) {
      vex_num = line_var[0];
      edgeset = new EDGES[line_var[1] + 1];
    } else {
      edgeset[arc_num].bv = line_var[0];
      edgeset[arc_num].ev = line_var[1];
      edgeset[arc_num].w = line_var[2];
      arc_num++;
    }
  }
  --arc_num;
  file.close();
  return edgeset;
}

int main() {
  int vex_num, arc_num = 1;
  EDGES *edgeset;
  fstream file;
  get_file(file);
  edgeset = creat_edgeset_file(file, arc_num, vex_num);
  print_edges(edgeset, arc_num);
  sort(edgeset, arc_num);
  kruskal(edgeset, arc_num, vex_num);
  return 0;
}


/* int vex_num, arc_num;
   cout << "Kruskal克鲁斯卡尔求最小生成树" << endl;
   EDGES *edgeset;

   cout << "请输入无向图的顶点数:";
   cin >> vex_num;
   cout << "输入无向网的边数:";
   cin >> arc_num;
   edgeset = new EDGES[arc_num + 1];

   creat_edgeset(edgeset, arc_num);
   sort(edgeset, arc_num);
   kruskal(edgeset, arc_num, vex_num);*/


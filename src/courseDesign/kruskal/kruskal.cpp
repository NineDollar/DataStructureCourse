//
// Created by Nine_Dollar on 2021/5/1.
//
/**
 * p: Kruskal克鲁斯卡尔求最小生成树,稠密图
 */
#include <fstream>
#include <iostream>
#include "boost/tokenizer.hpp"
#include "boost/typeof/typeof.hpp"
#include "boost/lexical_cast.hpp"

using namespace std;
using namespace boost;

typedef struct edges {
  int bv, ev, w;
} EDGES;

void creat_edgeset(EDGES *edgeset, int arc_num) {
  int i;
  for (i = 1; i <= arc_num; i++) {
    cout << "bv,ev,w=";  //分别对应起点,终点,权值
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
      cout << " " << edgeset[i].bv << "---->" << edgeset[i].ev << "     " << edgeset[i].w << endl;
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
void print_edges(EDGES *edges, int arc_num) {
  cout << "起点-->终点   权值" << endl;
  for (int i = 1; i <= arc_num; ++i) {
    cout << " " << edges[i].bv << "---->" << edges[i].ev << "     " << edges[i].w << endl;
  }
}

void file_test() {
  int line_var[10] = {0}, *p;
  int arc_num = 1;
  int e;
  int vex_num;
  EDGES *edgeset = nullptr;
  fstream io_file;
  char buffer[1024];
  string file_path = string(__FILE__);
  string file_dir = file_path.substr(0, file_path.find_last_of('\\'));
  io_file.open(file_dir + "/kruskal.txt");
  if (!io_file.is_open()) {
    cout << "打开文件失败";
    return;
  }
  while (io_file.getline(buffer, 1024)) {
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
  print_edges(edgeset, arc_num);
  sort(edgeset, arc_num);
  kruskal(edgeset, arc_num, vex_num);
}

int main() {
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

  file_test();
  return 0;
}


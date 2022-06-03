//
// Created by NineDollar on 2022/4/19.
// Copyright (c) 2020�� NineDollar. All rights reserved.
// Prim����ķ�㷨����С��������������

#include <iomanip>
#include <fstream>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include "prim.h"

using namespace std;
using namespace boost;
using boost::format;

/**
 * �����ڽӾ���,��ÿ�����㸳ֵΪ�����,Ȼ������ÿ�������Ȩֵ
 * @param cost ��ά����
 * @return int
 */
void create_cost(int **cost, int vex_num, int arc_num) {
  int v1, v2, w;
  for (int i = 0; i <= vex_num; ++i) {
    for (int j = 0; j <= vex_num; ++j) {
      cost[i][j] = 32767;
    }
  }
  for (int k = 1; k <= arc_num; ++k) {
    cout << "v1 v2 w= ";
    cin >> v1 >> v2 >> w;
    cost[v1][v2] = w;
    cost[v2][v1] = w;
  }
}
/**
 * ��ӡ�ڽӾ���
 * @param cost
 * @param vex_num
 */
void print_cost(int **cost, int vex_num) {
  if (cost == nullptr) {
    return;
  }
  int space = 10, frame = 12;
  for (int i = 0; i < vex_num * frame - 1; ++i) {
    cout << "-";
  }
  cout << endl;
  for (int j = 0; j <= vex_num; ++j) {
    if (j == 0) {
      cout << "|" << setw(space);
      continue;
    }
    cout << "|" << right << setw(space - 3) << "v" << j << " ";
  }
  cout << "|";
  cout << endl;
  for (int i = 1; i <= vex_num; ++i) {
    for (int j = 0; j < vex_num * frame - 1; ++j) {
      cout << "-";
    }
    cout << endl;
    cout << "| v" << setw(space - 3) << left << i;
    for (int j = 1; j <= vex_num; ++j) {
      cout << "|" << setw(space - 3) << right << cost[i][j] << "  ";
    }
    cout << "|";
    cout << endl;
  }
  for (int i = 0; i < vex_num * frame - 1; ++i) {
    cout << "-";
  }
  cout << endl;
}

int out(string text) {
  fstream file;
  string file_path = string(__FILE__);
  string file_dir = file_path.substr(0, file_path.find_last_of('\\'));
  file.open(file_dir + "/out.txt", ios::out | ios::app);
  if (!file.is_open()) {
    return 1;
  }
  file << text;
  file.close();
  return 0;
}

/**
 * ����ķ����С������
 * @param cost
 * @param vex_num
 */
void prim(int **cost, int vex_num) {
  int low_cost[vex_num + 1], close_ver[vex_num + 1];
  if (cost == nullptr) {
    return;
  }
  for (int i = 1; i <= vex_num; ++i) {
    low_cost[i] = cost[1][i];
    close_ver[i] = 1;
  }
  close_ver[1] = -1;
  for (int i = 2; i <= vex_num; ++i) {
    int k, min;
    min = 32767;
    k = 0;
    for (int j = 1; j <= vex_num; ++j) {
      if (close_ver[j] != -1 && low_cost[j] < min) {
        min = low_cost[j];
        k = j;
      }
    }
    if (k) {
      format text = format("(%1%,%2%) %3%\n") % close_ver[k] % k % low_cost[k];
      string str = text.str();
      cout << str;
      out(str);
      close_ver[k] = -1;
      for (int j = 2; j <= vex_num; ++j) {
        if (close_ver[j] != -1 && cost[k][j] < low_cost[j]) {
          low_cost[j] = cost[k][j];
          close_ver[j] = k;
        }
      }
    }
  }
}

int get_file(fstream &file) {
  string file_path = string(__FILE__);
  string file_dir = file_path.substr(0, file_path.find_last_of('\\'));
  file.open(file_dir + "/prim.txt", ios::in);
  if (!file.is_open()) {
    cout << "���ļ�ʧ��";
    return 1;
  }
  return 0;
}

int **create_cost_file(fstream &file, int &edge) {
  int **cost = nullptr;
  char buffer[1024];
  while (file.getline(buffer, 1024)) {
    int line_var[10], *p;
    string line = string(buffer);
    tokenizer<> tok(line);
    p = line_var;
    for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it) {
      *p++ = lexical_cast<int>(string(*it));
    }
    if (cost == nullptr) {
      cost = new int *[line_var[0] + 1];
      for (int i = 0; i < line_var[0] + 1; ++i) {
        cost[i] = new int[line_var[0] + 1];
      }
      for (int i = 0; i < line_var[0] + 1; ++i) {
        for (int j = 0; j < line_var[0] + 1; ++j) {
          cost[i][j] = 32767;
        }
      }
      edge = line_var[0];
    } else {
      cost[line_var[0]][line_var[1]] = line_var[2];
      cost[line_var[1]][line_var[0]] = line_var[2];
    }
  }
  file.close();
  return cost;
}

int main() {
  int **cost, vex_num;
  fstream file;
  get_file(file);
  cost = create_cost_file(file, vex_num);
  print_cost(cost, vex_num);
  prim(cost, vex_num);
  free(cost);
  return 0;
}

/*int vex_num, arc_num;
  int **cost = nullptr;
  cout << "�����붥�����ͱ���: ";
  cin >> vex_num >> arc_num;
  cout << "prim�㷨����С������" << endl;
  cost = new int *[vex_num+1];
  for (int i = 0; i < vex_num+1; ++i) {
    cost[i] = new int[vex_num+1];
  }
  create_cost(cost, vex_num, arc_num);
  print_cost(cost, vex_num);
  prim(cost, vex_num);*/
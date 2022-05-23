/*
 * Copyright (c) 2015 NineDollar. All rights reserved.
 */
#include <iostream>
#include <random>
using namespace std;

#define play_times 10
#define colors_max 2000
#define color_size 4
typedef int ElemType;
typedef ElemType color_array[color_size];

typedef struct colors {
  color_array color;
  int length;
} colors;

void init(colors U[]);
void play(colors *U);
int get_new_U(colors *U, int rand_index, int &u_nc, int &u_np);
int get_np(color_array &temp_U, color_array &temp_R);
int get_nc(color_array &temp_U, color_array &temp_R);
int get_rand(int size);

int main() {
  colors U[colors_max];
  init(U);
  play(U);

  return 0;
}

/**
 * 生成所有颜色数组集U
 * @param U 数组集
 */
void init(colors *U) {
  int length = 0;
  for (int i = 1; i <= 6; ++i) {
    for (int j = 1; j <= 6; ++j) {
      for (int k = 1; k <= 6; ++k) {
        for (int l = 1; l <= 6; ++l) {
          color_array color = {i, j, k, l};
          memcpy(
              U[length++].color, color, sizeof(color));
        }
      }
    }
  }
  U->length = length;
}

int get_rand(int size) {
  srand((unsigned) time(nullptr));
  return rand() % size;
}

void show(colors *co) {
  int count = 0;
  for (int i = 0; i < co->length; ++i) {
    cout << ++count << "  ";
    for (int j = 0; j < color_size; ++j) {
      cout << co[i].color[j] << "  ";
    }
    cout << endl;
  }
  cout << "-------------------" << endl;
}

void play(colors *U) {
  int u_nc;
  int u_np;
  int rand_index = 0;

  for (int i = 0; i < play_times; ++i) {
    rand_index = get_rand(U->length);
    for (int vaule : U[rand_index].color) {
      cout << vaule << "  ";
    }
    cout << endl;
    cout << "请输入颜色对位置错的个数：";
    cin >> u_nc;
    if (u_nc < 0 || u_nc > 4) {
      cout << "输入错误";
      return;
    }
    cout << "请输入颜色和位置都对的个数：";
    cin >> u_np;
    if (u_np < 0 || u_np > 4) {
      cout << "输入错误";
      return;
    }
    int state = get_new_U(U, rand_index, u_nc, u_np);
    show(U);
    if (state == color_size) {
      cout << "猜对了" << endl;
      return;
    } else if (U->length == 0) {
      cout << "没猜到";
      return;
    }
  }
  cout << "太难了，没猜到";
}

/**
 * 获取匹配后的颜色数组集合
 * @param U 颜色数组集合
 * @param rand_index 随机获取一个
 * @param u_nc 颜色种位置不对的个数
 * @param u_np 颜色中位置对的个数
 */
int get_new_U(colors *U, int rand_index, int &u_nc, int &u_np) {
  int statu = 0;
  color_array temp_U;
  color_array temp_R;
  colors new_U[colors_max];
  int new_U_length = 0;
  for (int i = 0; i < U->length; ++i) {
    int np = 0;
    int nc = 0;
    memcpy(temp_U, U[i].color, sizeof(U[i].color));
    memcpy(temp_R, U[rand_index].color, sizeof(U[rand_index].color));
    np = get_np(temp_U, temp_R);
    statu = np;
    nc = get_nc(temp_U, temp_R);
    if (statu == color_size && statu == u_np) {
      return statu;
    }
    if (np == u_np && nc == u_nc) {
      memcpy(new_U[new_U_length++].color, U[i].color, sizeof(U[i].color));
    }
  }
  new_U->length = new_U_length;
  memcpy(U, new_U, sizeof(new_U));
  return statu;
}

/**
 * 获取颜色中位置对的个数
 * @param U 颜色数组集合
 * @param temp_R 随机颜色数组
 * @param nc 颜色种位置不对的个数
 */
int get_np(color_array &temp_U, color_array &temp_R) {
  int np = 0;
  for (int i = 0; i < color_size; ++i) {
    if (temp_U[i] == temp_R[i]) {
      temp_U[i] = temp_R[i] = 0;
      np++;
    }
  }
  return np;
}
/**
 * 颜色对位置错
 * @param temp_U 颜色数组集合
 * @param temp_R 随机颜色数组
 * @return 颜色种位置不对的个数
 */
int get_nc(color_array &temp_U, color_array &temp_R) {
  int nc = 0;
  for (int i = 0; i < color_size; ++i) {
    for (int j = 0; j < color_size; ++j) {
      if (temp_R[i] == temp_U[j] && temp_R[i] != 0) {
        temp_U[j] = 0;
        nc++;
        break;
      }
    }
  }
  return nc;
}


/*
 * Copyright (c) 2015 NineDollar. All rights reserved.
 */
#include <iostream>
#include <random>
using namespace std;

#define PLAY_TIMES 10
#define COLORS_MAX 2000
#define COLOR_MAX 4
typedef int ElemType;
typedef ElemType color_array[COLOR_MAX];

typedef struct colors {
  color_array color[COLORS_MAX];
  int length;
} SqList;

void init(SqList U[]);
void play(SqList *U);
int get_new_U(SqList *U, int rand_index, int &u_nc, int &u_np);
int GetNp(color_array &temp_U, color_array &temp_R);
int GetNc(color_array &temp_U, color_array &temp_R);
int get_rand(int size);

int main() {
  SqList U[COLORS_MAX];
  init(U);
  play(U);

  return 0;
}



/**
 * ����������ɫ���鼯U
 * @param U ���鼯
 */
void init(SqList *U) {
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

void show(SqList *co) {
  int count = 0;
  for (int i = 0; i < co->length; ++i) {
    cout << ++count << "  ";
    for (int j = 0; j < COLOR_MAX; ++j) {
      cout << co[i].color[j] << "  ";
    }
    cout << endl;
  }
  cout << "-------------------" << endl;
}

void play(SqList *U) {
  int u_nc;
  int u_np;
  int rand_index = 0;

  for (int i = 0; i < PLAY_TIMES; ++i) {
    rand_index = get_rand(U->length);
    for (int vaule : U[rand_index].color) {
      cout << vaule << "  ";
    }
    cout << endl;
    cout << "��������ɫ��λ�ô�ĸ�����";
    cin >> u_nc;
    if (u_nc < 0 || u_nc > 4) {
      cout << "�������";
      return;
    }
    cout << "��������ɫ��λ�ö��Եĸ�����";
    cin >> u_np;
    if (u_np < 0 || u_np > 4) {
      cout << "�������";
      return;
    }
    int state = get_new_U(U, rand_index, u_nc, u_np);
    show(U);
    if (state == COLOR_MAX) {
      cout << "�¶���" << endl;
      return;
    } else if (U->length == 0) {
      cout << "û�µ�";
      return;
    }
  }
  cout << "̫���ˣ�û�µ�";
}

/**
 * ��ȡƥ������ɫ���鼯��
 * @param U ��ɫ���鼯��
 * @param rand_index �����ȡһ��
 * @param u_nc ��ɫ��λ�ò��Եĸ���
 * @param u_np ��ɫ��λ�öԵĸ���
 */
int get_new_U(SqList *U, int rand_index, int &u_nc, int &u_np) {
  int statu = 0;
  color_array temp_U;
  color_array temp_R;
  SqList new_U[COLORS_MAX];
  int new_U_length = 0;
  for (int i = 0; i < U->length; ++i) {
    int np = 0;
    int nc = 0;
    memcpy(temp_U, U[i].color, sizeof(U[i].color));
    memcpy(temp_R, U[rand_index].color, sizeof(U[rand_index].color));
    np = GetNp(temp_U, temp_R);
    statu = np;
    nc = GetNc(temp_U, temp_R);
    if (statu == COLOR_MAX && statu == u_np) {
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
 * ��ȡ��ɫ��λ�öԵĸ���
 * @param U ��ɫ���鼯��
 * @param temp_R �����ɫ����
 * @param nc ��ɫ��λ�ò��Եĸ���
 */
int GetNp(color_array &temp_U, color_array &temp_R) {
  int np = 0;
  for (int i = 0; i < COLOR_MAX; ++i) {
    if (temp_U[i] == temp_R[i]) {
      temp_U[i] = temp_R[i] = 0;
      np++;
    }
  }
  return np;
}
/**
 * ��ɫ��λ�ô�
 * @param temp_U ��ɫ���鼯��
 * @param temp_R �����ɫ����
 * @return ��ɫ��λ�ò��Եĸ���
 */
int GetNc(color_array &temp_U, color_array &temp_R) {
  int nc = 0;
  for (int i = 0; i < COLOR_MAX; ++i) {
    for (int j = 0; j < COLOR_MAX; ++j) {
      if (temp_R[i] == temp_U[j] && temp_R[i] != 0) {
        temp_U[j] = 0;
        nc++;
        break;
      }
    }
  }
  return nc;
}


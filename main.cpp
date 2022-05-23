//
// Created by NineDollar on 2022/5/23.
//
#include <iostream>
#include <random>
using namespace std;

#define COLOR_MAX 4
#define PLAY_TIMES 10
#define COLORS_MAX 2000
typedef int ElemType[4];

typedef struct SqList {
  ElemType data[COLORS_MAX];
  int length;
} SqList;

void InitList(SqList &L);
int InitColors(SqList &L);
void Play(SqList &L);

int main() {
  SqList L;
  InitList(L);
  InitColors(L);
  Play(L);
  return 0;
}

/**
 * 插入元素
 */
int InsElem(SqList &L, ElemType x, int i) {
  int j;
  if (i < 1 || i > L.length + 1) {
    return 0;
  }
  for (j = L.length; j > i; j--) {
    for (int k = 0; k < COLOR_MAX; ++k) {
      L.data[j][k] = L.data[j - 1][k];
    }
  }
  for (int k = 0; k < COLOR_MAX; ++k) {
    L.data[i - 1][k] = x[k];
  }
  L.length++;
  return 1;
}

/**
 * 生成所有颜色集合
 */
int InitColors(SqList &L) {
  int length = 1;
  for (int i = 1; i <= 6; ++i) {
    for (int j = 1; j <= 6; ++j) {
      for (int k = 1; k <= 6; ++k) {
        for (int l = 1; l <= 6; ++l) {
          ElemType x = {i, j, k, l};
          InsElem(L, x, length++);
        }
      }
    }
  }
  return 1;
}

/**
 * 初始化线性表
 */
void InitList(SqList &L) {
  L.length = 0;
}

/**
 * 求线性表长度运算算法
 */
int GetLength(SqList L) {
  return L.length;
}

/**
 * 求线性表中第i个元素
 */
int GetElem(SqList L, int i, ElemType &e) {
  if (i < 1 || i > L.length) {
    return 0;
  } else {
    for (int j = 0; j < COLOR_MAX; ++j) {
      e[j] = L.data[i - 1][j];
    }
    return 1;
  }
}

/**
 * 按值查找
 */
int Locate(SqList L, ElemType x) {
  int i = 0;
  while (i < L.length && L.data[i] != x) {
    i++;
  }
  if (i >= L.length) {
    return 0;
  } else {
    return i + 1;
  }
}

int DelElem(SqList &L, int i) {
  if (i < 1 || i > L.length) {
    return 0;
  }
  for (int j = 0; j < L.length; ++j) {
    for (int k = 0; k < COLOR_MAX; ++k) {
      L.data[j - 1][k] = L.data[j][k];
    }
  }
  L.length--;
  return 1;
}

void DispList(SqList L) {
  for (int i = 0; i < GetLength(L); ++i) {
    for (int j = 0; j < COLOR_MAX; ++j) {
      cout << L.data[i][j] << "  ";
    }
    cout << endl;
  }
}

int GetRand(int size) {
  srand((unsigned) time(nullptr));
  return rand() % size;
}

/**
 * 获取颜色中位置对的个数
 * @param U 颜色数组集合
 * @param temp_R 随机颜色数组
 * @param nc 颜色种位置不对的个数
 */
int GetNp(ElemType &temp_U, ElemType &temp_R) {
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
 * 颜色对位置错
 * @param temp_U 颜色数组集合
 * @param temp_R 随机颜色数组
 * @return 颜色种位置不对的个数
 */
int GetNc(ElemType &temp_U, ElemType &temp_R) {
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

/**
 * 获取匹配后的颜色数组集合
 * @param L 颜色数组集合
 * @param rand_index 随机获取一个
 * @param nc 颜色种位置不对的个数
 * @param np 颜色中位置对的个数
 */
int GetAfterL(SqList &L, int rand_index, int &nc, int &np) {
  int statu = 0;
  ElemType tempL;
  ElemType tempAfter;
  SqList afterL;
  InitList(afterL);
  int afterLength = 0;
  for (int i = 0; i < L.length; ++i) {
    int p;
    int c;
    GetElem(L, i, tempL);
    GetElem(L, rand_index, tempAfter);
    p = GetNp(tempL, tempAfter);
    statu = p;
    c = GetNc(tempL, tempAfter);
    if (statu == COLOR_MAX && statu == np) {
      return statu;
    }
    if (p == np && c == nc) {
      InsElem(afterL, L.data[i], afterLength++);
    }
  }
  L = afterL;
  return statu;
}

void Play(SqList &L) {
  int nc;
  int np;
  for (int i = 0; i < PLAY_TIMES; ++i) {
    int ri = GetRand(L.length);
    for (int value : L.data[ri]) {
      cout << value << "  ";
    }
    cout << endl;
    cout << "请输入颜色对位置错的个数：";
    cin >> nc;
    if (nc < 0 || nc > 4) {
      cout << "输入错误";
      return;
    }
    cout << "请输入颜色和位置都对的个数：";
    cin >> np;
    if (np < 0 || np > 4) {
      cout << "输入错误";
      return;
    }
    int state = GetAfterL(L, ri, nc, np);
    DispList(L);
    cout << "--------------" << endl;
    if (state == COLOR_MAX) {
      cout << "猜对了" << endl;
      return;
    } else if (L.length == 0) {
      cout << "没猜到";
      return;
    }
  }
  cout << "太难了，没猜到";
}

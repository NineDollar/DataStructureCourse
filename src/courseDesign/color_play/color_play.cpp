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
 * ����Ԫ��
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
 * ����������ɫ����
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
 * ��ʼ�����Ա�
 */
void InitList(SqList &L) {
  L.length = 0;
}

/**
 * �����Ա��������㷨
 */
int GetLength(SqList L) {
  return L.length;
}

/**
 * �����Ա��е�i��Ԫ��
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
 * ��ֵ����
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

int GetRand(int length) {
  srand((unsigned) time(nullptr));
  return rand() % length;
}

/**
 * ��ȡ��ɫ��λ�öԵĸ���
 * @param U ��ɫ���鼯��
 * @param tempAfter �����ɫ����
 * @param nc ��ɫ��λ�ò��Եĸ���
 */
int GetNp(ElemType &tempL, ElemType &tempAfter) {
  int np = 0;
  for (int i = 0; i < COLOR_MAX; ++i) {
    if (tempL[i] == tempAfter[i]) {
      tempL[i] = tempAfter[i] = 0;
      np++;
    }
  }
  return np;
}
/**
 * ��ɫ��λ�ô�
 * @param tempL ��ɫ���鼯��
 * @param tempAfter �����ɫ����
 * @return ��ɫ��λ�ò��Եĸ���
 */
int GetNc(ElemType &tempL, ElemType &tempAfter) {
  int nc = 0;
  for (int i = 0; i < COLOR_MAX; ++i) {
    for (int j = 0; j < COLOR_MAX; ++j) {
      if (tempAfter[i] == tempL[j] && tempAfter[i] != 0) {
        tempL[j] = 0;
        nc++;
        break;
      }
    }
  }
  return nc;
}

/**
 * ��ȡƥ������ɫ���鼯��
 * @param L ��ɫ���鼯��
 * @param r �����ȡһ��
 * @param nc ��ɫ��λ�ò��Եĸ���
 * @param np ��ɫ��λ�öԵĸ���
 */
int GetAfterL(SqList &L, int r, int &nc, int &np) {
  int statu = 0;
  ElemType tempL;
  ElemType tempAfter;
  SqList afterL;
  InitList(afterL);
  int afterLength = 1;
  for (int i = 0; i < L.length; ++i) {
    int p;
    int c;
    GetElem(L, i+1, tempL);
    GetElem(L, r+1, tempAfter);
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
  return 0;
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
    cout << "��������ɫ��λ�ô�ĸ�����";
    cin >> nc;
    if (nc < 0 || nc > 4) {
      cout << "�������";
      return;
    }
    cout << "��������ɫ��λ�ö��Եĸ�����";
    cin >> np;
    if (np < 0 || np > 4) {
      cout << "�������";
      return;
    }
    int state = GetAfterL(L, ri, nc, np);
    // DispList(L);
    // cout << "--------------" << endl;
    if (state == COLOR_MAX) {
      cout << "�¶���" << endl;
      return;
    } else if (L.length == 0) {
      cout << "û�µ�";
      return;
    }
  }
  cout << "̫���ˣ�û�µ�";
}

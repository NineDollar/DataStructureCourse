//
// Created by NineDollar on 2022/6/3.
//
#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 3    //停车场最多可停留汽车辆数
const float price = 0.05;    //每分钟停车费用
int i;    //汽车在便道中的位置

/*********************************/

//时间
typedef struct time {
  int h, m;    //小时 分钟
} Time;

//汽车
typedef struct car {
  Time t1, t2;    //到达时间和离开时间
  string num;    //车牌号
  int p1, p2;    //汽车在停车场或者便道停留位置
} Car;

//停车场
typedef struct {
  Car data[MAXSIZE];
  int top;
} SeqList;

//便道
typedef struct qnode {
  Car data;
  struct qnode *next;
} QNode;

typedef struct lqueue {
  QNode *front, *rear;
} LQueue;

/*********************************/

//初始化停车场
SeqList *Init_SeqList() {
  SeqList *s;
  s = new SeqList;
  s->top = -1;
  return s;
}

//初始化便道
LQueue *Init_LQueue() {
  LQueue *q;
  QNode *p;
  q = new lqueue;
  p = new qnode;
  p->next = NULL;
  q->front = p;
  q->rear = p;
  return q;
}


/*********************************/


//汽车进入停车场
void Push_SeqList(SeqList *s, Car x) {
  s->top++;
  s->data[s->top] = x;
}

//汽车离开停车场
Car Pop_SeqList(SeqList *s) {
  Car x = s->data[s->top];
  s->top--;
  return x;
}

//停车场满的时候进入便道
void In_LQueue(LQueue *q, Car x) {
  QNode *p;
  p = new qnode;
  p->data = x;
  p->next = NULL;
  q->rear->next = p;
  q->rear = p;
}

//停车场有车离开有空位时便道上的车辆按照到达顺序依次进入停车场
Car Out_LQueue(LQueue *q) {
  Car x;
  QNode *p;
  p = q->front->next;
  q->front->next = p->next;
  x = p->data;
  delete p;
  if (q->front->next == NULL)    //只有一个元素时，出队后队空，此时还要修改队尾指针
  {
    q->front->next = NULL;
    q->rear = q->front;
  }
  return x;
}


/***********************************************/

//汽车到达
void Car_In(SeqList *p, LQueue *q) {
  Car c;
  cout << "请依次输入汽车车牌号和到达时间（小时，分钟）：";
  cin >> c.num >> c.t1.h >> c.t1.m;
  if (p->top == MAXSIZE - 1) {
    //进入便道
    c.p2 = ++i;
    cout << "生意火爆，停车场已满，进入便道等待，位置为：00" << c.p2 << endl;
    In_LQueue(q, c);
  } else {
    //进入停车场
    c.p1 = p->top + 2;
    cout << "进入停车场，位置为：00" << c.p1 << endl;
    Push_SeqList(p, c);
  }
}

//检验停车场内是否有该车辆
Car *Car_if(SeqList *p, Car c) {
  int t;    //保留下标
  SeqList *temp = Init_SeqList();
  Car x;
  while (c.num != p->data[p->top].num && p->top != -1) {
    x = Pop_SeqList(p);
    Push_SeqList(temp, x);
  }
  t = p->top;
  //恢复停车场
  while (temp->top != -1) {
    x = Pop_SeqList(temp);
    Push_SeqList(p, x);
  }
  if (t == -1) return NULL;
  else return &x;
}


/************************************************/

//汽车离去
void Car_Out(SeqList *p, LQueue *q) {
  Car c, x, first;
  int flag = 0;
  if (p->top == -1) {
    //停车场无车
    cout << "当前停车场无车！" << endl;
    return;
  }
  if (p->top == MAXSIZE - 1) {
    //当停车库满了的时候判断便道是否有车
    if (q->front == q->rear) return;
    else {
      first = Out_LQueue(q);    //便道内第一辆车
      flag = 1;
    }
  }
  SeqList *temp = Init_SeqList();    //临时栈，保留有车离开让车时从停车场退出的车辆
  cout << "请依次输入汽车车牌号和离去时间（小时，分钟）：";
  cin >> c.num >> c.t2.h >> c.t2.m;
  //判断停车场内是否有该车辆
  if (!Car_if(p, c)) {
    cout << "该停车场内没有该车辆！" << endl;
    return;
  }
  while (c.num != p->data[p->top].num) {
    x = Pop_SeqList(p);
    cout << "车牌号为" << x.num << "的车让路" << endl;
    Push_SeqList(temp, x);
  }
  x = Pop_SeqList(p);    //目标车辆
  x.t2.h = c.t2.h, x.t2.m = c.t2.m;
  float t = (x.t2.h - x.t1.h) * 60 + x.t2.m - x.t1.m; //总停留分钟
  float t1, t2;
  if (x.t2.m >= x.t1.m) {
    t2 = x.t2.m - x.t1.m;
    t1 = x.t2.h - x.t1.h;
  } else {
    t2 = x.t2.m + 60 - x.t1.m;
    t1 = x.t2.h - x.t1.h - 1;
  }
  cout << "车牌号为" << x.num << "的车开出" << endl;
  //刚才让出的车辆按照原来的顺序依次开入停车场
  while (temp->top != -1) {
    x = Pop_SeqList(temp);
    x.p1 = p->top + 2;
    cout << "车牌号为" << x.num << "的车开入" << endl;
    Push_SeqList(p, x);
  }
  //若便道有车则让便道上第一辆车进入停车场
  if (flag) {
    first.p1 = p->top + 2;
    Push_SeqList(p, first);
    cout << "车牌号为" << first.num << "的车开入" << endl;
  }
  cout << "停留时间：" << t1 << "小时" << t2 << "分钟" << "    收费：" << t * price << "元\n" << "欢迎下次光临~" << endl;
}



/**************************************************/



//显示停车场内车辆信息
void Display(SeqList *p) {
  Car x;
  SeqList *temp = Init_SeqList();
  if (p->top == -1) {
    cout << "当前停车场无车，生意惨淡！" << endl;
    return;
  } else {
    while (p->top != -1) {
      x = Pop_SeqList(p);
      Push_SeqList(temp, x);
    }
    cout << "当前停放的车辆信息:" << endl;
    while (temp->top != -1) {
      x = Pop_SeqList(temp);
      cout << "停车位置为：00" << x.p1 << "  车牌号码:" << x.num << "  停车时间：" << x.t1.h << "点" << x.t1.m << "分" << endl;
      Push_SeqList(p, x);
    }
  }
}

/****************************************************/
int main() {
  int flag = 1;
  SeqList *p = Init_SeqList();
  LQueue *q = Init_LQueue();
  while (flag) {
    cout << "=========================欢迎使用停车场===========================" << endl;
    puts("");
    cout << "                   本停车场最多可停放" << MAXSIZE << "辆汽车" << endl;
    puts("");
    cout << "==================================================================" << endl;
    int i;
    cout << "**********1.汽车到达  2.汽车离去  3.查看车库  4.退出系统**********" << endl;
    scanf("%d", &i);    //使用cin >> i;出现错误
    while (getchar() != '\n');    //清除缓冲区
    switch (i) {
      case 1:Car_In(p, q);
        break;
      case 2:Car_Out(p, q);
        break;
      case 3:Display(p);
        break;
      case 4:cout << "拜拜，下次再见！" << endl;
        flag = 0;
        break;
      default:
        cout << "输入错误啦~请输入数字1--4重新选择~" << endl;
        break;
    }
  }
  system("pause");
  return 0;
}



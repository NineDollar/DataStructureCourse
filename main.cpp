//
// Created by NineDollar on 2022/5/13.
//
#include <iostream>

using namespace std;

#define ARRIVAL_TIME 15
#define BANK_PROCESSING_TIME 120
typedef int QElemType;
typedef struct QNode {
  //到达时间
  QElemType arrival_time;
  //办理时间
  QElemType processing_time;
  struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
  //头指针
  QueuePtr front;
  //尾指针
  QueuePtr rear;
} LinkQueue;

void bank(LinkQueue *q, int people_num, int windows_num, int &bank_time, int &wait_time);
void get_max_window(QNode *windows, int windows_num, int &window_index);
void get_min_window(QNode *windows, int windows_num, int &window_index);
void dequeue(LinkQueue *q, QNode &people);
void enqueue(LinkQueue *q, QElemType arrival_time, QElemType processing_time);
void destroy_queue(LinkQueue *q);
void init_queue(LinkQueue *q);

int main() {
  LinkQueue q;
  init_queue(&q);
  int arrival_time = 0;
  int bank_time = 0;
  int wait_time = 0;
  int test_times;
  cout << "请输入测试次数：" << endl;
  cin >> test_times;
  int people_num[test_times];
  int windows_num[test_times];
  cout << "请分别输入" << test_times << "次排队人数和服务窗口数（人数 窗口）：" << endl;
  for (int i = 0; i < test_times; ++i) {
    cin >> people_num[i] >> windows_num[i];
  }
  for (int i = 0; i < test_times; ++i) {
    arrival_time = 0;
    for (int j = 0; j < people_num[i]; ++j) {
      enqueue(&q, arrival_time, BANK_PROCESSING_TIME);
      arrival_time += ARRIVAL_TIME;
    }
    bank(&q, people_num[i], windows_num[i], bank_time, wait_time);
    cout << "第" << i + 1 << "次" << windows_num[i] << "个窗口办理需要: " << bank_time << "秒" << "  ";
    cout << people_num[i] << "个人平均等待: " << wait_time << "秒" << endl;
    wait_time = 0;
    bank_time = 0;
  }
  return 0;
}

void init_queue(LinkQueue *q) {
  q->front = q->rear = (QueuePtr) malloc(sizeof(QNode));
  if (!q->front) {
    return;
  }
  q->front->next = nullptr;
}

void destroy_queue(LinkQueue *q) {
  while (q->front) {
    q->rear = q->front->next;
    free(q->front);
    q->front = q->rear;
  }
}

void enqueue(LinkQueue *q, QElemType arrival_time, QElemType processing_time) {
  QueuePtr p;
  p = (QueuePtr) malloc(sizeof(QNode));
  if (!p) {
    return;
  }
  p->arrival_time = arrival_time;
  p->processing_time = processing_time;
  p->next = nullptr;
  q->rear->next = p;
  q->rear = p;
}

void dequeue(LinkQueue *q, QNode &people) {
  QueuePtr p;
  if (q->front == q->rear) {
    printf("空队\n");
    return;
  }
  p = q->front->next;
  people = *p;
  q->front->next = p->next;  //指向删除元素下一个节点
  if (q->rear == p) {
    q->rear = q->front;
  }
  free(p);
}

void get_min_window(QNode *windows, int windows_num, int &window_index) {
  int remaining_min_index = 0;
  int remaining_min_time = windows[0].processing_time;
  for (int i = 0; i < windows_num; ++i) {
    if (windows[i].processing_time < remaining_min_time) {
      remaining_min_time = windows[i].processing_time;
      remaining_min_index = i;
    }
  }
  window_index = remaining_min_index;
}

void get_max_window(QNode *windows, int windows_num, int &window_index) {
  int remaining_max_index = 0;
  int remaining_max_time = windows[0].processing_time;
  for (int i = 0; i < windows_num; ++i) {
    if (windows[i].processing_time > remaining_max_time) {
      remaining_max_time = windows[i].processing_time;
      remaining_max_index = i;
    }
  }
  window_index = remaining_max_index;
}

void bank(LinkQueue *q, int people_num, int windows_num, int &bank_time, int &wait_time) {
  QNode windows[windows_num];
  QNode people;
  int window_index;

  for (int i = 0; i < windows_num && i < people_num; ++i) {
    dequeue(q, people);
    windows[i] = people;
    for (int j = 0; j < i; ++j) {
      windows[j].processing_time -= 15;
    }
    if (i != 0) {
      bank_time += 15;
    }
  }

  while (q->front->next != nullptr) {
    dequeue(q, people);
    get_min_window(windows, windows_num, window_index);
    for (int j = 0; j < windows_num; ++j) {
      if (j != window_index) {
        windows[j].processing_time -= windows[window_index].processing_time;
      }
    }
    bank_time += windows[window_index].processing_time;
    windows[window_index] = people;
    wait_time += bank_time - people.arrival_time;
  }
  get_max_window(windows, windows_num, window_index);
  bank_time += windows[window_index].processing_time;
  wait_time /= people_num;
}


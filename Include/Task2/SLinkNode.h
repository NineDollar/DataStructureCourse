//
// Created by NineDollar on 2022/4/16.
//

#ifndef DATASTRUCTURECOURSE_SLINKNODE_H
#define DATASTRUCTURECOURSE_SLINKNODE_H

struct SLinkNode{};
// 初始化链表
void InitList(SLinkNode *&L);

// 销毁线性表
void DestroyList(SLinkNode *&L);

// 求线性表长度
int GetLength(SLinkNode *L);

// 求线性表中第i个元素
int GetElem(SLinkNode *L, int i, ElemType &e);

//按值查找
int Locate(SLinkNode *L, ElemType e);

//插入元素
int InsElem(SLinkNode *&L, ElemType x, int i);

// 删除元素
int DelElem(SLinkNode *&L, int i);

void DispList(SLinkNode *L);

void testSLinkNode();

#endif //DATASTRUCTURECOURSE_SLINKNODE_H

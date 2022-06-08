#include <stdio.h>
#define MaxSize 100
typedef int ElemType;				//设置顺序表元素为int类型
typedef struct
{	ElemType data[MaxSize];			//存放顺序表的元素
	int length;						//顺序表的实际长度
} SqList;							//顺序表类型声明
void InitList(SqList &L)			//初始化顺序表L
{
	L.length=0;
}
void DestroyList(SqList L)			//销毁顺序表L
{
}
int GetLength(SqList L)				//求长度
{
	return L.length;
}
int GetElem(SqList L,int i,ElemType &e)	//求第i个元素
{	if (i<1 || i>L.length)			//无效的i值
		return 0;
	else
	{	e=L.data[i-1];
		return 1;
	}
}
int Locate(SqList L,ElemType x)		//查找第一个x元素的位置
{	int i=0;
	while (i<L.length && L.data[i]!=x)
		i++; 						//查找第1个值为x的元素
	if (i>=L.length) return(0);		//未找到返回0
	else return(i+1);				//找到后返回其逻辑序号
}
int InsElem(SqList &L,ElemType x,int i)	//插入x作为第i个元素
{	int j;
	if (i<1 || i>L.length+1)		//无效的参数i
		return 0;
	for (j=L.length;j>i;j--)		//将位置为i的元素及之后的元素后移
		L.data[j]=L.data[j-1];
	L.data[i-1]=x;					//在位置i处放入x
	L.length++;						//顺序表长度增1
	return 1;
}
int DelElem(SqList &L,int i)		//删除第i个元素
{	int j;
	if (i<1 || i>L.length)			//无效的参数i
		return 0;
	for (j=i;j<L.length;j++)		//将位置为i的元素之后的元素前移
		L.data[j-1]=L.data[j];
	L.length--;						//顺序表长度减1
	return 1;
}
void DispList(SqList L)				//输出顺序表
{	int i;
	for (i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");
}
void CreateList(SqList &L,ElemType a[],int n)	//整体创建顺序表L
{
	int i,k=0;						//k累计顺序表L中的元素个数
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//向L中添加一个元素
		k++;						//L中元素个数增1
	}
	L.length=k;						//设置L的长度
}
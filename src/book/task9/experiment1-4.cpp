#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//存放关键字,KeyType为关键字类型
	ElemType data;			//其他数据,ElemType为其他数据的类型
} SqType;
void dispR(SqType R[],int n,int i)	//输出R
{	printf("[");
	if (i==-1) printf("]");
	for (int j=0;j<n;j++)
	{	if (j==i)
			printf("%d] ",R[j].key);
		else	
			printf("%d  ",R[j].key);
	}
	printf("\n");
}
void BubbleSort(SqType R[],int n)	//冒泡排序
{	int i,j,exchange;
	SqType tmp;
	for (i=0;i<n-1;i++)
	{	exchange=0;			//本趟排序前置exchange为0
		for (j=n-1;j>i;j--)	//比较,找出最小关键字的记录
			if (R[j].key<R[j-1].key)
			{	tmp=R[j];	//R[j]与R[j-1]进行交换,将最小关键字记录前移
				R[j]=R[j-1];
				R[j-1]=tmp;
				exchange=1;	//本趟排序发生交换置exchange为1
			}
		printf(" i=%d的结果: ",i);	dispR(R,n,i);
		if (exchange==0)	//本趟未发生交换时结束算法
			return;
	}
}
int main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++) R[i].key=A[i];
	printf("初始序列:  "); dispR(R,n,-1);
	printf("排序过程如下:\n");
	BubbleSort(R,n);
    return 0;
}

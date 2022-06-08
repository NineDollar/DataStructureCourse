#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;					//存放关键字,KeyType为关键字类型
	ElemType data;					//其他数据,ElemType为其他数据的类型
} SqType;
void dispR(SqType R[],int n,int i)	//输出R
{	for (int j=1;j<=n;j++)
	{	if (j==i-1)
			printf("%d [",R[j].key);
		else	
			printf("%d  ",R[j].key);
	}
	if (i==-1) printf("[");
	printf("]\n");
}

void Sift(SqType R[],int low,int high)		//对R[low..high]进行堆筛选
{	int i=low,j=2*i;						//R[j]是R[i]的左孩子
	SqType tmp=R[i];
	while (j<=high)
	{	if (j<high && R[j].key<R[j+1].key) 	//若右孩子较大,把j指向右孩子
			j++;
		if (tmp.key<R[j].key) 
		{	R[i]=R[j];						//将R[j]调整到双亲结点位置上
			i=j;							//修改i和j值,以便继续向下筛选
			j=2*i;
		}
		else break;							//筛选结束
	}
	R[i]=tmp;								//被筛选结点的值放入最终位置
}
void HeapSort(SqType R[],int n)		//对R[1..n]进行递增堆排序
{	int i;
	SqType tmp;
	for (i=n/2;i>=1;i--)	//循环建立初始堆
		Sift(R,i,n); 
	printf("初始堆:     "); dispR(R,n,-1);
	for (i=n;i>=2;i--)		//进行n-1次循环,完成堆排序
	{
		tmp=R[1];			//将R[1]和R[i]交换
		R[1]=R[i];
		R[i]=tmp;
		printf("i=%2d的结果: ",i); dispR(R,n,i);
		Sift(R,1,i-1);		//筛选
		printf("  筛选结果: "); dispR(R,n,i);
	}
}
int main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)		//关键字存放在R[1..n]中
		R[i+1].key=A[i];
	printf("初始序列:   ");dispR(R,n,-1);	
	printf("排序过程如下:\n");
	HeapSort(R,n);
    return 0;
}

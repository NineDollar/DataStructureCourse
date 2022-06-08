#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;			//��������,ElemTypeΪ�������ݵ�����
} SqType;
void dispR(SqType R[],int n,int i)	//���R
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
void BubbleSort(SqType R[],int n)	//ð������
{	int i,j,exchange;
	SqType tmp;
	for (i=0;i<n-1;i++)
	{	exchange=0;			//��������ǰ��exchangeΪ0
		for (j=n-1;j>i;j--)	//�Ƚ�,�ҳ���С�ؼ��ֵļ�¼
			if (R[j].key<R[j-1].key)
			{	tmp=R[j];	//R[j]��R[j-1]���н���,����С�ؼ��ּ�¼ǰ��
				R[j]=R[j-1];
				R[j-1]=tmp;
				exchange=1;	//����������������exchangeΪ1
			}
		printf(" i=%d�Ľ��: ",i);	dispR(R,n,i);
		if (exchange==0)	//����δ��������ʱ�����㷨
			return;
	}
}
int main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++) R[i].key=A[i];
	printf("��ʼ����:  "); dispR(R,n,-1);
	printf("�����������:\n");
	BubbleSort(R,n);
    return 0;
}

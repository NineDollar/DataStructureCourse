#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;					//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;					//��������,ElemTypeΪ�������ݵ�����
} SqType;
void dispR(SqType R[],int n,int i)	//���R
{	for (int j=1;j<=n;j++)
	{	if (j==i-1)
			printf("%d [",R[j].key);
		else	
			printf("%d  ",R[j].key);
	}
	if (i==-1) printf("[");
	printf("]\n");
}

void Sift(SqType R[],int low,int high)		//��R[low..high]���ж�ɸѡ
{	int i=low,j=2*i;						//R[j]��R[i]������
	SqType tmp=R[i];
	while (j<=high)
	{	if (j<high && R[j].key<R[j+1].key) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;
		if (tmp.key<R[j].key) 
		{	R[i]=R[j];						//��R[j]������˫�׽��λ����
			i=j;							//�޸�i��jֵ,�Ա��������ɸѡ
			j=2*i;
		}
		else break;							//ɸѡ����
	}
	R[i]=tmp;								//��ɸѡ����ֵ��������λ��
}
void HeapSort(SqType R[],int n)		//��R[1..n]���е���������
{	int i;
	SqType tmp;
	for (i=n/2;i>=1;i--)	//ѭ��������ʼ��
		Sift(R,i,n); 
	printf("��ʼ��:     "); dispR(R,n,-1);
	for (i=n;i>=2;i--)		//����n-1��ѭ��,��ɶ�����
	{
		tmp=R[1];			//��R[1]��R[i]����
		R[1]=R[i];
		R[i]=tmp;
		printf("i=%2d�Ľ��: ",i); dispR(R,n,i);
		Sift(R,1,i-1);		//ɸѡ
		printf("  ɸѡ���: "); dispR(R,n,i);
	}
}
int main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)		//�ؼ��ִ����R[1..n]��
		R[i+1].key=A[i];
	printf("��ʼ����:   ");dispR(R,n,-1);	
	printf("�����������:\n");
	HeapSort(R,n);
    return 0;
}

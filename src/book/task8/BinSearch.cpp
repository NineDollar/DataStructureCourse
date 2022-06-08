#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;		//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;		//��������,ElemTypeΪ�������ݵ�����
} SqType;
int BinSearch(SqType R[],int n,int k)	//�������㷨
{	int low=0,high=n-1,mid;
	while (low<=high)				//��ǰ�������Ԫ��ʱѭ��
	{	mid=(low+high)/2;			//�����������м�λ��
		if (R[mid].key==k)			//���ҳɹ��������߼����mid+1
			return mid+1;			//�ҵ��󷵻����߼����mid+1
		else if (R[mid].key>k)		//������R[low..mid-1]�в���
			high=mid-1;
		else						//R[mid].key<k
			low=mid+1;				//������R[mid+1..high]�в���
	}
	return 0;						//����ǰ��������û��Ԫ��ʱ����0
}

#include "SqList.cpp"			//����˳���������㺯��
void Deletex(SqList &L,ElemType x)
{	int i,k=0;
	for (i=0;i<L.length;i++)
		if (L.data[i]!=x)		//����Ϊx��Ԫ�ز��뵽L��
		{	L.data[k]=L.data[i];
			k++;
		}
	L.length=k;					//����L�ĳ���
}
int Maxelem(SqList L)			//�������Ԫ��ֵ
{
	int maxe=L.data[0];
	for (int i=1;i<L.length;i++)
		if (L.data[i]>maxe)
			maxe=L.data[i];
	return maxe;
}
void Delmaxe(SqList &L)			//ɾ��L���������ֵ��Ԫ��
{
	int x;
	x=Maxelem(L);
	Deletex(L,x);
}
int main()
{
	SqList L;
	int a[]={2,1,5,4,2,5,1,5,4};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("L: "); DispList(L);
	printf("ɾ������Ԫ��\n");
	Delmaxe(L);
	printf("L: "); DispList(L);
	DestroyList(L);
    return 0;
}

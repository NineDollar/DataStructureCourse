#include "SqList.cpp"			//����˳���������㺯��
void Union(SqList A,SqList B,SqList &C)		//�󲢼�
{
	int i,j,k;					//k��¼C�е�Ԫ�ظ���
	for (i=0;i<A.length;i++)	//��A��Ԫ�ظ��Ƶ�C��
		C.data[i]=A.data[i];
	k=A.length;
	for (j=0;j<B.length;j++)	//����˳���B
	{	i=0;
		while (i<A.length && A.data[i]!=B.data[j])
			i++;
		if (i==A.length)		//��ʾB.data[j]����A��,����ŵ�C��
			C.data[k++]=B.data[j];
	}
	C.length=k;				//�޸ļ��ϳ���
}
void Diffence(SqList A,SqList B,SqList &C)	//��
{	int i,j,k=0;				//k��¼C�е�Ԫ�ظ���
	for (i=0;i<A.length;i++)	//����˳���A
	{	j=0;
		while (j<B.length && B.data[j]!=A.data[i])
			j++;
		if (j==B.length)		//��ʾA.data[i]����B��,����ŵ�C��
			C.data[k++]=A.data[i];
	}
	C.length=k;				//�޸ļ��ϳ���
}
void Intersection(SqList A,SqList B,SqList &C)	//�󽻼�
{	int i,j,k=0;				//k��¼C�е�Ԫ�ظ���
	for (i=0;i<A.length;i++)	//��i����˳���A
	{	j=0;
		while (j<B.length && B.data[j]!=A.data[i])
			j++;
		if (j<B.length)		//��ʾA.data[i]��B��,����ŵ�C��
			C.data[k++]=A.data[i];
	}
	C.length=k;				//�޸ļ��ϳ���
}
int main()
{
	SqList A,B,C;
	int a[]={1,3,5,8,4,2};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(A,a,n);
	printf(" A:  "); DispList(A);

	int b[]={2,6,4,10,5};
	int m=sizeof(b)/sizeof(b[0]);
	CreateList(B,b,m);
	printf(" B:  "); DispList(B);

	printf(" C=A��B\n");
	Union(A,B,C);
	printf(" C:  "); DispList(C);

	printf(" C=A-B\n");
	Diffence(A,B,C);
	printf(" C:  "); DispList(C);

	printf(" C=A��B\n");
	Intersection(A,B,C);
	printf(" C:  "); DispList(C);

	DestroyList(A);
	DestroyList(B);
	DestroyList(C);
    return 0;
}

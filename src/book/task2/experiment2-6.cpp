#include "SqList.cpp"			//包含顺序表基本运算函数
void Union(SqList A,SqList B,SqList &C)		//求并集
{
	int i,j,k;					//k记录C中的元素个数
	for (i=0;i<A.length;i++)	//将A中元素复制到C中
		C.data[i]=A.data[i];
	k=A.length;
	for (j=0;j<B.length;j++)	//遍历顺序表B
	{	i=0;
		while (i<A.length && A.data[i]!=B.data[j])
			i++;
		if (i==A.length)		//表示B.data[j]不在A中,将其放到C中
			C.data[k++]=B.data[j];
	}
	C.length=k;				//修改集合长度
}
void Diffence(SqList A,SqList B,SqList &C)	//求差集
{	int i,j,k=0;				//k记录C中的元素个数
	for (i=0;i<A.length;i++)	//遍历顺序表A
	{	j=0;
		while (j<B.length && B.data[j]!=A.data[i])
			j++;
		if (j==B.length)		//表示A.data[i]不在B中,将其放到C中
			C.data[k++]=A.data[i];
	}
	C.length=k;				//修改集合长度
}
void Intersection(SqList A,SqList B,SqList &C)	//求交集
{	int i,j,k=0;				//k记录C中的元素个数
	for (i=0;i<A.length;i++)	//用i遍历顺序表A
	{	j=0;
		while (j<B.length && B.data[j]!=A.data[i])
			j++;
		if (j<B.length)		//表示A.data[i]在B中,将其放到C中
			C.data[k++]=A.data[i];
	}
	C.length=k;				//修改集合长度
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

	printf(" C=A∪B\n");
	Union(A,B,C);
	printf(" C:  "); DispList(C);

	printf(" C=A-B\n");
	Diffence(A,B,C);
	printf(" C:  "); DispList(C);

	printf(" C=A∩B\n");
	Intersection(A,B,C);
	printf(" C:  "); DispList(C);

	DestroyList(A);
	DestroyList(B);
	DestroyList(C);
    return 0;
}

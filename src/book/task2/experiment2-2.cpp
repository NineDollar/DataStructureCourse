#include "SqList.cpp"			//包含顺序表基本运算函数
void Deletex(SqList &L,ElemType x)
{	int i,k=0;
	for (i=0;i<L.length;i++)
		if (L.data[i]!=x)		//将不为x的元素插入到L中
		{	L.data[k]=L.data[i];
			k++;
		}
	L.length=k;					//重置L的长度
}
int Maxelem(SqList L)			//查找最大元素值
{
	int maxe=L.data[0];
	for (int i=1;i<L.length;i++)
		if (L.data[i]>maxe)
			maxe=L.data[i];
	return maxe;
}
void Delmaxe(SqList &L)			//删除L中所有最大值的元素
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
	printf("删除最大的元素\n");
	Delmaxe(L);
	printf("L: "); DispList(L);
	DestroyList(L);
    return 0;
}

#include <stdio.h>
void Reverse(int A[],int i,int j)		//逆置A[i..j]
{	int k,tmp;
	for (k=0;k<(j-i+1)/2;k++)
	{	tmp=A[i+k];
		A[i+k]=A[j-k];
		A[j-k]=tmp;
	}
}
void Rightmove(int A[],int n,int m)	//将A[0..n-1]循环右移m个元素
{
	if (m>n) m=m%n;
	Reverse(A,0,n-m-1);
	Reverse(A,n-m,n-1);
	Reverse(A,0,n-1);
}
void display(int A[],int n,int m)	//输出测试结果
{
	printf("  移动前:");
	for (int i=0;i<n;i++)
		printf("%3d",A[i]);
	printf("\n");
	printf("  循环右移%d个元素\n",m);
	Rightmove(A,n,m);
	printf("  移动后:");
	for (int j=0;j<n;j++)
		printf("%3d",A[j]);
	printf("\n");
}
int main()
{
	int a[]={1,2,3,4,5,6};
	int n1=sizeof(a)/sizeof(a[0]);
	int m1=4;
	printf("测试1\n");
	display(a,n1,m1);
	printf("测试2\n");
	int b[]={1,2,3,4,5,6};
	int n2=sizeof(b)/sizeof(b[0]);
	int m2=20;
	display(b,n2,m2);
    return 0;
}

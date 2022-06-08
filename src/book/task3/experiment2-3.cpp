#include "SqStack1.cpp"				//包含顺序栈(栈元素为int类型)的基本运算函数
int Validseq(int a[],int n)
{
	int i,j,e;
	SqStack st;						//定义一个顺序栈st
	InitStack(st);					//初始化栈st
	j=0;
	for(i=1;i<=n;i++)				//处理进栈序列1、2、…、n
	{
		Push(st,i);					//整数i进栈
		printf("    %d进栈\n",i);
		while (!StackEmpty(st))		//栈不空循环
		{
			GetTop(st,e);			//取栈顶元素e
			if (a[j]==e)			//匹配的情况
			{
				Pop(st,e);			//退栈元素e
				printf("    %d退栈\n",e);
				j++;
			}
			else break;				//不匹配时退出while循环
        }
	}
	if (StackEmpty(st))				//栈空返回true;否则返回false
	{
		DestroyStack(st);			//销毁栈st
		return true;
	}
	else
	{
		DestroyStack(st);			//销毁栈st
		return false;
	}
}
void dispa(int a[],int n)			//输出a
{	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void display(int a[],int n)			//测试一个序列a
{
	printf("  测试 a:"); dispa(a,n);
	if (Validseq(a,n))
		printf("  a是合法序列\n");
	else
		printf("  a不是合法序列\n");
}
int main()
{
	printf("测试结果:\n");
	int n=5;
	int a[]={2,1,5,4,3};
	display(a,n);
	int a1[]={5,1,2,3,4};
	display(a1,n);
    return 0;
}

#include "SqQueue1.cpp"			//包含循环队列(队列元素为int类型)基本运算函数
void Josephus(int n,int m)		//用队列求解约瑟夫问题
{
	int i,p;
	SqQueue sq;					//定义一个顺序队sq
	InitQueue(sq);				//初始化队列
	for (i=1;i<=n;i++)			//n个人进队
		EnQueue(sq,i);
	printf(" 出列顺序:");
	i=0;
	while (!QueueEmpty(sq))		//队不空循环
	{
		DeQueue(sq,p);			//出队元素p
		i++;					//出队个数计数
		if (i % m==0)			//循环报数到m
			printf("%d ",p);	//出列p
		else
			EnQueue(sq,p);		//将p进队
	}
	printf("\n");
	DestroyQueue(sq);			//销毁队列
}
void display(int n,int m)		//测试一个约瑟夫问题
{
	printf("  n=%d,m=%d ",n,m);
	Josephus(n,m);
}
int main()
{
	printf("测试结果:\n");
	display(6,3);
	display(6,5);
	display(5,8);
	display(4,2);
    return 0;
}

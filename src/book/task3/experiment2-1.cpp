#include "SqStack.cpp"				//包含顺序栈的基本运算函数
void Dele(SqStack &st,ElemType e)	//求解算法
{	ElemType x;
	SqStack tmpst;
	InitStack(tmpst);
	while (!StackEmpty(st))		//栈st不空循环
	{	Pop(st,x);				//出栈元素x
		if (x!=e)
			Push(tmpst,x);
	}
	while (!StackEmpty(tmpst))	//栈tmpst不空循环
	{	Pop(tmpst,x);			//出栈元素x
		Push(st,x);
	}
	DestroyStack(tmpst);		//销毁栈tmpst
}
int main()
{
	SqStack st;
	printf("初始化栈st\n");
	InitStack(st);
	printf("元素1,2,2,1,2,3依次进栈\n");
	Push(st,'1');
	Push(st,'2');
	Push(st,'2');
	Push(st,'1');
	Push(st,'2');
	Push(st,'3');
	char e='2';
	printf("删除所有元素%c\n",e);
	Dele(st,e);
	printf("出栈序列: ");
	while (!StackEmpty(st))
	{
		Pop(st,e);
		printf("%c ",e);
	}
	printf("\n销毁栈\n");
	DestroyStack(st);
    return 0;
}

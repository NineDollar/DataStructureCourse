#include "SqStack.cpp"				//����˳��ջ�Ļ������㺯��
void Dele(SqStack &st,ElemType e)	//����㷨
{	ElemType x;
	SqStack tmpst;
	InitStack(tmpst);
	while (!StackEmpty(st))		//ջst����ѭ��
	{	Pop(st,x);				//��ջԪ��x
		if (x!=e)
			Push(tmpst,x);
	}
	while (!StackEmpty(tmpst))	//ջtmpst����ѭ��
	{	Pop(tmpst,x);			//��ջԪ��x
		Push(st,x);
	}
	DestroyStack(tmpst);		//����ջtmpst
}
int main()
{
	SqStack st;
	printf("��ʼ��ջst\n");
	InitStack(st);
	printf("Ԫ��1,2,2,1,2,3���ν�ջ\n");
	Push(st,'1');
	Push(st,'2');
	Push(st,'2');
	Push(st,'1');
	Push(st,'2');
	Push(st,'3');
	char e='2';
	printf("ɾ������Ԫ��%c\n",e);
	Dele(st,e);
	printf("��ջ����: ");
	while (!StackEmpty(st))
	{
		Pop(st,e);
		printf("%c ",e);
	}
	printf("\n����ջ\n");
	DestroyStack(st);
    return 0;
}

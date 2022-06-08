#include <stdio.h>
#define MaxSize 100				//˳��ջ�ĳ�ʼ����ռ��С
typedef char ElemType;			//����˳��ջ������Ԫ��Ϊchar����
typedef struct
{	ElemType data[MaxSize];		//����ջ��Ԫ��
	int top;					//ջ��ָ��
} SqStack;						//˳��ջ����

void InitStack(SqStack &st)		//��ʼ��˳��ջst
{
	st.top=-1;
}
void DestroyStack(SqStack st)	//����˳��ջst
{  }

int Push(SqStack &st,ElemType x)	//��ջԪ��x
{	if (st.top==MaxSize-1)			//ջ��
		return 0;
	else
	{	st.top++;
		st.data[st.top]=x;
		return 1;
	}
}

int Pop(SqStack &st,ElemType &x)	//��ջԪ��x
{	if (st.top==-1)					//ջ��
		return 0;
	else
	{	x=st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st,ElemType &x)	//ȡջ��Ԫ��x
{	if (st.top==-1)					//ջ��
		return 0;
	else
	{	x=st.data[st.top];
		return 1;
	}
}

int StackEmpty(SqStack st)		//�ж�ջ�Ƿ�Ϊ��
{	if (st.top==-1) return 1;
	else return 0;
}

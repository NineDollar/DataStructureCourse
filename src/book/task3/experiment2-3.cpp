#include "SqStack1.cpp"				//����˳��ջ(ջԪ��Ϊint����)�Ļ������㺯��
int Validseq(int a[],int n)
{
	int i,j,e;
	SqStack st;						//����һ��˳��ջst
	InitStack(st);					//��ʼ��ջst
	j=0;
	for(i=1;i<=n;i++)				//�����ջ����1��2������n
	{
		Push(st,i);					//����i��ջ
		printf("    %d��ջ\n",i);
		while (!StackEmpty(st))		//ջ����ѭ��
		{
			GetTop(st,e);			//ȡջ��Ԫ��e
			if (a[j]==e)			//ƥ������
			{
				Pop(st,e);			//��ջԪ��e
				printf("    %d��ջ\n",e);
				j++;
			}
			else break;				//��ƥ��ʱ�˳�whileѭ��
        }
	}
	if (StackEmpty(st))				//ջ�շ���true;���򷵻�false
	{
		DestroyStack(st);			//����ջst
		return true;
	}
	else
	{
		DestroyStack(st);			//����ջst
		return false;
	}
}
void dispa(int a[],int n)			//���a
{	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void display(int a[],int n)			//����һ������a
{
	printf("  ���� a:"); dispa(a,n);
	if (Validseq(a,n))
		printf("  a�ǺϷ�����\n");
	else
		printf("  a���ǺϷ�����\n");
}
int main()
{
	printf("���Խ��:\n");
	int n=5;
	int a[]={2,1,5,4,3};
	display(a,n);
	int a1[]={5,1,2,3,4};
	display(a1,n);
    return 0;
}

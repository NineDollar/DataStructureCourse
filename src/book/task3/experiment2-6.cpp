#include "SqQueue1.cpp"			//����ѭ������(����Ԫ��Ϊint����)�������㺯��
void Josephus(int n,int m)		//�ö������Լɪ������
{
	int i,p;
	SqQueue sq;					//����һ��˳���sq
	InitQueue(sq);				//��ʼ������
	for (i=1;i<=n;i++)			//n���˽���
		EnQueue(sq,i);
	printf(" ����˳��:");
	i=0;
	while (!QueueEmpty(sq))		//�Ӳ���ѭ��
	{
		DeQueue(sq,p);			//����Ԫ��p
		i++;					//���Ӹ�������
		if (i % m==0)			//ѭ��������m
			printf("%d ",p);	//����p
		else
			EnQueue(sq,p);		//��p����
	}
	printf("\n");
	DestroyQueue(sq);			//���ٶ���
}
void display(int n,int m)		//����һ��Լɪ������
{
	printf("  n=%d,m=%d ",n,m);
	Josephus(n,m);
}
int main()
{
	printf("���Խ��:\n");
	display(6,3);
	display(6,5);
	display(5,8);
	display(4,2);
    return 0;
}

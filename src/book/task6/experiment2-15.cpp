#include "BTree.cpp"			//�����������Ļ������㺯��
int LevelkNode(BTNode *b,int k)
{	BTNode *Qu[MaxSize];		//����ѭ������
	int front,rear;				//�����ͷ�Ͷ�βָ��
	int num=0;					//num�ۼƵ�k�������
	int last;					//���嵱ǰ�������ҽ���ڶ����е�λ��
	int level;					//���嵱ǰ���Ĳ��
	front=rear=0;				//�ö���Ϊ�ն���
	if (b==NULL || k<=0)		//�������󷵻�0
		return 0;
	rear++;						//��������
	last=rear;level=1;			//��1������ҽ���ڶ����е�λ��Ϊ1,����Ϊ1
	Qu[rear]=b;
	while (rear!=front)			//���в�Ϊ��ʱѭ��
	{	front=(front+1)%MaxSize;
		b=Qu[front];			//����
		if (level==k)
			num++;				//��k���������1
		if (b->lchild!=NULL) 	//���ӽ���
		{	rear=(rear+1)%MaxSize;
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL) 	//�Һ��ӽ���
		{	rear=(rear+1)%MaxSize;
			Qu[rear]=b->rchild;
		}
		if (front==last)		//ͬ������ҽ�㴦�����,������1
		{
			if (level==k)		//��ǰ��ŵ���kʱ����num,���ټ���
				return num;
			level++;
			last=rear;			//��lastָ����һ������ҽ���ڶ����е�λ��
		}
	}
	return 0;
}
int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))"); //���������
	printf("b: "); DispBTree(b); printf("\n");
	for (int k=0;k<=5;k++)
		printf("  b�е�%d��Ľ�����=%d\n",k,LevelkNode(b,k));
	DestroyBTree(b);
    return 0;
}

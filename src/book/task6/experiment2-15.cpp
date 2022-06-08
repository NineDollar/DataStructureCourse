#include "BTree.cpp"			//包含二叉树的基本运算函数
int LevelkNode(BTNode *b,int k)
{	BTNode *Qu[MaxSize];		//定义循环队列
	int front,rear;				//定义队头和队尾指针
	int num=0;					//num累计第k层结点个数
	int last;					//定义当前层中最右结点在队列中的位置
	int level;					//定义当前结点的层号
	front=rear=0;				//置队列为空队列
	if (b==NULL || k<=0)		//条件错误返回0
		return 0;
	rear++;						//根结点进队
	last=rear;level=1;			//第1层的最右结点在队列中的位置为1,其层次为1
	Qu[rear]=b;
	while (rear!=front)			//队列不为空时循环
	{	front=(front+1)%MaxSize;
		b=Qu[front];			//出队
		if (level==k)
			num++;				//第k层结点个数增1
		if (b->lchild!=NULL) 	//左孩子进队
		{	rear=(rear+1)%MaxSize;
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL) 	//右孩子进队
		{	rear=(rear+1)%MaxSize;
			Qu[rear]=b->rchild;
		}
		if (front==last)		//同层的最右结点处理完毕,层数增1
		{
			if (level==k)		//当前层号等于k时返回num,不再继续
				return num;
			level++;
			last=rear;			//让last指向下一层的最右结点在队列中的位置
		}
	}
	return 0;
}
int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))"); //构造二叉链
	printf("b: "); DispBTree(b); printf("\n");
	for (int k=0;k<=5;k++)
		printf("  b中第%d层的结点个数=%d\n",k,LevelkNode(b,k));
	DestroyBTree(b);
    return 0;
}

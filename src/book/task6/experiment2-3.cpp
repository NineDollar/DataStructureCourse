#include "BTree.cpp"					//包含二叉树的基本运算函数
void Swap(BTNode *b,BTNode *&t)			//求解算法
{	if (b==NULL)
		t=NULL;
	else
	{	t=(BTNode *)malloc(sizeof(BTNode));	//复制根结点
		t->data=b->data;
		Swap(b->lchild,t->rchild);		//交换左子树
		Swap(b->rchild,t->lchild); 		//交换右子树
	}
}
int main()
{
	BTNode *b,*t;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");		//构造二叉链
	printf("b: "); DispBTree(b); printf("\n");
	printf("b产生t\n");
	Swap(b,t);
	printf("t: "); DispBTree(t); printf("\n");
	DestroyBTree(b);
	DestroyBTree(t);
    return 0;
}

#include "BST.cpp"					//包含二叉排序树的基本运算函数
#include <math.h>
int judgeAVL(BSTNode *bt,int &h)
{	int bl,br,hl,hr;
	if (bt==NULL)					//空树
	{
		h=0;
		return 1;
	}
	if (bt->lchild==NULL && bt->rchild==NULL)	//叶子结点
	{
		h=1;
		return 1;
	}
	bl=judgeAVL(bt->lchild,hl);		//判断左子树
	br=judgeAVL(bt->rchild,hr);		//判断右子树
	h=(hl>hr?hl:hr)+1;
	if (abs(hl-hr)<2)				//h1和h2的绝对值是否小于2
		return bl & br;				//"&"为整数的与运算
	else
		return 0;
}
void display(BSTNode *bt)			//输出测试结果
{
	printf("  bt: "); DispBST(bt); printf("\n");
	int balance,h;
	balance=judgeAVL(bt,h);
	if (balance)
		printf("  bt是一棵AVL\n");
	else
		printf("  bt不是一棵AVL\n");
}
int main()
{
	BSTNode *bt1,*bt2;
	KeyType a[]={3,2,1,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	CreateBST(bt1,a,n);
	KeyType b[]={3,2,1,5,4,6};
	int m=sizeof(b)/sizeof(b[0]);
	CreateBST(bt2,b,m);
	printf("求解结果:\n");
	printf("测试1\n"); display(bt1);
	printf("测试2\n"); display(bt2);
	DestroyBST(bt1);
	DestroyBST(bt2);
    return 0;
}


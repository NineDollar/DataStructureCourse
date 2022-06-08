#include "BST.cpp"		//包含二叉排序树的基本运算函数
KeyType predt=0;		//predt为全局变量,保存当前结点中序前驱的值,初值为最小值
int judgeBST(BSTNode *bt)
{	//返回1表示是一棵二叉排序树，返回0表示不是
	int b1,b2;
	if (bt==NULL)					//空树是一棵二叉排序树
		return 1;
	else
	{	b1=judgeBST(bt->lchild);	//判断左子树
		if (b1==false)
			return 0;		//若左子树不是BST，则返回0
		if (predt>=bt->key)
			return 0;		//若当前结点值小于等于中序前驱结点值，则返回0
		predt=bt->key;			//保存当前结点的关键字
		b2=judgeBST(bt->rchild);	//判断右子树
		return b2;
	}
}
int main()
{
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11};
	int n=12;
	BSTNode *bt;
	CreateBST(bt,a,n);
	printf("bt: "); DispBST(bt); printf("\n");
	if (judgeBST(bt))
		printf("bt是一棵二叉排序树\n");
	else
		printf("bt不是一棵二叉排序树\n");
	printf("将bt的根结点改为10\n");
	bt->key=20;
	printf("bt: "); DispBST(bt); printf("\n");
	if (judgeBST(bt))
		printf("bt是一棵二叉排序树\n");
	else
		printf("bt不是一棵二叉排序树\n");
	DestroyBST(bt);
    return 0;
}


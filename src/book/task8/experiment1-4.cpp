#include "BST.cpp"
int main()
{
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11},k;
	int n=12;
	BSTNode *bt;
	printf("(1)创建二叉排序树bt\n");
	CreateBST(bt,a,n);
	printf("  BST:"); DispBST(bt); printf("\n");
	k=32;
	printf("(2)查找关键字%d\n",k);
	BSTNode *p=BSTSearch(bt,k);
	if (p!=NULL)
		printf("  查找成功!\n");
	else
		printf("  查找失败!\n");
	k=25;
	printf("(3)删除关键字%d\n",k);
	if (BSTDelete(bt,k))
	{
		printf("  BST:"); 
		DispBST(bt); printf("\n");
	}
	else
		printf("未找到关键字为%d的结点\n",k);
	printf("(4)插入关键字%d\n",k);
	if (BSTInsert(bt,k))
	{
		printf("  BST:"); 
		DispBST(bt); printf("\n");
	}
	else
		printf("存在重复的关键字%d\n",k);
	printf("(5)销毁bt\n");
	DestroyBST(bt);
    return 0;
}


#include "BST.cpp"					//包含二叉排序树的基本运算函数
#define MaxSize 100
void dispb(int b[],int m)		//输出序列b
{	printf("序列: ");
	for (int i=0;i<m;i++)
		printf("%d ",b[i]);
}
int SearchBSTk(BSTNode *bt,int k,int a[],int n)	//求解算法
{	BSTNode *p=bt;
	int i=0;
	if (a[n-1]!=k)						//未找到k，返回0
		return 0;
	while (p!=NULL)
	{	if (p->key!=a[i])				//若不等，表示a不是k的查找序列
			return 0;
		if (k<p->key) p=p->lchild;		//在左子树中查找
		if (k>p->key) p=p->rchild;		//在右子树中查找
		i++;							//查找序列指向下一个关键字
	}
	if (p!=NULL) return 1;				//找到了k，返回1
	else return 0;						//未找到k，返回0
}
int main()
{
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11};
	int n=12;
	BSTNode *bt;
	CreateBST(bt,a,n);
	printf("bt: "); DispBST(bt); printf("\n");
	int b1[]={25,46,39,32};
	int m=sizeof(b1)/sizeof(b1[0]);
	int k=32;
	dispb(b1,m);
	if (SearchBSTk(bt,k,b1,m))
		printf(" 是搜索关键字%d的序列\n",k);
	else
		printf(" 不是搜索关键字%d的序列\n",k);

	int b2[]={25,18,4};
	m=sizeof(b2)/sizeof(b2[0]);
	k=4;
	dispb(b2,m);
	if (SearchBSTk(bt,k,b2,m))
		printf(" 是搜索关键字%d的序列\n",k);
	else
		printf(" 不是搜索关键字%d的序列\n",k);
	DestroyBST(bt);
    return 0;
}


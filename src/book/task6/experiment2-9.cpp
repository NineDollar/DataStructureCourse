#include <stdio.h>
#include "BTree.cpp"							//包含二叉树的基本运算函数
void Path(BTNode *b,ElemType x,ElemType path[],int pathlen)
{
	if (b!=NULL)
	{	if (b->data==x)					//找到值为x的结点
		{	printf("从根结点到%c结点的路径: ",b->data);
			for (int i=0;i<pathlen;i++)
				printf("%c→",path[i]);
			printf("%c\n",b->data);
			return;
		}
		else
		{	path[pathlen]=b->data;				//将当前结点放入路径中
			pathlen++;							//path中元素个数增1
			Path(b->lchild,x,path,pathlen);	//递归遍历左子树
			Path(b->rchild,x,path,pathlen);	//递归遍历右子树
		}
	}
}

int main()
{	BTNode *b;
	ElemType path[MaxSize],x='I';
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//创建二叉链
	printf("b: "); DispBTree(b); printf("\n");
	Path(b,x,path,0);
	DestroyBTree(b);
    return 0;
}

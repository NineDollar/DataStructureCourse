#include "BST.cpp"
int main()
{
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11},k;
	int n=12;
	BSTNode *bt;
	printf("(1)��������������bt\n");
	CreateBST(bt,a,n);
	printf("  BST:"); DispBST(bt); printf("\n");
	k=32;
	printf("(2)���ҹؼ���%d\n",k);
	BSTNode *p=BSTSearch(bt,k);
	if (p!=NULL)
		printf("  ���ҳɹ�!\n");
	else
		printf("  ����ʧ��!\n");
	k=25;
	printf("(3)ɾ���ؼ���%d\n",k);
	if (BSTDelete(bt,k))
	{
		printf("  BST:"); 
		DispBST(bt); printf("\n");
	}
	else
		printf("δ�ҵ��ؼ���Ϊ%d�Ľ��\n",k);
	printf("(4)����ؼ���%d\n",k);
	if (BSTInsert(bt,k))
	{
		printf("  BST:"); 
		DispBST(bt); printf("\n");
	}
	else
		printf("�����ظ��Ĺؼ���%d\n",k);
	printf("(5)����bt\n");
	DestroyBST(bt);
    return 0;
}


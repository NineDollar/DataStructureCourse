#include "BST.cpp"					//���������������Ļ������㺯��
#include <math.h>
int judgeAVL(BSTNode *bt,int &h)
{	int bl,br,hl,hr;
	if (bt==NULL)					//����
	{
		h=0;
		return 1;
	}
	if (bt->lchild==NULL && bt->rchild==NULL)	//Ҷ�ӽ��
	{
		h=1;
		return 1;
	}
	bl=judgeAVL(bt->lchild,hl);		//�ж�������
	br=judgeAVL(bt->rchild,hr);		//�ж�������
	h=(hl>hr?hl:hr)+1;
	if (abs(hl-hr)<2)				//h1��h2�ľ���ֵ�Ƿ�С��2
		return bl & br;				//"&"Ϊ������������
	else
		return 0;
}
void display(BSTNode *bt)			//������Խ��
{
	printf("  bt: "); DispBST(bt); printf("\n");
	int balance,h;
	balance=judgeAVL(bt,h);
	if (balance)
		printf("  bt��һ��AVL\n");
	else
		printf("  bt����һ��AVL\n");
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
	printf("�����:\n");
	printf("����1\n"); display(bt1);
	printf("����2\n"); display(bt2);
	DestroyBST(bt1);
	DestroyBST(bt2);
    return 0;
}


#include "BST.cpp"		//���������������Ļ������㺯��
KeyType predt=0;		//predtΪȫ�ֱ���,���浱ǰ�������ǰ����ֵ,��ֵΪ��Сֵ
int judgeBST(BSTNode *bt)
{	//����1��ʾ��һ�ö���������������0��ʾ����
	int b1,b2;
	if (bt==NULL)					//������һ�ö���������
		return 1;
	else
	{	b1=judgeBST(bt->lchild);	//�ж�������
		if (b1==false)
			return 0;		//������������BST���򷵻�0
		if (predt>=bt->key)
			return 0;		//����ǰ���ֵС�ڵ�������ǰ�����ֵ���򷵻�0
		predt=bt->key;			//���浱ǰ���Ĺؼ���
		b2=judgeBST(bt->rchild);	//�ж�������
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
		printf("bt��һ�ö���������\n");
	else
		printf("bt����һ�ö���������\n");
	printf("��bt�ĸ�����Ϊ10\n");
	bt->key=20;
	printf("bt: "); DispBST(bt); printf("\n");
	if (judgeBST(bt))
		printf("bt��һ�ö���������\n");
	else
		printf("bt����һ�ö���������\n");
	DestroyBST(bt);
    return 0;
}


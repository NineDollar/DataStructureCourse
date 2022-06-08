#include "BTree.cpp"					//�����������Ļ������㺯��
void Swap(BTNode *b,BTNode *&t)			//����㷨
{	if (b==NULL)
		t=NULL;
	else
	{	t=(BTNode *)malloc(sizeof(BTNode));	//���Ƹ����
		t->data=b->data;
		Swap(b->lchild,t->rchild);		//����������
		Swap(b->rchild,t->lchild); 		//����������
	}
}
int main()
{
	BTNode *b,*t;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");		//���������
	printf("b: "); DispBTree(b); printf("\n");
	printf("b����t\n");
	Swap(b,t);
	printf("t: "); DispBTree(t); printf("\n");
	DestroyBTree(b);
	DestroyBTree(t);
    return 0;
}

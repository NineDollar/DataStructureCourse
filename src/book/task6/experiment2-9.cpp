#include <stdio.h>
#include "BTree.cpp"							//�����������Ļ������㺯��
void Path(BTNode *b,ElemType x,ElemType path[],int pathlen)
{
	if (b!=NULL)
	{	if (b->data==x)					//�ҵ�ֵΪx�Ľ��
		{	printf("�Ӹ���㵽%c����·��: ",b->data);
			for (int i=0;i<pathlen;i++)
				printf("%c��",path[i]);
			printf("%c\n",b->data);
			return;
		}
		else
		{	path[pathlen]=b->data;				//����ǰ������·����
			pathlen++;							//path��Ԫ�ظ�����1
			Path(b->lchild,x,path,pathlen);	//�ݹ����������
			Path(b->rchild,x,path,pathlen);	//�ݹ����������
		}
	}
}

int main()
{	BTNode *b;
	ElemType path[MaxSize],x='I';
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//����������
	printf("b: "); DispBTree(b); printf("\n");
	Path(b,x,path,0);
	DestroyBTree(b);
    return 0;
}

#include "BST.cpp"					//���������������Ļ������㺯��
#define MaxSize 100
void dispb(int b[],int m)		//�������b
{	printf("����: ");
	for (int i=0;i<m;i++)
		printf("%d ",b[i]);
}
int SearchBSTk(BSTNode *bt,int k,int a[],int n)	//����㷨
{	BSTNode *p=bt;
	int i=0;
	if (a[n-1]!=k)						//δ�ҵ�k������0
		return 0;
	while (p!=NULL)
	{	if (p->key!=a[i])				//�����ȣ���ʾa����k�Ĳ�������
			return 0;
		if (k<p->key) p=p->lchild;		//���������в���
		if (k>p->key) p=p->rchild;		//���������в���
		i++;							//��������ָ����һ���ؼ���
	}
	if (p!=NULL) return 1;				//�ҵ���k������1
	else return 0;						//δ�ҵ�k������0
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
		printf(" �������ؼ���%d������\n",k);
	else
		printf(" ���������ؼ���%d������\n",k);

	int b2[]={25,18,4};
	m=sizeof(b2)/sizeof(b2[0]);
	k=4;
	dispb(b2,m);
	if (SearchBSTk(bt,k,b2,m))
		printf(" �������ؼ���%d������\n",k);
	else
		printf(" ���������ؼ���%d������\n",k);
	DestroyBST(bt);
    return 0;
}


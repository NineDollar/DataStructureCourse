#include "SLinkNode.cpp"				//����������������㺯��
void DelSame(SLinkNode *&L)
{	SLinkNode *p=L->next,*q;
	while (p->next!=NULL) 
	{	if (p->data==p->next->data) 	//�ҵ��ظ�ֵ�Ľ��p->next
		{	q=p->next;					//qָ������ظ�ֵ�Ľ��
			p->next=q->next;			//ɾ��q���
			free(q);
		}
		else p=p->next;
	}
}

int main()
{
	SLinkNode *L;
	int a[]={1,2,2,3,3,3,4,5,5,6,6};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);
	printf("  L: ");DispList(L);
	printf("  ɾ��ֵ�ظ��Ľ��\n");
	DelSame(L);
	printf("  L: ");DispList(L);
	DestroyList(L);
    return 0;
}

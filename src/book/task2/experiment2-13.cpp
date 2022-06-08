#include "SLinkNode.cpp"		//包含单链表基本运算函数
void Merge(SLinkNode *L1,SLinkNode *L2,SLinkNode *&L3)
{	SLinkNode *p=L1->next,*q=L2->next,*s,*t;
	L3=(SLinkNode *)malloc(sizeof(SLinkNode));
	t=L3;
	while (p!=NULL && q!=NULL)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=p->data;		//复制产生s结点并链到L3的末尾
		t->next=s;t=s;
		p=p->next;
		s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=q->data;		//复制产生s结点并链到L3的末尾
		t->next=s;t=s;
		q=q->next;
	}
	if (q!=NULL) p=q;			//让p指向未遍历完的结点
	while (p!=NULL)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=p->data;		//复制产生s结点并链到L3的末尾
		p=p->next;
	}
	t->next=NULL;
}
int main()
{
	SLinkNode *L1,*L2,*L3;
	int a[]={1,3,5,7,9};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L1,a,n);				//尾插法建表
	printf("L1: ");DispList(L1);
	int b[]={2,4,6,8};
	int m=sizeof(b)/sizeof(b[0]);
	CreateListR(L2,b,m);				//尾插法建表
	printf("L2: ");DispList(L2);
	printf("L1和L2合并产生L3\n");
	Merge(L1,L2,L3);
	printf("L3: ");DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
    return 0;
}

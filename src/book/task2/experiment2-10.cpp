#include "SLinkNode.cpp"				//包含单链表基本运算函数
void DelSame(SLinkNode *&L)
{	SLinkNode *p=L->next,*q;
	while (p->next!=NULL) 
	{	if (p->data==p->next->data) 	//找到重复值的结点p->next
		{	q=p->next;					//q指向这个重复值的结点
			p->next=q->next;			//删除q结点
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
	printf("  删除值重复的结点\n");
	DelSame(L);
	printf("  L: ");DispList(L);
	DestroyList(L);
    return 0;
}

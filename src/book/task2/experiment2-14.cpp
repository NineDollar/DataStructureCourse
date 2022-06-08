#include "SLinkNode.cpp"		//包含单链表基本运算函数
void Move(SLinkNode *&L)
{
	SLinkNode *L1[3],*tc1[3];
	SLinkNode *p=L->next,*tc;
	L1[0]=L1[1]=L1[2]=NULL;			//3个不带头结点的单链表
	while (p!=NULL)					//扫描L的所有数据结点
	{
		if (p->data<0)				//p结点值为负数
		{
			if (L1[0]==NULL)		//L1[0]单链表为空时
			{
				L1[0]=p;			//p结点作为L1[0]的首结点
				tc1[0]=p;			//tc1[0]指向L1[0]的尾结点
			}
			else					//L1[0]单链表不为空时
			{
				tc1[0]->next=p;		//将p结点链接到L1[0]的末尾
				tc1[0]=p;			//tc1[0]指向L1[0]的尾结点
			}
		}
		else if (p->data==0)		//p结点值为0
		{
			if (L1[1]==NULL)		//L1[1]单链表为空时
			{
				L1[1]=p;			//p结点作为L1[1]的首结点
				tc1[1]=p;			//tc1[1]指向L1[1]的尾结点
			}
			else					//L1[1]单链表不为空时
			{
				tc1[1]->next=p;		//将p结点链接到L1[1]的末尾
				tc1[1]=p;			//tc1[1]指向L1[1]的尾结点
			}
		}
		else						//p结点值为正数
		{
			if (L1[2]==NULL)		//L1[2]单链表为空时
			{
				L1[2]=p;			//p结点作为L1[2]的首结点
				tc1[2]=p;			//tc1[2]指向L1[2]的尾结点
			}
			else					//L1[2]单链表不为空时
			{
				tc1[2]->next=p;		//将p结点链接到L1[2]的末尾
				tc1[2]=p;			//tc1[2]指向L1[2]的尾结点
			}
		}
		p=p->next;					//p移动到下一个结点
	}
	L->next=NULL;					//L置为空
	tc=L;							//tc作为L的尾结点指针
	for (int i=0;i<3;i++)
	{
		if (L1[i]!=NULL)			//L1[i]为非空
		{
			tc->next=L1[i];			//将L1[i]链接到L
			tc=tc1[i];				//tc取L1[i]的尾结点
		}
	}
	tc->next=NULL;
}
int main()
{
	SLinkNode *L;
	int a[]={6,4,-6,-4,0,1,0,-2,2,0,3,-3,-5};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);				//尾插法建表
	printf("L: ");DispList(L);
	printf("移动\n");
	Move(L);
	printf("L: ");DispList(L);
	DestroyList(L);
    return 0;
}

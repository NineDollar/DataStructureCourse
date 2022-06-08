#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{	ElemType data;					//数据域
	struct node *prior,*next;		//分别指向前驱结点和后继结点的指针
    int freq;						//频度域
} DLinkNode;						//双链表结点类型

void CreateListR(DLinkNode *&L,ElemType a[],int n)	//尾插法建表
{	DLinkNode *s,*tc;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建头结点
	tc=L;										//tc始终指向尾结点,开始时指向头结点
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新结点
		s->data=a[i];
		s->freq=0;
		tc->next=s;								//将s插入tc之后
		s->prior=tc;
		tc=s;
	}
	tc->next=NULL;								//尾结点next域置为NULL
}

void DispList(DLinkNode *L)					//输出双链表L
{	DLinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d[%d] ",p->data,p->freq);
		p=p->next;
	}
	printf("\n");
}

void DestroyList(DLinkNode *&L)		//销毁双链表L
{	DLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;	//pre、p同步后移
	}
	free(pre);
}


int LocateNode(DLinkNode *L,ElemType x)	//本实验题算法
{	DLinkNode *p=L->next,*pre;
	while (p!=NULL && p->data!=x)
		p=p->next;					//找data域值为x的结点p
	if (p==NULL)					//未找到这样的结点
		return 0;
	else							//找到这样的结点p
	{	p->freq++;					//频度增1
		pre=p->prior;				//pre为p前驱结点
		if (pre!=L)					//若pre不为头结点
		{	while (pre!=L && pre->freq<p->freq) //找到pre结点
				pre=pre->prior;
			p->prior->next=p->next;	//先删除p结点
			if (p->next!=NULL)
				p->next->prior=p->prior;
			p->next=pre->next;		//将p结点插入到pre结点之后
			if (pre->next!=NULL)
				pre->next->prior=p;
			pre->next=p;
			p->prior=pre;
		}
		return 1;
	}
}
void display(DLinkNode *L,int x)	//查找x并输出链表
{
	printf("查找%d结点 ",x);
	if (!LocateNode(L,x))
		printf("%d没有找到!\n",x);
	else
	{
		printf("查找后L: ");
		DispList(L);
	}
}
int main()
{
	DLinkNode *L;
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);				//尾插法建表
	printf("L: ");DispList(L);
	int b[]={5,5,1,0,1,2,3,1,5};	//查找序列
	int m=sizeof(b)/sizeof(b[0]);
	for (int j=0;j<m;j++)
		display(L,b[j]);
	DestroyList(L);
    return 0;
}

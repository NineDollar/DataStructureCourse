#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{	ElemType data;					//������
	struct node *prior,*next;		//�ֱ�ָ��ǰ�����ͺ�̽���ָ��
    int freq;						//Ƶ����
} DLinkNode;						//˫����������

void CreateListR(DLinkNode *&L,ElemType a[],int n)	//β�巨����
{	DLinkNode *s,*tc;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));	//����ͷ���
	tc=L;										//tcʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��
		s->data=a[i];
		s->freq=0;
		tc->next=s;								//��s����tc֮��
		s->prior=tc;
		tc=s;
	}
	tc->next=NULL;								//β���next����ΪNULL
}

void DispList(DLinkNode *L)					//���˫����L
{	DLinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d[%d] ",p->data,p->freq);
		p=p->next;
	}
	printf("\n");
}

void DestroyList(DLinkNode *&L)		//����˫����L
{	DLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;	//pre��pͬ������
	}
	free(pre);
}


int LocateNode(DLinkNode *L,ElemType x)	//��ʵ�����㷨
{	DLinkNode *p=L->next,*pre;
	while (p!=NULL && p->data!=x)
		p=p->next;					//��data��ֵΪx�Ľ��p
	if (p==NULL)					//δ�ҵ������Ľ��
		return 0;
	else							//�ҵ������Ľ��p
	{	p->freq++;					//Ƶ����1
		pre=p->prior;				//preΪpǰ�����
		if (pre!=L)					//��pre��Ϊͷ���
		{	while (pre!=L && pre->freq<p->freq) //�ҵ�pre���
				pre=pre->prior;
			p->prior->next=p->next;	//��ɾ��p���
			if (p->next!=NULL)
				p->next->prior=p->prior;
			p->next=pre->next;		//��p�����뵽pre���֮��
			if (pre->next!=NULL)
				pre->next->prior=p;
			pre->next=p;
			p->prior=pre;
		}
		return 1;
	}
}
void display(DLinkNode *L,int x)	//����x���������
{
	printf("����%d��� ",x);
	if (!LocateNode(L,x))
		printf("%dû���ҵ�!\n",x);
	else
	{
		printf("���Һ�L: ");
		DispList(L);
	}
}
int main()
{
	DLinkNode *L;
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);				//β�巨����
	printf("L: ");DispList(L);
	int b[]={5,5,1,0,1,2,3,1,5};	//��������
	int m=sizeof(b)/sizeof(b[0]);
	for (int j=0;j<m;j++)
		display(L,b[j]);
	DestroyList(L);
    return 0;
}

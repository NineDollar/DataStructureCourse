#include "SLinkNode.cpp"		//����������������㺯��
void Move(SLinkNode *&L)
{
	SLinkNode *L1[3],*tc1[3];
	SLinkNode *p=L->next,*tc;
	L1[0]=L1[1]=L1[2]=NULL;			//3������ͷ���ĵ�����
	while (p!=NULL)					//ɨ��L���������ݽ��
	{
		if (p->data<0)				//p���ֵΪ����
		{
			if (L1[0]==NULL)		//L1[0]������Ϊ��ʱ
			{
				L1[0]=p;			//p�����ΪL1[0]���׽��
				tc1[0]=p;			//tc1[0]ָ��L1[0]��β���
			}
			else					//L1[0]������Ϊ��ʱ
			{
				tc1[0]->next=p;		//��p������ӵ�L1[0]��ĩβ
				tc1[0]=p;			//tc1[0]ָ��L1[0]��β���
			}
		}
		else if (p->data==0)		//p���ֵΪ0
		{
			if (L1[1]==NULL)		//L1[1]������Ϊ��ʱ
			{
				L1[1]=p;			//p�����ΪL1[1]���׽��
				tc1[1]=p;			//tc1[1]ָ��L1[1]��β���
			}
			else					//L1[1]������Ϊ��ʱ
			{
				tc1[1]->next=p;		//��p������ӵ�L1[1]��ĩβ
				tc1[1]=p;			//tc1[1]ָ��L1[1]��β���
			}
		}
		else						//p���ֵΪ����
		{
			if (L1[2]==NULL)		//L1[2]������Ϊ��ʱ
			{
				L1[2]=p;			//p�����ΪL1[2]���׽��
				tc1[2]=p;			//tc1[2]ָ��L1[2]��β���
			}
			else					//L1[2]������Ϊ��ʱ
			{
				tc1[2]->next=p;		//��p������ӵ�L1[2]��ĩβ
				tc1[2]=p;			//tc1[2]ָ��L1[2]��β���
			}
		}
		p=p->next;					//p�ƶ�����һ�����
	}
	L->next=NULL;					//L��Ϊ��
	tc=L;							//tc��ΪL��β���ָ��
	for (int i=0;i<3;i++)
	{
		if (L1[i]!=NULL)			//L1[i]Ϊ�ǿ�
		{
			tc->next=L1[i];			//��L1[i]���ӵ�L
			tc=tc1[i];				//tcȡL1[i]��β���
		}
	}
	tc->next=NULL;
}
int main()
{
	SLinkNode *L;
	int a[]={6,4,-6,-4,0,1,0,-2,2,0,3,-3,-5};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);				//β�巨����
	printf("L: ");DispList(L);
	printf("�ƶ�\n");
	Move(L);
	printf("L: ");DispList(L);
	DestroyList(L);
    return 0;
}

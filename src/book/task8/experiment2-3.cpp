#include <stdio.h>
int FindElem(int a[],int n,int k)
{
	int i=4,low,high,mid;
	if (k<a[1] || k>a[4*n]) return -1;
	while(i<=4*n)				//˳�����
	{	if (a[i]==k)
			return i;			//���ҳɹ�����
		else if (a[i]<k)
			i+=4;
		else					//�ҵ�����k��λ��i
			break;
	}
	low=i-3;high=i-1;
	while (low<=high)			//�۰����
	{	mid=(low+high)/2;
		if (a[mid]==k)			//���ҳɹ�����
			return mid;
		if (a[mid]>k)			//������a[low..mid-1]�в���
			high=mid-1;
		else
			low=mid+1;			//������a[mid+1..high]�в���
	}
	return -1;
}
int main()
{
	int a[]={0,1,2,3,4,10,11,12,13,20,21,22,23,30,31,32,33,52,53,54,55};
	int n=5;
	int b[]={2,4,6,8,20,42,52,80};		//��������
	int m=sizeof(b)/sizeof(b[0]);
	printf("�����:\n");
	for (int i=0;i<m;i++)
	{
		int j=FindElem(a,n,b[i]);
		if (j!=-1)
			printf("  ����%d�ɹ�: a[%d]=%d\n",b[i],j,b[i]);
		else
			printf("  ����%dʧ��\n",b[i]);
	}
    return 0;
}

#include "BinSearch.cpp"
int main()
{
	int i,j;
	KeyType a[]={2,4,7,9,10,14,18,26,32,40};
	int n=sizeof(a)/sizeof(a[0]);
	SqType R[MaxSize];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("�����\n");
	for (j=0;j<n;j++)
	{
		i=BinSearch(R,n,a[j]);
		printf("  �ؼ���%2d���߼����:%d\n",a[j],i);
	}
    return 0;
}


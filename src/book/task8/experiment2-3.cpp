#include <stdio.h>
int FindElem(int a[],int n,int k)
{
	int i=4,low,high,mid;
	if (k<a[1] || k>a[4*n]) return -1;
	while(i<=4*n)				//顺序查找
	{	if (a[i]==k)
			return i;			//查找成功返回
		else if (a[i]<k)
			i+=4;
		else					//找到大于k的位置i
			break;
	}
	low=i-3;high=i-1;
	while (low<=high)			//折半查找
	{	mid=(low+high)/2;
		if (a[mid]==k)			//查找成功返回
			return mid;
		if (a[mid]>k)			//继续在a[low..mid-1]中查找
			high=mid-1;
		else
			low=mid+1;			//继续在a[mid+1..high]中查找
	}
	return -1;
}
int main()
{
	int a[]={0,1,2,3,4,10,11,12,13,20,21,22,23,30,31,32,33,52,53,54,55};
	int n=5;
	int b[]={2,4,6,8,20,42,52,80};		//查找序列
	int m=sizeof(b)/sizeof(b[0]);
	printf("求解结果:\n");
	for (int i=0;i<m;i++)
	{
		int j=FindElem(a,n,b[i]);
		if (j!=-1)
			printf("  查找%d成功: a[%d]=%d\n",b[i],j,b[i]);
		else
			printf("  查找%d失败\n",b[i]);
	}
    return 0;
}

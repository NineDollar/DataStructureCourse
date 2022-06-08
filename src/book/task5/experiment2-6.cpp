#define M 5
#define N 5
#include "TSMatrix.cpp"					//包含稀疏矩阵三元组的基本运算函数
int Diagonal(TSMatrix t,ElemType &s)	//求解算法
{	int i;
	if (t.rows!=t.cols)
		return 0;						//不是方阵
	s=0;
	for (i=0;i<t.nums;i++)
		if (t.data[i].r==t.data[i].c)	//行号等于列号
			s+=t.data[i].d;
	return 1;
}
int main()
{
	TSMatrix t;
	int a[N][N]={
		{0,0,1,0,0},
		{0,2,0,0,3},
		{0,0,4,0,0},
		{0,0,0,0,5},
		{0,0,0,0,6} };
	CreatMat(t,a);		//创建三元组t
	printf("三元组t\n");
	DispMat(t);			//输出三元组t
	int s;
	if (Diagonal(t,s))
		printf("主对角线元素之和=%d\n",s);
	else
		printf("不是方阵\n");
    return 0;
}

#define M 5
#define N 5
#include "TSMatrix.cpp"					//����ϡ�������Ԫ��Ļ������㺯��
int Diagonal(TSMatrix t,ElemType &s)	//����㷨
{	int i;
	if (t.rows!=t.cols)
		return 0;						//���Ƿ���
	s=0;
	for (i=0;i<t.nums;i++)
		if (t.data[i].r==t.data[i].c)	//�кŵ����к�
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
	CreatMat(t,a);		//������Ԫ��t
	printf("��Ԫ��t\n");
	DispMat(t);			//�����Ԫ��t
	int s;
	if (Diagonal(t,s))
		printf("���Խ���Ԫ��֮��=%d\n",s);
	else
		printf("���Ƿ���\n");
    return 0;
}

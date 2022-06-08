#include "AdjGraph.cpp"		//�����ڽӱ�Ļ������㺯��
int main()
{
	AdjGraph *G;
	int A[][MAXVEX]={
		{ 0,  2, 5,  3, INF,INF,INF},
		{INF, 0, 2, INF,INF, 8, INF},
		{INF,INF,0, 1,  3,   5, INF},
		{INF,INF,INF,0, 5, INF,INF},
		{INF,INF,INF,INF, 0, 3,  9},
		{INF,INF,INF,INF,INF,0, 5},
		{INF,INF,INF,INF,INF,INF,0}};
	int n=7,e=12;
	CreateGraph(G,A,n,e);	//����ͼ���ڽӱ�
	printf("ͼG�Ĵ洢�ṹ:\n"); DispGraph(G);
	printf("ͼG�����ж���Ķ�:\n"); 
	printf("  ����\t��\n");
	for (int i=0;i<G->n;i++)
		printf("   %d\t%d\n",i,Degree2(G,i));
	printf("����ͼ\n");
	DestroyGraph(G);
}


#include "MinPath.cpp"		//�����������Ȩ����ͼ�����·���ĺ���
int main()
{
	MatGraph g;
	int n=7,e=12,v=0;
	int A[][MAXVEX]={
		{ 0,  2, 5,  3, INF,INF,INF},
		{INF, 0, 2, INF,INF, 8, INF},
		{INF,INF,0, 1,  3,   5, INF},
		{INF,INF,INF,0, 5, INF,INF},
		{INF,INF,INF,INF, 0, 3,  9},
		{INF,INF,INF,INF,INF,0, 5},
		{INF,INF,INF,INF,INF,INF,0}};
	CreateGraph(g,A,n,e);		//����ͼ���ڽӾ���
	printf("ͼG�Ĵ洢�ṹ:\n"); DispGraph(g);
	printf("Dijkstra���������:\n"); 
	Dijkstra(g,v);
	printf("\nFloyd���������:\n"); 
	Floyd(g);
	DestroyGraph(g);
    return 0;
}


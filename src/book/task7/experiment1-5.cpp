#include "MinPath.cpp"		//含有两个求带权有向图中最短路径的函数
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
	CreateGraph(g,A,n,e);		//建立图的邻接矩阵
	printf("图G的存储结构:\n"); DispGraph(g);
	printf("Dijkstra求解结果如下:\n"); 
	Dijkstra(g,v);
	printf("\nFloyd求解结果如下:\n"); 
	Floyd(g);
	DestroyGraph(g);
    return 0;
}


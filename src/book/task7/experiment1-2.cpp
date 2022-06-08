#include "AdjGraph.cpp"		//包含邻接表的基本运算函数
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
	CreateGraph(G,A,n,e);	//建立图的邻接表
	printf("图G的存储结构:\n"); DispGraph(G);
	printf("图G中所有顶点的度:\n"); 
	printf("  顶点\t度\n");
	for (int i=0;i<G->n;i++)
		printf("   %d\t%d\n",i,Degree2(G,i));
	printf("销毁图\n");
	DestroyGraph(G);
}


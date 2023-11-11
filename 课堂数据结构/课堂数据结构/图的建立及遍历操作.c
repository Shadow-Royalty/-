#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "stdio.h"
#include "malloc.h"
#define INFINITY 32767
#define MAX_VERTEX_NUM 20

typedef enum { FALSE, TRUE }visited_hc;
typedef enum { DG, DN, UDG, UDN }graphkind_hc;
//这是一个枚举类型，表示图的种类，包括有向图(DG)、有向网(DN)、无向图(UDG)、无向网(UDN)。

typedef struct arccell_hc
{
	int adj;
	int* info;
}arccell_hc, adjmatrix_hc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//arccell_hc: 邻接矩阵中每个单元格的数据结构，
//包含一个 adj 表示顶点之间是否有边相连，
//以及一个 info 指针，指向与该边相关的信息。
//adjmatrix_hc : 邻接矩阵类型，是一个二维数组，用于存储图的邻接矩阵。

typedef struct
{
	char vexs[MAX_VERTEX_NUM];
	adjmatrix_hc arcs;
	int vexnum, arcnum;
	graphkind_hc kind;
}mgraph_hc;

typedef struct arcnode_hc
{
	int adjvex;
	struct arcnode_hc* nextarc;
	int* info;
}arcnode_hc;

typedef struct vnode_hc
{
	char data;
	arcnode_hc* firstarc;
}vnode_hc, adjlist_hc[MAX_VERTEX_NUM];

typedef struct
{
	adjlist_hc vertices;
	int vexnum, arcnum;
	graphkind_hc kind;
}algraph_hc;

int locatevex_hc(mgraph_hc* g, char v)
{
	int i, k = 0;
	for (i = 0; i < g->vexnum; i++)
		if (g->vexs[i] == v) { k = i; i = g->vexnum; }
	return(k);
}

mgraph_hc* createudg_hc()
{
	mgraph_hc* g;
	char v1, v2;
	int i, j, incinfo;
	g = (mgraph_hc*)malloc(sizeof(mgraph_hc));
	g->kind = UDG;
	printf("请输入图顶点数、边数及该边相关信息:");
	scanf("%d %d %d", &g->vexnum, &g->arcnum, &incinfo);
	printf("请输入顶点信息:"); flushall();
	for (i = 0; i < g->vexnum; ++i)scanf("%c", &g->vexs[i]);
	for (i = 0; i < g->vexnum; ++i)
		for (j = 0; j < g->vexnum; ++j)
			g->arcs[i][j].adj = 0;
	printf("输入一条边依附的顶点:\n");
	flushall(); scanf("%c%c", &v1, &v2);
	while (v1 != '#' && v2 != '#')
	{
		i = locatevex_hc(g, v1); j = locatevex_hc(g, v2);
		g->arcs[i][j].adj = 1;
		if (incinfo)g->arcs[i][j].info = &incinfo;
		g->arcs[j][i].adj = g->arcs[i][j].adj;
		g->arcs[j][i].info = g->arcs[i][j].info;
		flushall(); scanf("%c%c", &v1, &v2);
	}
	return(g);
}

visited_hc vis[MAX_VERTEX_NUM];

int firstadjvex_hc(mgraph_hc* g, int v)
{
	int i, k = -1;
	for (i = 0; i < g->vexnum; i++)
		if (g->arcs[v][i].adj == 1) { k = i; i = g->vexnum; }
	return(k);
}

int nextadjvex_hc(mgraph_hc* g, int v, int w)
{
	int i, k = -1;
	for (i = 0; i < g->vexnum; i++)
		if (g->arcs[v][i].adj == 1 && i > w) { k = i; i = g->vexnum; }
	return(k);
}

void dfs_hc(mgraph_hc* g, int v)
{
	int w;
	vis[v] = TRUE; printf("%c", g->vexs[v]);
	for (w = firstadjvex_hc(g, v); w >= 0; w = nextadjvex_hc(g, v, w))
		if (!vis[w])dfs_hc(g, w);
}

void dfstraverse_hc(mgraph_hc* g)
{
	int v, i; char f;
	for (v = 0; v < g->vexnum; v++)vis[v] = FALSE;
	printf("输入遍历开始顶点:"); flushall(); scanf("%c", &f);
	i = locatevex_hc(g, f); printf("深度遍历结果为:");
	for (v = i; v < g->vexnum; v++)if (!vis[v])dfs_hc(g, v);
	for (v = 0; v < i; v++)if (!vis[v])dfs_hc(g, v);
}

int locatevexal_hc(algraph_hc* a, char v)
{
	int i, k = 0;
	for (i = 0; i < a->vexnum; i++)
		if (a->vertices[i].data == v) { k = i; i = a->vexnum; }
	return(k);
}

char createlist_hc(algraph_hc* a, arcnode_hc* firstl, char v)
{
	arcnode_hc* nextl;
	if (v != '\n')
	{
		nextl = (arcnode_hc*)malloc(sizeof(arcnode_hc));
		nextl->adjvex = locatevexal_hc(a, v);
		nextl->nextarc = NULL; nextl->info = firstl->info;
		firstl->nextarc = nextl;
		scanf("%c", &v); v = createlist_hc(a, nextl, v);
	}
	return(v);
}

algraph_hc* createaludg_hc()
{
	algraph_hc* a; int i, incinfo; char v;
	a = (algraph_hc*)malloc(sizeof(algraph_hc));
	a->kind = UDG;
	printf("请输入图顶点数、边数及该边相关信息:");
	scanf("%d %d %d", &a->vexnum, &a->arcnum, &incinfo);
	printf("请输入顶点信息:"); flushall();
	for (i = 0; i < a->vexnum; ++i)scanf("%c", &a->vertices[i].data);
	for (i = 0; i < a->vexnum; ++i)
	{
		printf("输入%c的邻接点:", a->vertices[i].data);
		flushall(); scanf("%c", &v);
		a->vertices[i].firstarc = (arcnode_hc*)malloc(sizeof(arcnode_hc));
		a->vertices[i].firstarc->adjvex = locatevexal_hc(a, v);
		a->vertices[i].firstarc->nextarc = NULL;
		if (incinfo)a->vertices[i].firstarc->info = &incinfo;
		scanf("%c", &v); v = createlist_hc(a, a->vertices[i].firstarc, v);
	}
	return(a);
}

visited_hc vis[MAX_VERTEX_NUM];

void dfsal_hc(algraph_hc* a, arcnode_hc* b, int k)
{
	vis[k] = TRUE;
	printf("%c", a->vertices[k].data);
	while (b)
	{
		k = b->adjvex;
		if (!vis[k]) { b = a->vertices[k].firstarc; dfsal_hc(a, b, k); }
		else b = b->nextarc;
	}
}

void dfstraverseal_hc(algraph_hc* a)
{
	char f; int i = 0, k;
	for (i = 0; i < a->vexnum; i++)vis[i] = FALSE;
	printf("遍历开始顶点:"); flushall(); scanf("%c", &f);
	k = locatevexal_hc(a, f);
	printf("深度遍历结果:");
	for (i = k; i < a->vexnum; i++)
		if (!vis[k])dfsal_hc(a, a->vertices[i].firstarc, i);
	for (i = 0; i < k; i++)
		if (!vis[k])dfsal_hc(a, a->vertices[i].firstarc, i);
}

void main()
{
	algraph_hc* a; mgraph_hc* g;
	char c;
	printf("邻接矩阵(M)\n");
	printf("邻接表(A)\n");
	printf("请选择:");
	c = getchar();
	while (c != 'E')
	{
		if (c == 'M') { g = createudg_hc(); dfstraverse_hc(g); }
		else if (c == 'A') { a = createaludg_hc(); dfstraverseal_hc(a); }
		printf("\n请选择:"); flushall(); c = getchar();
	}
}

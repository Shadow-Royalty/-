#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // ���ͷ�ļ�

#define MAX_VERTEX_NUM 100 //ͼ����󶥵���


//struct ArcNode* nextarc;
//ArcNode* firstarc;
//�������Ǻ��б�Ҫ�ģ������û��������ָ�룬����޷��жϵ�ǰ�Ķ�������һ��
// adj���ڽӵ㣬firstarc��nextarc�ֱ����ǰ����һ���㡣

//ͼ���ڽӱ�洢�ṹ����
typedef struct ArcNode {
    int adjvex;              //�ڽӵ��������е�λ���±�
    struct ArcNode* nextarc; //ָ����һ���ڽӵ��ָ��
} ArcNode;

typedef struct VNode {
    char data;             //������Ϣ
    ArcNode* firstarc;     //ָ���һ���ڽӵ��ָ��
} VNode, AdjList[MAX_VERTEX_NUM];

//ʹ�ýṹ��Ƕ�׵ķ�ʽ�����������㻹�б߶���Ƕ������

typedef struct {
    AdjList vertices;      //�ڽӱ�Ҳ���Ƕ������˼
    int vexnum, arcnum;    //�������ͻ���
    bool is_directed;      //�Ƿ�������ͼ
} ALGraph;

//���Ҷ���ĵ�һ���ڽӵ�
int FirstAdjVex(ALGraph G, int v)
{
    if (G.vertices[v].firstarc != NULL) {
        return G.vertices[v].firstarc->adjvex;
    }
    else {
        return -1;  //���ء��ա�
    }
}

//���Ҷ������һ���ڽӵ�


int NextAdjVex(ALGraph G, int v, int w)
{
    ArcNode* p = G.vertices[v].firstarc;
    while (p != NULL && p->adjvex != w) {
        p = p->nextarc;
    }
    //���ҵ�w�ȣ���Ŀ˵�����w����һ���ڽӵ�

    if (p != NULL && p->nextarc != NULL) {
        return p->nextarc->adjvex;
    }
    else {
        return -1;  //���ء��ա�
    }
}

//v��ͼ�е�ĳ������Ҳ���� ArcNode* p����G.vertices[v].firstarc;
//��p->adjvex != w����v��ǰ���ڽӵ�
//����һ���ڽӵ���Ȼ���� p->nextarc->adjvex��

//һ��ڵ����һ���ڵ��ֻ��һ����
// ����DFS����һֱ�������ң���һ���͵����ˣ�����˵�Ǻ����ѭ����
//��Ŀ����˼����˵��w��v���ٽӽڵ㡣

//����һ���¶���
void InsertVex(ALGraph* G, char v)
{
    if (G->vexnum >= MAX_VERTEX_NUM) {
        printf("Error: The graph is full!\n");
        return;
    }
    G->vertices[G->vexnum].data = v;//��ŵ�
    G->vertices[G->vexnum].firstarc = NULL;//������ڽӵ�
    G->vexnum++;
}

//ɾ��һ�����㼰����صĻ�
void DeleteVex(ALGraph* G, char v)
{
    int i, j;
    ArcNode* p, * q;
    i = LocateVex(*G, v);//�ҵ�����λ��
    if (i == -1) {
        printf("Error: Vertex not found!\n");
        return;
    }
    //ɾ����ö�����صĻ�
    for (j = 0; j < G->vexnum; j++) {
        p = G->vertices[j].firstarc;//Ѱ��ÿ��ͼ�е����еĵ�һ���ڽӵ㡣
        while (p != NULL) {
            if (p->adjvex == i) {
                //����ڽӵ��Ǹ��±�ĵ�
                q = p->nextarc;
 //��Ϊ�ǵ�һ���ڽӵ㣬����������ǰ������⣬����ֱ�ӽ�������һ�ξ�����
                free(p);
                G->arcnum--;
                p = q;
               
            }
            else {
                //ָ��Ҫ����ֻ���ڽӵ�Ϊi�ĵ�
                //��������ĵ㣬ֱ���±���ǰ��һλ������
                if (p->adjvex > i) {
                    p->adjvex--;
                    //�����Ѿ���ȷ������Ҫɾ��i�㣬
                    // ��ô�������е��ڽӵ��±�λ�ö�Ҫ��ǰ��1λ
                    //��ΪҪɾ��i���ˣ���ô���еĵ��λ�ö�Ҫ�����仯��������������
                    //ɾ��һ��Ԫ�أ�ȫ��Ԫ�ض�Ҫ��ǰ�ƶ���

                    //����ǰ��� if (p->adjvex == i) 
                    //������Ϊֱ�ӽ�p��ֱ��ɾ���ˣ���Ȼ�Ͳ���Ҫ�ٹ�����λ����������
                }
                p = p->nextarc;//���������ң��ظ���ǰ������
            }

 //           ����δ����У�adjvex���Ա�ʾһ������ָ��Ķ�����ͼ�е�����λ�á�
 //          ��ɾ����ָ��������صĻ�ʱ����������е�����
 //               ��Щλ��ָ������֮��Ķ����������ᷢ���仯��
 //ͨ����pָ��Ļ���adjvex���Լ�1������ȷ������֮��ı�������ԡ�
 //               Ҳ����˵��ɾ��һ������֮��
 //               ��֮��Ķ������������Ҫ����1���Ա��ֶ�Ӧ��ϵ����ȷ�ԡ�
 //              

 //               ���磬����ԭ������i֮��Ķ���ֱ�Ϊi + 1��i + 2��i + 3��
 //               ɾ���붥��i��صĻ�֮��i + 1�����i��i + 2�����i + 1��i + 3�����i + 2���Դ����ơ�

 //               ��������Ŀ����Ϊ����ɾ������֮��
 //               ��Ȼ����ͨ���������������ȷ���ʺͲ���ͼ���ڽ���Ϣ��
        }
    }

    //ɾ���ö��㱾��
    //���������ǲ�һ���ĸ���
    for (j = i + 1; j < G->vexnum; j++) {
        G->vertices[j - 1] = G->vertices[j];
    }
    for (j = 0; j < G->vexnum; j++) {
        p = G->vertices[j].firstarc;
        while (p != NULL) {
            if (p->adjvex > i) {
                p->adjvex--;
            }
            p = p->nextarc;
        }
    }
    G->vexnum--;


      //  ��һ��ѭ������ɾ����ָ��������صĻ�ʱ���еġ�
      //���ҵ��ڽӵ���������ڱ�ɾ�����������ʱ�������1���Ա��ֶ���֮��ı�������ԡ�

      //  �ڶ���ѭ������ɾ�����㱾�����еġ�����ÿ�����㣬
      //      �������ڽ���������ڽӵ���������ڱ�ɾ�������������
      //      �����1��ͬ����Ϊ�˱����ڽ���Ϣ����ȷ�ԡ�

      //  ������ѭ����Ŀ�Ķ���ʹ��ɾ��һ�������
      //      �������������������Ӧ�仯����ȷ�������ķ��ʺͲ�����Ȼ��Ч��

}

//�ڽӱ��ʾ��ǰ������
//��֧�����κ�һ����һ���Ķ��㡣
//
//��ÿһ�ζ�ָ��ָ����һ��Ȼ��ɾ��ԭ�ȵ�p�ڵ㡣
//Ҳ�͵��ڶϿ��������뵱ǰ�ڵ�����ӣ�
//Ҳ�ͳɹ��������������л��ˡ�

//����һ���»�
void InsertArc(ALGraph* G, char v, char w)
{
    int i, j;
    ArcNode* p, * q;
    i = LocateVex(*G, v);
    j = LocateVex(*G, w);
    if (i == -1 || j == -1) {
        printf("Error: Vertex not found!\n");
        return;
    }
    p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = j;//�ڽӵ���j
    p->nextarc = G->vertices[i].firstarc;//��Ϊ�ǲ��룬������next����first
    G->vertices[i].firstarc = p;
    //p������ G->vertices[i].firstarc
    //������Ϊp�л���adj���j��ֵ��
    /*����Ϊ�˲����»��Ŵ��� G->vertices[i].firstarc��*/
        //����˵ԭ��ַ�� G->vertices[i].firstarc��������p�ͳɹ������ˡ�
    //p���µ�ͷ��㣬����ԭ���ĵ�ַ�ĳ�p��ָ��ûë��

  /*  ���ȣ�p->nextarc = G->vertices[i].firstarc; 
    ��p����һ��ָ��ָ�򶥵�i��ԭ��һ���ڽӱߣ�����p�ͳ�Ϊ���µĵ�һ���ڽӱߡ�

        Ȼ��G->vertices[i].firstarc = p;
    ������i�ĵ�һ���ڽӱ�ָ��ָ��p����p��Ϊ�˶���i�ڽӱ���µĵ�һ���ڵ㡣*/

  /*  ������ָ��ƫ���ˣ����ס���䶯�����Ժ�һ��Ҫ��ָ���ͷָ���µ�ͷ��㣬��Ȼȫ�������ˣ�*/

    G->arcnum++;
    if (!G->is_directed) {
        q = (ArcNode*)malloc(sizeof(ArcNode));
        q->adjvex = i;
        q->nextarc = G->vertices[j].firstarc;
        G->vertices[j].firstarc = q;
        G->arcnum++;
    }
}
//p->adjvex  ����ĩ�˵ĵ�
//G->vertices[i].firstarc;  ����ǰ�˵ĵ�

//�ʣ�p->nextarc = G->vertices[i].firstarc; Ϊʲô��ֱ��д��p = G->vertices[i].firstarc;?

//������ΪG->vertices[i].firstarc��һ��ָ��߱�ṹ���ָ�룬
//��p��һ��ָ��߱�ṹ���ָ�������
//���������ֱ�Ӹ�ֵ���ᵼ��p��G->vertices[i].firstarcָ��ͬһ���ڴ�����
//�κ�һ���Ը��ڴ�������޸Ķ���Ӱ����һ��������ܲ������������Ľ����
//
//��ȷ����������pָ����G->vertices[i].firstarc��ͬ���ڴ��ַ��
//����������������ͬ��ָ����������������������һ��ָ��������޸Ĳ���Ӱ����һ����
//����Ӧ��д��p->nextarc = G->vertices[i].firstarc��
//�������Ա�֤pָ����G->vertices[i].firstarc��ͬ���ڴ��ַ��
//����������������ͬ��ָ����������������������һ��ָ��������޸Ĳ���Ӱ����һ����

//�ܽ�:ָ������������⣬ֱ�Ӹ�ֵ�ͱ�ʾָ��ͬһ���ص㣬pָ��͵�����ָ���Ŀ��ĵ�ַ��
//���������޸�pҲ�͵����޸���ԭ��ַ��ֵ�����Ա���Ҫ��next���ܳ�Ϊ������ָ�롣
//�൱����ֻ��ʹ����ԭ��ַ��ֵ����������Ϊ������һ������


//ɾ��һ����
void DeleteArc(ALGraph* G, char v, char w)
{
    int i, j;
    ArcNode* p, * q;
    i = LocateVex(*G, v);
    j = LocateVex(*G, w);
    if (i == -1 || j == -1) {
        printf("Error: Vertex not found!\n");
        return;
    }
    p = G->vertices[i].firstarc;//����㿪ʼ��
    q = NULL;
    while (p != NULL && p->adjvex != j) {
        q = p;
        //ΪʲôҪ����ǰ��Ķ��㣿
        //Ϊ�˴���ǰ��������,��������νӡ�
        p = p->nextarc;
    }
    if (p != NULL) {
        if (q == NULL) {
            G->vertices[i].firstarc = p->nextarc; 
            //ֻ��һ��������
        }
       
        else {
            q->nextarc = p->nextarc;
        }
        free(p);
        G->arcnum--;
    }
    if (!G->is_directed) {
        p = G->vertices[j].firstarc;
        q = NULL;
        while (p != NULL && p->adjvex != i) {
            q = p;
            p = p->nextarc;
        }
        if (p != NULL) {
            if (q == NULL) {
                G->vertices[j].firstarc = p->nextarc;
            }
            else {
                q->nextarc = p->nextarc;
            }
            free(p);
            G->arcnum--;
        }
    }
}

//��λĳ�������λ��
int LocateVex(ALGraph G, char v)
{
    int i;
    for (i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == v) {
            return i;
        }
    }
    return -1;  //δ�ҵ�
}

int main()
{
    ALGraph G;
    G.is_directed = false;  // ����ͼΪ����ͼ
    G.vexnum = 0;
    G.arcnum = 0;

    InsertVex(&G, 'A');
    InsertVex(&G, 'B');
    InsertVex(&G, 'C');
    InsertVex(&G, 'D');

    InsertArc(&G, 'A', 'B');
    InsertArc(&G, 'A', 'C');
    InsertArc(&G, 'B', 'D');
    InsertArc(&G, 'C', 'D');

    printf("The first adjacent vertex of A is %c\n", G.vertices[0].firstarc->adjvex + 'A');
    printf("The next adjacent vertex of A after B is %c\n", NextAdjVex(G, 0, LocateVex(G, 'B')) + 'A');

    DeleteArc(&G, 'B', 'D');
    DeleteVex(&G, 'C');

    return 0;
}

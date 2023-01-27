//
// Created by 徐朝阳 on 2022/8/18.
//
//对邻接表表示的图进行深度遍历和广度遍历
/*解题思路:深度优先遍历是递归，广度优先遍历用队列，二者类比树中的先序遍历和树的广度优先遍历(层次遍历)。
 * 为了消除邻接矩阵和邻接表写出来后的差异性，为两种图的表示方式分别构造 firstNeighbor()和 nextNeighbor() 函数。
 * 每执行一次 dfs(bfs)相当于遍历了图中的一个连通分量，visited[]数组保证 了每个结点只被访问一次。
 */
//无向图的极大连通子图————连通分量
//有向图的极大连通子图————强连通分量，每对顶点都强连通————强连通图

#include "iostream"
#define maxVertices 10
using namespace std;
//边结点结构声明
struct EdgeNode{
    int val;
    struct EdgeNode *next;//链接下一条边
};
//顶点结构声明
struct VertexNode{
    int val;
    struct EdgeNode *first;//边链表头指针（一直指第一个）；通过边链接后面结点
};

struct ALGraph{
    VertexNode VerticesList[maxVertices];//邻接表的顶点数组
    int numVertices;//顶点数
    int numEdges;//边数
};

//与顶点V相邻的第一个结点的下标
int firstNeighbor(ALGraph &G,int v){
    if (G.VerticesList[v].first != NULL)//判断图非空
        return G.VerticesList[v].first->val;
    else
        return -1;
}
//顶点v除w顶点外的下一个相邻结点的下标
int nextNeighbor(ALGraph &G ,int v ,int w ){
    EdgeNode *p = G.VerticesList[v].first;
    //找到w顶点
    while (p != NULL && p->val != w) p = p->next;
    //如果w后还有顶点就返回
    if (p != NULL && p->next != NULL)
        return p->next->val;
    else
        return -1;
}

//深度优先遍历一个连通分量，把与v连接的都访问完
void dfs(ALGraph &G ,int v ,int visited[]){
    cout << G.VerticesList[v].val << " ";
    visited[v] = 1;//标记已访问
    int w = firstNeighbor(G,v);
    while (w != -1){//w存在
        if (!visited[w])//w未访问
            dfs(G,w,visited);//访问w
        w = nextNeighbor(G,v,w);//w后的一个结点
    }
}
//深度遍历
void graphTraverse_dfs(ALGraph &G,int visited[]){
    //遍历所有顶点
    cout <<"开始深度遍历"<<endl;
    for (int i = 0; i < G.numVertices; i++) {
        if (!visited[i])//如果第i个顶点未访问
            dfs(G , i ,visited);
    }
}
//创建邻接表存储的图
void createGraph(ALGraph &G){
    cout<<"输入顶点数和边数："<<endl;
    cin >> G.numVertices >> G.numEdges ;//输入顶点数边数
    for (int i = 0; i < G.numVertices; i++) {
        cout<<"输入顶点名称："<<endl;
        cin >> G.VerticesList[i].val;//顶点名称
        G.VerticesList[i].first = NULL;//边链表置空
    }
    for (int i = 0; i < G.numEdges; i++) {
        char tail ,head;//定义边
        cout<<"输入边(p,q)"<<endl;
        cin >> tail >> head;//输入边
        //创建一个新结点
        EdgeNode *p = new EdgeNode;
        p->val = head;
        //寻找tail对应顶点
        int temp;
        for (int i = 0; i < G.numVertices; i++) {
            if (G.VerticesList[i].val == tail)
                temp = i ;
        }
        //头插法插入新结点
        p->next = G.VerticesList[temp].first;
        G.VerticesList[temp].first = p;
    }
}
int main(){
    ALGraph G;
/*
5
4
0 1 2 3 4
0 1
1 2
2 3
3 4
*/
    int visited[5] = {0};
    createGraph(G);
    graphTraverse_dfs(G,visited);
}



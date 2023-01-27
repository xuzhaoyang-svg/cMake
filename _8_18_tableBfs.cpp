//
// Created by 徐朝阳 on 2022/8/18.
//
//邻接表存储的图进行广度遍历
#include "iostream"
#include "queue"
#define maxVertices 10
using namespace std;
//定义边结构
struct EdgeNode{
    int val;
    struct EdgeNode *next;
};
//定义顶点结构
struct VertexNode{
    int val;
    struct EdgeNode *first;
};
//定义图结构
struct ALGraph{
    VertexNode VerticesList[maxVertices];
    int numVertices;
    int numEdges;
};
//创建图
void createGraph(ALGraph &G){
    cin >> G.numVertices >> G.numEdges;//输入顶点数，边数
    //给顶点赋值
    for (int i = 0; i < G.numVertices; i++) {
        cin >> G.VerticesList[i].val;
        G.VerticesList[i].first = NULL;
    }
    //创建边
    for (int i = 0; i < G.numEdges; i++) {
        char tail ,head;
        cin >> tail >> head;
        //创建新结点head
        EdgeNode *p = new EdgeNode;
        p->val = head;
        //看tail在顶点表中没
        int temp;
        for (int i = 0; i < G.numVertices; i++) {
            if (G.VerticesList[i].val == tail)
                temp = i;
        }
        //头插法
        p->next = G.VerticesList[temp].first;
        G.VerticesList[temp].first = p;

    }
}
//与顶点V相邻的第一个结点的下标
int firstNeighbor(ALGraph &G,int v){
    if (G.VerticesList[v].first != NULL)//v这个顶点存在顶点表中
        return G.VerticesList[v].first->val;//返回与v相连的第一个顶点
    else
        return -1;
}
//顶点v除w顶点外的下一相邻结点的下标
int nextNeighbor(ALGraph &G,int v,int w){
    EdgeNode *p = G.VerticesList[v].first;
    //找到w位置
    while (p != NULL && p->val != w) p = p->next;
    //如果w后还有非空顶点，则返回
    if (p != NULL && p->next != NULL)
        return p->next->val;
    else
        return -1;

}
//广度优先遍历一个连通分量
void bfs(ALGraph &G,int v,int visited[]){
    cout << G.VerticesList[v].val <<" ";
    visited[v] = 1;
    queue<int>(q);
    q.push(v);
    while (!q.empty()){
        v = q.front();
        q.pop();
        int w = firstNeighbor(G,v);
        while (w != -1){//w存在
            if (!visited[w])//w未访问
            {
                cout << G.VerticesList[w].val << " ";
                visited[w] = 1;//标记访问
                q.push(w);
            }
            w = nextNeighbor(G,v,w);
        }
    }
}
//广度优先遍历
void graphTraverse_bfs(ALGraph &G,int visited[]){
    for (int i = 0; i < G.numVertices; i++) {
        if (!visited[i])
            bfs(G,i,visited);
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
    graphTraverse_bfs(G,visited);
}



//
// Created by 徐朝阳 on 2022/8/5.
//
//编写算法，由依次输入的顶点数，弧数和各顶点信息、弧信息建立有向图的邻接表存储结构。
#include<iostream>
using namespace std;
#define maxVertices 10

//边表结点
struct EdgeNode{ //边结点结构声明
    char val;
    struct EdgeNode* next; //链接下一条边
};

//顶点结点
struct VertexNode{ //顶点结点结构声明
    char val;
    struct EdgeNode* first;//边链表头指针
};

//ALGraph是以邻接表存储的图类型
struct ALGraph{ //邻接表结构声明
    VertexNode VerticesList[maxVertices]; //邻接表的顶点数组
    int numVertices; //顶点数
    int numEdges; //边数
};
//每输入一条边(p,q)，创建一个值为 q 新结点，将它以头插法的方式插入到顶点 p 对应的边链表中。其中由 p 值寻找对应顶点数组的下标涉及一个查找问题。
void createGraph(ALGraph& G){
    cout<<"输入顶点数和边数："<<endl;
    cin >> G.numVertices >> G.numEdges; //输入顶点数和边数

    //建立顶点表
    for(int i = 0; i < G.numVertices; i ++){
        cout<<"输入顶点名称："<<endl;
        cin >> G.VerticesList[i].val; //顶点名称
        G.VerticesList[i].first = NULL; //边链表置空
    }

    //建立边表
    for(int i = 0; i < G.numEdges; i ++){
        char tail,head; //定义边
        cout<<"输入边(p,q)"<<endl;
        cin >> tail >> head; //输入边
        EdgeNode* p = new EdgeNode;
        p->val = head;
        //寻找tail对应顶点
        int temp;
        for(int i = 0;i < G.numVertices; i ++)
            if(G.VerticesList[i].val == tail)
                temp = i;
        //头插法插入边结点
        p->next = G.VerticesList[temp].first;//P结点插到前面
        G.VerticesList[temp].first = p;//P结点设为第一个结点
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
    createGraph(G);
}



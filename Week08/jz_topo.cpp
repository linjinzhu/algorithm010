/***************************************************************************
:*
* Copyright (c) 2020 zhuzige studio , Inc. All Rights Reserved
*
* Author : linjinzhu
**************************************************************************/

#ifndef DESIGN_MODAL_TOPO
#define DESIGN_MODAL_TOPO

#include <list>
#include <queue>
#include <iostream>

using namespace std;

class Graph
{
private:
    int v;          // 顶点数量
    int *indegree;  // 每个顶点的入度
    list<int> *adj; // 每个顶点的邻接点
    queue<int> q;   // 入度为0的顶点集合
public:

    Graph(int v);
    ~Graph();

    // 添加边
    void add_edge(int v, int w);
    // 拓扑排序
    bool sort();
};

Graph::Graph(int v)
{
    this->v = v;

    // 初始化邻接顶点
    this->adj = new list<int>[v];

    // 初始化入度，每个顶点入度初始化为0
    this->indegree = new int[v];
    for (size_t i = 0; i < v; i++) {
        indegree[i] = 0;
    }
}

Graph::~Graph()
{
    delete [] adj;
    delete [] indegree;
}

void Graph::add_edge(int v, int w) {
    // 更新入度
    ++indegree[w];
    // 更新邻接表
    adj[v].push_back(w);
}

bool Graph::sort() {
    // 记录入度为0的顶点
    for (size_t i = 0; i < this->v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 记录取出的顶点数量
    int count = 0;
    // 每次pop一个入度为0的顶点，并加入新的入度为0的顶点
    while (!q.empty()) {
        // 取出一个顶点
        int vertex = q.front();
        q.pop();

        count++;

        std::cout << vertex << " ";

        // 遍历顶点的邻接点，并将邻接点的入度减一
        list<int>::iterator adj_iter = adj[vertex].begin();
        for (; adj_iter != adj[vertex].end(); adj_iter++) {
            // 入度为零，放入队列
            int adj_indegree = --indegree[*adj_iter];
            if (adj_indegree == 0) {
                q.push(*adj_iter);
            }
        }
    }

    if (count == v) {
        return true;
    }
    
    return false;
}

int main(int argc, char const *argv[])
{
    Graph g(8);
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 2);
    g.add_edge(2, 4);
    g.add_edge(1, 5);
    g.add_edge(1, 6);
    g.add_edge(1, 7);

    g.sort();

    return 0;
}

#endif //DESIGN_MODAL_TOPO

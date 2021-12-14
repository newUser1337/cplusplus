#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <list>
#include <queue>

class Graph
{
private:
    std::map<int, std::vector<int>> Nodes;
    int size;

    void Dfs_rec(int, int *);
    void Dfs(std::stack<int> *, int *);
    void Bfs(std::queue<int> *, int *);
    void DirectCycle(int, std::list<int> *, std::list<int> *, std::list<int> *, bool *);
    bool FindEl(std::list<int> *, int);
    void Cycle(int, int, int *, bool *);
    void Component(std::map<int, std::vector<int>> *, int *);
    void Component_rec(std::map<int, std::vector<int>>::iterator, std::vector<int> *, int *);

public:
    Graph();

    void AddVertex(int);
    void SetConnections(int, int);
    void SetDirectConnections(int, int);

    void Dfs_rec(int);
    void Dfs(int);
    void Bfs(int);

    bool DirectCycle();
    bool Cycle(int);

    void Component(std::map<int, std::vector<int>> *);

    std::map<int, std::vector<int>> *GetNodes();
    friend std::ostream &operator<<(std::ostream &, Graph &);
};

#endif
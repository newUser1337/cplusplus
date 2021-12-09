#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__

#include <iostream>
#include <list>
#include <queue>

class GNode
{
private:
    std::list<int> connections;
    int index;

public:
    GNode(int in_index) : index(in_index){};
    ~GNode();
    int GetIndex() const;
    std::list<int> *GetConnections();
    bool FindConnection(int);
    void PrintIndex();

    void SetConnect(int);
    friend std::ostream &operator<<(std::ostream &, GNode &);
    bool operator==(int);
    int operator-(int);
};

class Graph
{
private:
    std::list<GNode *> set;
    GNode *CreateNode(int);
    int size;
    void _Dfs_rec(int, int *);
    void _Dfs(int, std::stack<int> *, int *);
    void _Bfs(int, std::queue<int> *, int *);
    void _Cycle(int, int, int *, bool *);
    void _CycleDirect(std::list<int> *, std::list<int> *, std::list<int> *, int, bool *);
    bool _Search(std::list<int> *, int);
    void _Component(std::list<GNode *> *, std::list<GNode *>::iterator, int *);
    void _Component_rec(GNode *, std::list<int> *, int *);

public:
    Graph() : size(0){};
    ~Graph();
    GNode *FindNode(int);
    GNode *Add(int);
    std::list<GNode *> *GetNodes();
    bool SetConnection(int, int);
    bool SetDirectConnection(int, int);
    void Dfs_rec(int);
    void Dfs(int);
    void Bfs(int);
    bool Cycle(int);
    bool CycleDirect();
    void Component(std::list<GNode *> *);

    std::ostream &PrintGraph(std::ostream &s, std::list<GNode *> *in_Nodes);
    friend std::ostream &operator<<(std::ostream &, Graph &);
};

#endif
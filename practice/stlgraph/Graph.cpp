#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include "Graph.h"

Graph::Graph()
{
    size = 0;
}

std::map<int, std::vector<int>> *Graph::GetNodes()
{
    return &this->Nodes;
}

std::ostream &operator<<(std::ostream &s, Graph &graph)
{
    std::map<int, std::vector<int>> *Nodes = graph.GetNodes();
    std::map<int, std::vector<int>>::iterator Vertexes;
    std::vector<int>::iterator Con;
    for (Vertexes = Nodes->begin(); Vertexes != Nodes->end(); Vertexes++)
    {
        s << "Vertex: " << Vertexes->first << std::endl;
        s << "Connections: ";
        for (Con = Vertexes->second.begin(); Con != Vertexes->second.end(); Con++)
        {
            s << *Con << " ";
        }
        s << std::endl;
    }
    return s;
}

void Graph::AddVertex(int Vertex)
{
    if (Nodes.end() != Nodes.find(Vertex))
        return;
    std::vector<int> connections;
    Nodes.insert(make_pair(Vertex, connections));
    size++;
}

void Graph::SetConnections(int vertex_1, int vertex_2)
{
    std::map<int, std::vector<int>>::iterator Vert1 = Nodes.find(vertex_1);
    std::map<int, std::vector<int>>::iterator Vert2 = Nodes.find(vertex_2);
    if (vertex_1 == vertex_2 || Vert1 == Nodes.end() || Vert2 == Nodes.end())
        return;
    std::vector<int>::iterator v_connectios;
    for (v_connectios = Vert2->second.begin();
         v_connectios != Vert2->second.end(); v_connectios++)
        if (*v_connectios == vertex_1)
            return;

    Vert1->second.push_back(vertex_2);
    Vert2->second.push_back(vertex_1);
}

void Graph::SetDirectConnections(int vertex_1, int vertex_2)
{
    std::map<int, std::vector<int>>::iterator Vert1 = Nodes.find(vertex_1);
    std::map<int, std::vector<int>>::iterator Vert2 = Nodes.find(vertex_2);
    if (vertex_1 == vertex_2 || Vert1 == Nodes.end() || Vert2 == Nodes.end())
        return;
    std::vector<int>::iterator v_connectios;
    for (v_connectios = Vert2->second.begin();
         v_connectios != Vert2->second.end(); v_connectios++)
        if (*v_connectios == vertex_1)
            return;

    Vert1->second.push_back(vertex_2);
}

void Graph::Dfs_rec(int start_index)
{
    int isvisited[size];
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    if (Nodes.end() == Nodes.find(start_index))
        return;
    std::cout << "Dfs_rec: " << std::endl;
    Dfs_rec(start_index, isvisited);
    std::cout << std::endl;
}

void Graph::Dfs_rec(int cur, int *isvisited)
{
    if (isvisited[cur - 1])
        return;
    isvisited[cur - 1] = 1;
    std::cout << cur;
    std::vector<int> connections = Nodes.find(cur)->second;
    std::vector<int>::iterator iter;
    for (iter = connections.begin(); iter != connections.end(); iter++)
        Dfs_rec(*iter, isvisited);
}

void Graph::Dfs(int start_index)
{
    int isvisited[size];
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    if (Nodes.end() == Nodes.find(start_index))
        return;

    std::stack<int> st;
    st.push(start_index);
    std::cout << "Dfs: " << std::endl;
    Dfs(&st, isvisited);
    std::cout << std::endl;
}

void Graph::Dfs(std::stack<int> *st, int *isvisited)
{
    int vertex;
    while (!st->empty())
    {
        vertex = st->top();
        std::cout << vertex;
        st->pop();
        isvisited[vertex - 1] = 1;
        std::vector<int> connections = Nodes.find(vertex)->second;
        std::vector<int>::iterator iter;
        for (iter = connections.begin(); iter != connections.end(); iter++)
            if (!isvisited[*iter - 1])
            {
                isvisited[*iter - 1] = 1;
                st->push(*iter);
            }
    }
}

void Graph::Bfs(int start_index)
{
    int isvisited[size];
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    if (Nodes.end() == Nodes.find(start_index))
        return;
    std::queue<int> qu;
    qu.push(start_index);
    std::cout << "Bfs: " << std::endl;
    Bfs(&qu, isvisited);
    std::cout << std::endl;
}

void Graph::Bfs(std::queue<int> *qu, int *isvisited)
{
    int vertex;
    while (!qu->empty())
    {
        vertex = qu->front();
        std::cout << vertex;
        isvisited[vertex - 1] = 1;
        qu->pop();
        std::vector<int> connections = Nodes.find(vertex)->second;
        std::vector<int>::iterator iter;
        for (iter = connections.begin(); iter != connections.end(); iter++)
            if (!isvisited[*iter - 1])
            {
                isvisited[*iter - 1] = 1;
                qu->push(*iter);
            }
    }
}

bool Graph::DirectCycle()
{
    bool result = false;
    std::list<int> nots, in, done;
    std::map<int, std::vector<int>>::iterator iter;
    for (iter = Nodes.begin(); iter != Nodes.end(); iter++)
        nots.push_back(iter->first);
    while (!nots.empty())
        DirectCycle(nots.front(), &nots, &in, &done, &result);
    return result;
}

void Graph::DirectCycle(int cur, std::list<int> *nots, std::list<int> *in, std::list<int> *done, bool *result)
{
    if (FindEl(done, cur))
        return;
    if (FindEl(in, cur))
    {
        *result = true;
        return;
    }
    nots->remove(cur);
    in->push_back(cur);

    std::vector<int> connections = Nodes.find(cur)->second;
    std::vector<int>::iterator iter;
    for (iter = connections.begin(); iter != connections.end(); iter++)
        DirectCycle(*iter, nots, in, done, result);

    in->remove(cur);
    done->push_back(cur);
}

bool Graph::FindEl(std::list<int> *List, int value)
{
    std::list<int>::iterator iter;
    for (iter = List->begin(); iter != List->end(); iter++)
        if (*iter == value)
            return true;
    return false;
}

bool Graph::Cycle(int start_index)
{
    int isvisited[size];
    bool result = false;
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    if (Nodes.end() == Nodes.find(start_index))
        return false;
    Cycle(start_index, start_index, isvisited, &result);
    return result;
}

void Graph::Cycle(int cur, int prev, int *isvisited, bool *result)
{
    if (isvisited[cur - 1])
        return;
    isvisited[cur - 1] = 1;
    std::vector<int> connections = Nodes.find(cur)->second;
    std::vector<int>::iterator iter;
    for (iter = connections.begin(); iter != connections.end(); iter++)
    {
        if (isvisited[*iter - 1] && *iter != prev)
            *result = true;

        Cycle(*iter, cur, isvisited, result);
    }
}

void Graph::Component(std::map<int, std::vector<int>> *result)
{
    int isvisited[size];
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    Component(result, isvisited);
}

void Graph::Component(std::map<int, std::vector<int>> *result, int *isvisited)
{
    std::map<int, std::vector<int>>::iterator vertexes;
    for (vertexes = Nodes.begin(); vertexes != Nodes.end(); vertexes++)
    {
        if (!isvisited[vertexes->first - 1])
        {
            isvisited[vertexes->first - 1] = 1;
            std::vector<int> connections;
            connections.push_back(vertexes->first);

            Component_rec(vertexes, &connections, isvisited);

            result->insert(make_pair(vertexes->first, connections));
        }
    }
}

void Graph::Component_rec(std::map<int, std::vector<int>>::iterator vertex, std::vector<int> *connection, int *isvisited)
{
    std::vector<int>::iterator iter;
    for (iter = vertex->second.begin(); iter != vertex->second.end(); iter++)
        if (!isvisited[*iter - 1])
        {
            isvisited[*iter - 1] = 1;
            connection->push_back(*iter);
            Component_rec(Nodes.find(*iter), connection, isvisited);
        }
}
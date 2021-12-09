#include <cstdlib>
#include <iostream>
#include <list>
#include <algorithm>
#include <stack>
#include "Graph.h"

GNode::~GNode()
{
}

int GNode::GetIndex() const
{
    return index;
}

std::list<int> *GNode::GetConnections()
{
    return &this->connections;
}

std::ostream &operator<<(std::ostream &s, GNode &node)
{
    std::list<int> *templ = node.GetConnections();
    std::list<int>::iterator iter;
    s << "Node: " << node.GetIndex() << std::endl
      << "Connections: ";
    for (iter = templ->begin(); iter != templ->end(); iter++)
        s << *iter << " ";
    s << std::endl;

    return s;
}

void GNode::SetConnect(int in_index)
{
    std::list<int>::iterator iter;
    for (iter = connections.begin(); iter != connections.end(); iter++)
        if (*iter == in_index)
            return;
    connections.push_back(in_index);
}

bool GNode::operator==(int in_index)
{
    return (index == in_index) ? true : false;
}

int GNode::operator-(int value)
{
    return index - value;
}

bool GNode::FindConnection(int in_index)
{
    if (in_index == index)
        return true;
    std::list<int>::iterator iter;
    for (iter = connections.begin(); iter != connections.end(); iter++)
        if (*iter == in_index)
            return true;
    return false;
}

void GNode::PrintIndex()
{
    std::cout << index << " ";
}

Graph::~Graph()
{
    std::list<GNode *>::iterator iter;
    for (iter = set.begin(); iter != set.end(); iter++)
        delete *iter;
}

GNode *Graph::CreateNode(int in_index)
{
    GNode *node = new GNode(in_index);
    return node;
}

std::list<GNode *> *Graph::GetNodes()
{
    return &this->set;
}

GNode *Graph::FindNode(int in_index)
{
    std::list<GNode *>::iterator iter;
    for (iter = set.begin(); iter != set.end(); iter++)
        if (**iter == in_index)
            return *iter;
    return NULL;
}

GNode *Graph::Add(int in_index)
{
    GNode *node = FindNode(in_index);
    if (node != NULL)
        return node;
    node = CreateNode(in_index);
    set.push_back(node);
    size++;
    return node;
}

std::ostream &operator<<(std::ostream &s, Graph &graph)
{

    // std::list<GNode *> *Nodes = graph.GetNodes();
    // std::list<GNode *>::iterator iter;
    // for (iter = Nodes->begin(); iter != Nodes->end(); iter++)
    //     s << **iter;

    return graph.PrintGraph(s, graph.GetNodes());
}

std::ostream &Graph::PrintGraph(std::ostream &s, std::list<GNode *> *in_Nodes)
{
    // std::list<GNode *> *Nodes = graph.GetNodes();
    std::list<GNode *>::iterator iter;
    for (iter = in_Nodes->begin(); iter != in_Nodes->end(); iter++)
        s << **iter;
    return s;
}

bool Graph::SetConnection(int index_1, int index_2)
{
    GNode *node_1 = FindNode(index_1);
    GNode *node_2 = FindNode(index_2);
    if (node_1 == NULL || node_2 == NULL || index_1 == index_2)
        return false;
    if (node_1->FindConnection(index_2))
        return false;
    node_1->SetConnect(index_2);
    node_2->SetConnect(index_1);
    return true;
}

bool Graph::SetDirectConnection(int index_1, int index_2)
{
    GNode *node_1 = FindNode(index_1);
    GNode *node_2 = FindNode(index_2);
    if (node_1 == NULL || node_2 == NULL || index_1 == index_2)
        return false;
    if (node_1->FindConnection(index_2))
        return false;
    node_1->SetConnect(index_2);
    return true;
}

void Graph::Dfs_rec(int start_index)
{
    GNode *node = FindNode(start_index);
    if (node == NULL)
    {
        std::cout << "Node doesn't exist" << std::endl;
        return;
    }
    int isvisited[size];
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    std::cout << "Dfs_rec" << std::endl;
    _Dfs_rec(start_index, isvisited);
    std::cout << std::endl;
}

void Graph::_Dfs_rec(int cur, int *isvisited)
{
    if (isvisited[cur - 1])
        return;
    isvisited[cur - 1] = 1;
    GNode *node = FindNode(cur);
    node->PrintIndex();

    std::list<int> *connect = node->GetConnections();
    std::list<int>::iterator iter;
    for (iter = connect->begin(); iter != connect->end(); iter++)
        if (!isvisited[*iter - 1])
            _Dfs_rec(*iter, isvisited);
}

void Graph::Dfs(int start_index)
{
    GNode *node = FindNode(start_index);
    if (node == NULL)
    {
        std::cout << "Node doesn't exist" << std::endl;
        return;
    }
    int isvisited[size];
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    std::cout << "Dfs" << std::endl;
    std::stack<int> qu;
    _Dfs(start_index, &qu, isvisited);
    std::cout << std::endl;
}

void Graph::_Dfs(int cur, std::stack<int> *qu, int *isvisited)
{
    isvisited[cur - 1] = 1;
    qu->push(cur);
    while (!qu->empty())
    {
        cur = qu->top();
        GNode *node = FindNode(cur);
        node->PrintIndex();
        qu->pop();

        std::list<int> *connect = node->GetConnections();
        std::list<int>::iterator iter;
        for (iter = connect->begin(); iter != connect->end(); iter++)
            if (!isvisited[*iter - 1])
            {
                qu->push(*iter);
                isvisited[*iter - 1] = 1;
            }
    }
}

void Graph::Bfs(int start_index)
{
    GNode *node = FindNode(start_index);
    if (node == NULL)
    {
        std::cout << "Node doesn't exist" << std::endl;
        return;
    }
    int isvisited[size];
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    std::cout << "Bfs" << std::endl;
    std::queue<int> qu;
    _Bfs(start_index, &qu, isvisited);
    std::cout << std::endl;
}

void Graph::_Bfs(int cur, std::queue<int> *qu, int *isvisited)
{
    isvisited[cur - 1] = 1;
    qu->push(cur);
    while (!qu->empty())
    {
        cur = qu->front();
        GNode *node = FindNode(cur);
        node->PrintIndex();
        qu->pop();
        std::list<int> *connect = node->GetConnections();
        std::list<int>::iterator iter;
        for (iter = connect->begin(); iter != connect->end(); iter++)
            if (!isvisited[*iter - 1])
            {
                qu->push(*iter);
                isvisited[*iter - 1] = 1;
            }
    }
}

bool Graph::Cycle(int start_index)
{
    GNode *node = FindNode(start_index);
    if (node == NULL)
    {
        std::cout << "Node doesn't exist" << std::endl;
        return false;
    }
    int isvisited[size];
    bool result = false;
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    std::cout << "Cycle" << std::endl;
    _Cycle(start_index, start_index, isvisited, &result);
    return result;
}

void Graph::_Cycle(int cur, int prev, int *isvisited, bool *result)
{
    if (isvisited[cur - 1])
        return;
    isvisited[cur - 1] = 1;
    GNode *node = FindNode(cur);
    std::list<int> *Connections = node->GetConnections();
    std::list<int>::iterator iter;
    for (iter = Connections->begin(); iter != Connections->end(); iter++)
    {
        if (isvisited[*iter - 1] && *iter != prev)
            *result = true;
        if (!isvisited[*iter - 1])
            _Cycle(*iter, cur, isvisited, result);
    }
}

bool Graph::CycleDirect()
{
    bool result = false;
    std::list<int> nots;
    std::list<int> in;
    std::list<int> done;

    std::list<GNode *>::iterator iter;
    for (iter = set.begin(); iter != set.end(); iter++)
        nots.push_front(((GNode *)*iter)->GetIndex());

    while (!nots.empty())
        _CycleDirect(&nots, &in, &done, nots.front(), &result);
    return result;
}

void Graph::_CycleDirect(std::list<int> *nots, std::list<int> *in, std::list<int> *done, int cur, bool *result)
{
    if (_Search(in, cur))
    {
        *result = true;
        return;
    }
    if (_Search(done, cur))
        return;

    in->push_back(cur);
    nots->remove(cur);

    GNode *node = FindNode(cur);
    std::list<int> *Connections = node->GetConnections();
    std::list<int>::iterator iter;
    for (iter = Connections->begin(); iter != Connections->end(); iter++)
        _CycleDirect(nots, in, done, *iter, result);

    in->remove(cur);
    done->push_back(cur);
}

bool Graph::_Search(std::list<int> *List, int value)
{
    std::list<int>::iterator iter;
    for (iter = List->begin(); iter != List->end(); iter++)
        if (*iter == value)
            return true;
    return false;
}

void Graph::Component(std::list<GNode *> *result)
{
    int isvisited[size];
    for (int i = 0; i < size; i++)
        isvisited[i] = 0;
    std::list<GNode *>::iterator iter;
    iter = set.begin();
    _Component(result, iter, isvisited);
}

void Graph::_Component(std::list<GNode *> *result, std::list<GNode *>::iterator iter, int *isvisited)
{
    if (iter == set.end())
        return;
    GNode *node = *iter;
    if (!isvisited[*node - 1])
    {
        GNode *newNode = CreateNode(node->GetIndex());

        isvisited[*newNode - 1] = 1;
        result->push_front(newNode);
        newNode->GetConnections()->push_front(newNode->GetIndex());

        _Component_rec(node, newNode->GetConnections(), isvisited);
    }
    _Component(result, ++iter, isvisited);
}

void Graph::_Component_rec(GNode *root, std::list<int> *Connect, int *isvisited)
{
    std::list<int> *Tepmpl = root->GetConnections();
    std::list<int>::iterator iter;

    for (iter = Tepmpl->begin(); iter != Tepmpl->end(); iter++)
        if (!isvisited[*iter - 1])
        {
            isvisited[*iter - 1] = 1;
            Connect->push_front(*iter);
            _Component_rec(FindNode(*iter), Connect, isvisited);
        }
}
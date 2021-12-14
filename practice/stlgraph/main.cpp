#include <iostream>
#include <map>
#include <vector>
#include "Graph.h"

int main()
{
    Graph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddVertex(5);
    graph.AddVertex(6);
    graph.AddVertex(7);
    graph.AddVertex(8);
    graph.SetConnections(7, 1);
    graph.SetConnections(7, 2);
    graph.SetConnections(2, 3);
    graph.SetConnections(2, 4);
    graph.SetConnections(3, 5);
    // graph.SetConnections(3, 4);
    graph.SetConnections(4, 6);
    graph.SetConnections(5, 6);
    graph.SetConnections(8, 6);
    std::cout << graph;

    graph.Dfs_rec(2);
    graph.Dfs(2);
    graph.Bfs(2);
    if (graph.Cycle(2))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    return 0;
}
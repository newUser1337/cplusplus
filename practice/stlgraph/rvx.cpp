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
    graph.SetDirectConnections(1, 2);
    graph.SetDirectConnections(1, 3);
    graph.SetDirectConnections(2, 3);
    graph.SetDirectConnections(4, 1);
    graph.SetDirectConnections(5, 4);
    graph.SetDirectConnections(6, 5);
    graph.SetDirectConnections(4, 6);
    std::cout << graph;
    if (graph.DirectCycle())
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    return 0;
}
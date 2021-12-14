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
    graph.AddVertex(9);
    graph.AddVertex(10);
    graph.AddVertex(11);
    graph.AddVertex(12);
    graph.SetConnections(7, 1);
    graph.SetConnections(7, 2);
    graph.SetConnections(2, 3);
    graph.SetConnections(2, 4);
    graph.SetConnections(3, 5);
    graph.SetConnections(3, 4);
    graph.SetConnections(4, 6);
    graph.SetConnections(5, 6);
    graph.SetConnections(8, 6);
    graph.SetConnections(9, 10);
    graph.SetConnections(10, 11);
    std::cout << graph;

    std::map<int, std::vector<int>> component;
    graph.Component(&component);
    for (std::map<int, std::vector<int>>::iterator comp_iter = component.begin(); comp_iter != component.end(); comp_iter++)
    {
        std::cout << "Vertex: " << comp_iter->first << std::endl;
        std::cout << "Connections: ";
        for (std::vector<int>::iterator Con = comp_iter->second.begin(); Con != comp_iter->second.end(); Con++)
        {
            std::cout << *Con << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
#include <iostream>
#include <stack>
#include <list>
#include "Graph.h"

int main()
{
    Graph gr;
    for (int i = 0; i < 12; i++)
        gr.Add(i + 1);

    gr.SetConnection(2, 1);
    gr.SetConnection(2, 3);
    gr.SetConnection(2, 4);
    gr.SetConnection(1, 7);
    gr.SetConnection(3, 6);
    gr.SetConnection(3, 4);
    gr.SetConnection(5, 6);
    gr.SetConnection(5, 4);
    gr.SetConnection(5, 8);
    gr.SetConnection(11, 10);
    gr.SetConnection(9, 10);

    std::cout << gr;
    std::list<GNode *> Res;
    gr.Component(&Res);
    std::cout << std::endl;
    gr.PrintGraph(std::cout, &Res);

    return 0;
}
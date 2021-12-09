#include <iostream>
#include <stack>
#include "Graph.h"

int main()
{
    Graph gr;
    for (int i = 0; i < 6; i++)
        gr.Add(i + 1);
    // gr.SetConnection(2, 1);
    // gr.SetConnection(2, 3);
    // gr.SetConnection(2, 4);
    // gr.SetConnection(1, 7);
    // gr.SetConnection(3, 6);
    // gr.SetConnection(3, 4);
    // gr.SetConnection(5, 6);
    // gr.SetConnection(5, 4);
    // gr.SetConnection(5, 8);
    // std::cout << gr;

    // gr.Dfs_rec(3);
    // gr.Dfs(3);
    // gr.Bfs(3);
    // if (gr.Cycle(3))
    //     std::cout << true << std::endl;
    // else
    //     std::cout << false << std::endl;

    gr.SetDirectConnection(1, 2);
    gr.SetDirectConnection(2, 3);
    gr.SetDirectConnection(1, 3);
    gr.SetDirectConnection(4, 1);
    gr.SetDirectConnection(6, 4);
    gr.SetDirectConnection(4, 5);
    gr.SetDirectConnection(5, 6);
    std::cout << gr;
    std::cout << gr.CycleDirect() << std::endl;

    return 0;
}
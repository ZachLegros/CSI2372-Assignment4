#include "Graph.h"
#include <iostream>

using namespace std;

int main()
{
    Graph g1(6);
    g1.add_edge(1, 2);
    g1.add_edge(2, 1);
    g1.add_edge(2, 3);
    g1.add_edge(2, 4);
    g1.add_edge(3, 3);
    g1.add_edge(4, 1);
    g1.add_edge(4, 3);
    g1.add_edge(5, 6);

    cout << g1 << endl;
    DoubleLinkedList dfs = g1.DFS(1);
    cout << dfs << endl;
    DoubleLinkedList bfs = g1.BFS(1);
    cout << bfs << endl;
    cout << "Connectivity: " << g1.connectivity_type() << endl;

    Graph g2(5);
    g2.add_edge(1, 2);
    g2.add_edge(1, 3);
    g2.add_edge(2, 4);
    g2.add_edge(2, 5);

    cout << g2 << endl;
    DoubleLinkedList dfs2 = g2.DFS(1);
    cout << dfs2 << endl;
    DoubleLinkedList bfs2 = g2.BFS(1);
    cout << bfs2 << endl;
    cout << "Connectivity: " << g2.connectivity_type() << endl;

    Graph g4(3);
    g4.add_edge(1, 2);
    g4.add_edge(2, 3);
    
    cout << g4 << endl;
    cout << "Connectivity: " << g4.connectivity_type() << endl;

    Graph g3(5);
    g3.add_edge(1, 2);
    g3.add_edge(2, 3);
    g3.add_edge(3, 4);
    g3.add_edge(3, 5);
    g3.add_edge(5, 3);
    g3.add_edge(4, 1);
    
    cout << g3 << endl;
    cout << "Connectivity: " << g3.connectivity_type() << endl;

    return 0;
}
#pragma once
#include <iostream>
#include "DoubleLinkedList.h"

enum Connectivity
{
    NOT_CONNECTED = 0,
    WEAKLY_CONNECTED = 1,
    UNILATERALLY_CONNECTED = 2,
    STRONGLY_CONNECTED = 3
};

class Graph
{
    private:
        int n;                  // size of graph
        DoubleLinkedList **adj;  // adjacency list
        int capacity;
        bool is_vertex_in_range(int) const;
    public:
        Graph();
        Graph(int);
        Graph(const Graph &);
        ~Graph();
        bool add_edge(int, int);
        void remove_edge(int, int);
        bool edge_exist(int, int) const;
        int get_degree(int) const;
        Graph &operator++();
        Graph operator++(int);
        Graph &operator--();
        Graph operator--(int);
        bool path_exist(int, int) const;
        friend std::ostream &operator<<(std::ostream &os, const Graph &);
        Connectivity connectivity_type() const;
        DoubleLinkedList BFS(int) const;        
        DoubleLinkedList DFS(int) const;
};
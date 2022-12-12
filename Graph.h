// Sébastien Girard 300133000
// Zachary Legros 300136274

#pragma once
#include<vector>
#include<ostream>

class Graph {
public:
    Graph();
    Graph(int numberOfVertices);
    Graph(const Graph &other);

    int size();
    bool add_edge(int from, int to);
    bool vertex_exists(int vertex) const;
    bool edge_exists(int from, int to) const;
    bool remove_edge(int from, int to);

    int get_degree(int vertex) const;

    bool path_exists(int from, int to) const;

    friend std::ostream& operator<<(std::ostream &o, const Graph &graph);
    void operator=(const Graph &other);
    Graph& operator++();
    Graph operator++(int);
    Graph& operator--();
    Graph operator--(int);

    std::vector<int> bfs(int initial) const;
    std::vector<int> dfs(int initial) const;

protected:

    struct AdjancyListItem {
        int nodeId;
        std::vector<int> adjancyNodes;
    };

    std::vector<AdjancyListItem> adjancyList;

    template<typename T>
    bool vectorContains(std::vector<T> vect, T item) const;
};
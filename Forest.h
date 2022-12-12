// Sébastien Girard 300133000
// Zachary Legros 300136274

#pragma once
#include "Graph.h"
#include <iostream>


class Forest : public Graph {
public:
    Forest();
    Forest(int num);
    bool has_cycle(int initialNode);
    bool add_edge(int v1, int v2);
};
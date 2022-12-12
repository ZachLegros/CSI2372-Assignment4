// Sébastien Girard 300133000
// Zachary Legros 300136274

#pragma once
#include "Graph.h"
#include <vector>
#include <iostream>

class BiPartite: public Graph {
    
public:
    BiPartite(int num);
    BiPartite();

    bool add_edge(int from, int to);

    BiPartite& operator++() = delete;
    BiPartite operator++(int) = delete;
    

private:
    bool isBiPartite();

};
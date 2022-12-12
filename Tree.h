#pragma once
#include "Forest.h"
#include <iostream>

class Tree : public Forest
{
private:
    int root;
    std::ostream &print_tree(std::ostream &o, int root, int tab, bool *visited) const;

public:
    Tree();
    Tree &operator++();
    Tree operator++(int);
    Tree &operator--();
    Tree operator--(int);
    bool add_vertex(int);
    bool set_root(int);
    friend std::ostream &operator<<(std::ostream &o, const Tree &tree);
};
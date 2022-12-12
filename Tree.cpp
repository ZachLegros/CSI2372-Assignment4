// Sébastien Girard 300133000
// Zachary Legros 300136274


#include "Tree.h"
#include <algorithm>

Tree::Tree()
{
    AdjancyListItem item = {(int)adjancyList.size(), std::vector<int>()};
    adjancyList.push_back(item);
    root = item.nodeId;
}

Tree &Tree::operator++()
{
    AdjancyListItem item = {(int)adjancyList.size(), std::vector<int>()};
    adjancyList.push_back(item);
    adjancyList[item.nodeId - 1].adjancyNodes.push_back(item.nodeId);
    adjancyList[item.nodeId].adjancyNodes.push_back(item.nodeId - 1);
    return *this;
}

Tree Tree::operator++(int)
{
    Tree other = *this;
    ++(*this);
    return other;
}

Tree &Tree::operator--()
{
    int to_remove = (*(adjancyList.end() - 1)).nodeId;
    adjancyList.pop_back();
    for (auto itr = adjancyList.begin(); itr != adjancyList.end(); itr++)
    {
        // erase the node to_remove from the other parents
        auto it = std::find(itr->adjancyNodes.begin(), itr->adjancyNodes.end(), to_remove);
        if (it != itr->adjancyNodes.end())
            itr->adjancyNodes.erase(it);
    }
    return *this;
}

Tree Tree::operator--(int)
{
    Tree other = *this;
    --(*this);
    return other;
}

bool Tree::add_vertex(int v)
{
    if (!vertex_exists(v))
        return false;
    AdjancyListItem item = {(int)adjancyList.size(), std::vector<int>()};
    adjancyList.push_back(item);
    adjancyList[v].adjancyNodes.push_back(item.nodeId);
    adjancyList[item.nodeId].adjancyNodes.push_back(v);
    return true;
}

bool Tree::set_root(int v)
{
    if (!vertex_exists(v))
        return false;
    root = v;
    return true;
}

std::ostream &Tree::print_tree(std::ostream &o, int root, int tab, bool *visited) const
{
    for (int i = 0; i < tab - 1; i++)
    {
        o << "   ";
    }
    if (tab > 0)
        o << "---";
    o << root << std::endl;
    visited[root] = true;
    if (adjancyList.at(root).adjancyNodes.size() == 1)
        return o;
    for (auto itr = adjancyList.at(root).adjancyNodes.begin(); itr != adjancyList.at(root).adjancyNodes.end(); ++itr)
    {
        if (!visited[(*itr)])
            print_tree(o, (*itr), tab + 1, visited);
    }
    return o;
}

std::ostream &operator<<(std::ostream &o, const Tree &tree)
{
    int n = tree.size();
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    return tree.print_tree(o, tree.root, 0, visited);
}
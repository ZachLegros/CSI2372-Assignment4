// Sébastien Girard 300133000
// Zachary Legros 300136274

#include "Forest.h"
#include <iostream>
#include <vector>
#include <algorithm>

Forest::Forest(): Graph() {
    
}
Forest::Forest(int num): Graph(num) {

}

bool Forest::add_edge(int v1, int v2)
{
    if(!vertex_exists(v1) || !vertex_exists(v2)) {
        return false;
    }
    
    // if edge already exists, we want to return falses
    if(edge_exists(v1, v2)) {
        return false;
    }

    adjancyList[v1].adjancyNodes.push_back(v2);
    adjancyList[v2].adjancyNodes.push_back(v1);

    if(has_cycle(v2))
    {
        remove_edge(v1, v2);
        return false;
    }
    return true;
}

bool Forest::has_cycle(int initialNode)
{
    std::vector<int> stack;
    int n = adjancyList.size();
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    stack.push_back(initialNode);

    int previous = -1;
    while(stack.size() > 0)
    {
        int current = *(stack.end()-1);
        stack.pop_back();
        if (visited[current] == false)
        {
            if(previous == current) {
                continue;
            }
            visited[current] = true;
            // add children to stack
            for (auto itr = adjancyList.at(current).adjancyNodes.begin(); itr != adjancyList.at(current).adjancyNodes.end(); ++itr)
            {
                stack.push_back(*itr);
            }
            previous = current;
        } 
        else
        {
            return true;
        }
    }
    return false;
}
#include "BiPartite.h"
#include <iostream>
#include <vector>

BiPartite::BiPartite(int num): Graph(num) {};
BiPartite::BiPartite(): Graph() {};


bool BiPartite::add_edge(int from, int to) {
    if(!vertex_exists(from) || !vertex_exists(to)) {
        return false;
    }
    if(edge_exists(from, to)) {
        return false;
    }
    if(edge_exists(to, from)) {
        return false;
    }

    adjancyList[from].adjancyNodes.push_back(to);
    adjancyList[to].adjancyNodes.push_back(from);

    if(!isBiPartite()) {
        adjancyList[from].adjancyNodes.pop_back();
        adjancyList[to].adjancyNodes.pop_back();
        return false;
    }
    return true;
}

bool BiPartite::isBiPartite() {
    std::vector<int> colors(adjancyList.size(), -1);
    std::vector<AdjancyListItem> queue;
    queue.push_back(adjancyList.at(0));
    colors[0] = 1;
    while(!queue.empty()) {
        AdjancyListItem current = queue.at(queue.size() - 1);
        queue.pop_back();
        for(int i = 0; i < current.adjancyNodes.size(); i++) { // for each adjancy node
            int adj = current.adjancyNodes.at(i);
            if(colors[adj] == -1) {
                colors[adj] = 1 - colors[current.nodeId];
                queue.push_back(adjancyList[adj]);
            } else if(colors[adj] == colors[current.nodeId]) {
                return false;
            }
        }
    }
    return true;
}
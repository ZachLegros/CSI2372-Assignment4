// Sébastien Girard 300133000
// Zachary Legros 300136274

#include "Graph.h"
#include <vector>
#include <ostream>


Graph::Graph() {

}

Graph::Graph(const Graph &other): adjancyList(other.adjancyList) {

}

Graph::Graph(int numberOfVertices) {
    for(int i=0; i<numberOfVertices; i++) {
        adjancyList.push_back({i, std::vector<int>()});
    }
}

int Graph::size()
{
    return adjancyList.size();
}


std::ostream& operator<<(std::ostream &o, const Graph &graph) {
    o << "V = {";
    for(int i=0; i<(int)graph.adjancyList.size()-1; i++) {
        o << graph.adjancyList[i].nodeId << ", ";
    }
    if(graph.adjancyList.size()  > 1) {
        o << graph.adjancyList[graph.adjancyList.size()-1].nodeId;
    }
    o << "}\n";

    o << "E =\n{\n";

    for(int i=0; i<(int)graph.adjancyList.size(); i++) {
        o << "\t" << graph.adjancyList[i].nodeId << " => ";
        if(graph.adjancyList[i].adjancyNodes.size() > 0) {
            for(int j=0; j<(int)graph.adjancyList[i].adjancyNodes.size()-1; j++) {
                o << graph.adjancyList[i].adjancyNodes[j] << ", ";
            }
            o << graph.adjancyList[i].adjancyNodes[graph.adjancyList[i].adjancyNodes.size()-1]<< "\n";

        } else {
            o << "None\n";
        }
    }
    o << "}";
    
    return o;

}

void Graph::operator=(const Graph &other) {
    adjancyList = other.adjancyList;
}


bool Graph::add_edge(int from, int to) {
    if(!vertex_exists(from) || !vertex_exists(to)) {
        return false;
    }
    
    // if edge already exists, we want to return falses
    if(edge_exists(from, to) || edge_exists(to, from)) {
        return false;
    }

    // add the node to the adjancy list
    adjancyList[from].adjancyNodes.push_back(to);
    adjancyList[to].adjancyNodes.push_back(from);
    
    return true;
}

bool Graph::vertex_exists(int vertexId) const {

    for(auto it = adjancyList.begin(); it != adjancyList.end(); ++it) {
        if (it->nodeId == vertexId) return true;
    }

    return false;
}

bool Graph::edge_exists(int from, int to) const {
    if(!vertex_exists(from) || !vertex_exists(to)) {
        return false;
    }

    for(auto it = adjancyList[from].adjancyNodes.begin(); it != adjancyList[from].adjancyNodes.end(); ++it) {
        if (*it == to) return true;
    }

    return false;
}

bool Graph::remove_edge(int from, int to) {
    if(!edge_exists(from, to)) {
        return false;
    }

    for(auto it=adjancyList[from].adjancyNodes.begin(); it != adjancyList[from].adjancyNodes.end(); ++it) {
        if(*it == to) {
            adjancyList[from].adjancyNodes.erase(it);
            return true;
        }
    }

    for(auto it=adjancyList[to].adjancyNodes.begin(); it != adjancyList[to].adjancyNodes.end(); ++it) {
        if(*it == to) {
            adjancyList[to].adjancyNodes.erase(it);
            return true;
        }
    }

    return false;
    
}

int Graph::get_degree(int vertex) const {
    if(!vertex_exists(vertex)) {
        return -1;
    }

    return adjancyList[vertex].adjancyNodes.size();
}

Graph& Graph::operator++() {
    AdjancyListItem item = {(int)this->adjancyList.size(), std::vector<int>()};
    this->adjancyList.push_back(item);
    return *this;
}

Graph Graph::operator++(int) {
    Graph other = *this;
    AdjancyListItem item = {(int)this->adjancyList.size(), std::vector<int>()};
    this->adjancyList.push_back(item);
    return other;
}

Graph& Graph::operator--() {
    this->adjancyList.pop_back();
    return *this;
}

Graph Graph::operator--(int) {
    Graph other = *this;
    this->adjancyList.pop_back();
    return other;
}


std::vector<int> Graph::bfs(int initial) const {
    if(!vertex_exists(initial)) {
        return std::vector<int>();
    }
    std::vector<int> toExplore;
    std::vector<int> explored;
    toExplore.push_back(initial);

    while(toExplore.size() > 0) {
        int current = toExplore.at(0);
        toExplore.erase(toExplore.begin());
        

        if(vectorContains(explored, current)) {
            continue;
        }
        for(int i=0; i<(int)adjancyList[current].adjancyNodes.size(); i++) {
            int node = adjancyList[current].adjancyNodes[i];
            if(!vectorContains(explored, node) && node != current) {
                toExplore.push_back(node);
            }
        }
        explored.push_back(current);
    }
    
    return explored;
}

bool Graph::path_exists(int from, int to) const {
    if(!vertex_exists(from) || !vertex_exists(to)) {
        return false;
    }
    return vectorContains(bfs(from), to);
}

template<typename T>
bool Graph::vectorContains(std::vector<T> vect, T item) const {
    for(auto it = vect.begin(); it != vect.end(); ++it) {
        if(*it == item) return true;
    }

    return false;
}

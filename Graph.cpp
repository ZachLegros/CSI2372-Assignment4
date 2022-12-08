#include "Graph.h"
#define INCREMENT_SIZE 10

Graph::Graph()
{
    this->n = 1;
    adj = new DoubleLinkedList*[n];
    capacity = n;
    for (int i = 0; i < n; i++)
    {
        DoubleLinkedList *a = new DoubleLinkedList();
        adj[i] = a;
    }
}

Graph::Graph(int n)
{
    this->n = n;
    adj = new DoubleLinkedList*[n];
    capacity = n;
    for (int i = 0; i < n; i++)
    {
        DoubleLinkedList *a = new DoubleLinkedList();
        adj[i] = a;
    }
}

Graph::Graph(const Graph &other)
{
    this->n = other.n;
    adj = new DoubleLinkedList*[other.n];
    capacity = other.capacity;

    for (int i = 0; i < other.n; i++)
    {
        adj[i] = new DoubleLinkedList();
        DoubleLinkedList *vertices = other.adj[i];
        int degree = vertices->count_nodes();
        for (int j = 0; j < degree; j++)
        {
            adj[i]->add_to_back((*vertices)[j]);
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < n; i++)
    {
        delete adj[i];
    }
    delete[] adj;
}

bool Graph::is_vertex_in_range(int v) const
{
    return !(v > n || v < 1);
}

bool Graph::add_edge(int v1, int v2)
{
    if (!is_vertex_in_range(v1) || !is_vertex_in_range(v2))
        return false;
    
    adj[v1 - 1]->add_to_back(v2);
    return true;
}

void Graph::remove_edge(int v1, int v2)
{
    if (!is_vertex_in_range(v1) || !is_vertex_in_range(v2))
        return;
    
    adj[v1 - 1]->remove_item(v2);
}

bool Graph::edge_exist(int v1, int v2) const
{
    if (!is_vertex_in_range(v1) || !is_vertex_in_range(v2))
        return false;
    
    return adj[v1 - 1]->find(v2);   
}

int Graph::get_degree(int v) const
{
    if (!is_vertex_in_range(v))
        return 0;
    
    return adj[v - 1]->count_nodes();
}

Graph &Graph::operator++()
{
    if (n >= capacity)
    {
        DoubleLinkedList **new_adj = new DoubleLinkedList*[capacity + INCREMENT_SIZE];
        std::copy(adj, adj + capacity, new_adj);
        delete[] adj;
        adj = new_adj;
        capacity += INCREMENT_SIZE;
    }

    adj[n++] = new DoubleLinkedList();
    return *this;
}

Graph Graph::operator++(int)
{
    Graph cp(*this);
    ++(*this);
    return cp;
}

Graph &Graph::operator--()
{
    if (n <= 0) return *this;

    for (int i = 0; i < n - 1; i++)
    {
        if (edge_exist(i+1, n))
            adj[i]->remove_item(n);
    }

    delete adj[--n];
    return *this;
}

Graph Graph::operator--(int)
{
    Graph cp(*this);
    --(*this);
    return cp;
}

bool Graph::path_exist(int v1, int v2) const
{
    DoubleLinkedList dfs = this->DFS(v1);
    int size = dfs.count_nodes();
    for (int i = 0; i < size; i++)
    {
        if (dfs[i] == v2)
            return true;
    }
    return false;
}

DoubleLinkedList Graph::DFS(int v) const
{
    DoubleLinkedList result;
    // if root vertex is invalid, return empty list
    if (!is_vertex_in_range(v))
        return result;

    DoubleLinkedList stack;
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    stack.add_to_back(v);
    while(stack.count_nodes() > 0)
    {
        int current = stack.get_tail();
        stack.remove_from_back();
        if (visited[current] == false)
        {
            visited[current] = true;
            result.add_to_back(current);
            // add children to stack
            int degree = get_degree(current);
            for (int i = degree - 1; i >= 0; i--)
            {
                stack.add_to_back((*adj[current - 1])[i]);
            }
        }
    }
    return result;
}

DoubleLinkedList Graph::BFS(int v) const
{
    DoubleLinkedList result;
    // if root vertex is invalid, return empty list
    if (!is_vertex_in_range(v))
        return result;

    DoubleLinkedList queue;
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    queue.add_to_front(v);
    while(queue.count_nodes() > 0)
    {
        int current = queue.get_head();
        queue.remove_from_front();
        if (visited[current] == false)
        {
            visited[current] = true;
            result.add_to_back(current);
            // add children to queue
            int degree = get_degree(current);
            for (int i = 0; i < degree; i++)
            {
                queue.add_to_back((*adj[current - 1])[i]);
            }
        }
    }
    return result;
}

Connectivity Graph::connectivity_type() const
{
    // create undirected graph
    Graph undirected(*this);
    for (int i = 0; i < undirected.n; i++)
    {
        int degree = undirected.get_degree(i+1);
        for (int j = 0; j < degree; j++)
        {
            if (!undirected.edge_exist((*undirected.adj[i])[j], i+1))
                undirected.add_edge((*undirected.adj[i])[j], i+1);
        }
    }
    
    bool is_strongly_connected = true;
    bool is_unilaterally_connected = true;
    bool is_weakly_connected = true;
    for (int i = 0; i < n; i++)
    {
        int degree = get_degree(i+1);
        for (int j = 0; j < n; j++)
        {
            if (j == n) continue;
            bool i_j_exist = path_exist(i+1, j+1);
            bool j_i_exist = path_exist(j+1, i+1);
            bool un_i_j_exist = undirected.path_exist(i+1, j+1);
            bool un_j_i_exist = undirected.path_exist(j+1, i+1);
            is_strongly_connected &= i_j_exist && j_i_exist;
            is_unilaterally_connected &= i_j_exist || j_i_exist;
            is_weakly_connected &= un_i_j_exist || un_j_i_exist;
        }
    }

    if (is_strongly_connected) return STRONGLY_CONNECTED;
    if (is_unilaterally_connected) return UNILATERALLY_CONNECTED;    
    if (is_weakly_connected) return WEAKLY_CONNECTED;
    return NOT_CONNECTED;
}


std::ostream &operator<<(std::ostream &os, const Graph &g)
{
    os << "V = {";
    for (int i = 1; i < g.n+1; i++)
    {
        os << i;
        if (i < g.n)
           os << ", ";
    }
    os << "}" << std::endl;
    os << "E =" << std::endl;
    os << "{" << std::endl;
    for (int i = 0; i < g.n; i++)
    {
        os << " " << i+1 << " => ";
        int degree = g.get_degree(i+1);
        if (degree == 0)
            os << "None";
        else
        {
            for (int j = 0; j < degree; j++)
            {
                os << (*g.adj[i])[j];
                if (j < degree - 1)
                    os << ", ";
            }
        }
        os << std::endl;
    }
    os << "}" << std::endl;
    
    return os;
}
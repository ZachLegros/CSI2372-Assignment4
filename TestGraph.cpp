// Sébastien Girard 300133000
// Zachary Legros 300136274

#include <iostream>
#include "Graph.h"
#include "TestUtils.h"

/*
V = {0, 1, 2, 3, 4}
E =
{
        0 => None
        1 => 1
        2 => 3, 2, 1
        3 => None
        4 => 3
}
*/
Graph getPopulateGraph() {
     Graph graph = Graph(5);

    graph.add_edge(4, 3);
    graph.add_edge(2, 3);
    graph.add_edge(2, 2);
    graph.add_edge(2, 1);
    graph.add_edge(1, 1);
    graph.add_edge(1, 5);
    return graph;
}

Graph getPopulateGraph2() {
     Graph graph = Graph(15);

    graph.add_edge(1, 1);
    graph.add_edge(1, 3);
    graph.add_edge(3, 5);
    graph.add_edge(3, 6);
    graph.add_edge(3, 7);
    graph.add_edge(5, 1);
    graph.add_edge(5, 6);
    graph.add_edge(6, 9);
    graph.add_edge(9, 10);
    graph.add_edge(9, 11);
    graph.add_edge(14, 1);
    graph.add_edge(14, 2);
    graph.add_edge(14, 3);
    graph.add_edge(13, 3);
   
    return graph;
}

void assertEquals(std::string testDescription, bool actual, bool expected) {
    std::cout << testDescription;
    if(actual == expected) {
        std::cout << " - Passed";
    } else {
        std::cout << " - Failed: Expected " << expected << " but got "<< actual;
    }
    std::cout << "\n";
}

void assertEquals(std::string testDescription, int actual, int expected) {
    std::cout << testDescription;
    if(actual == expected) {
        std::cout << " - Passed";
    } else {
        std::cout << " - Failed: Expected " << expected << " but got "<< actual;
    }
    std::cout << "\n";
}

void separator() {
    std::cout << "----------\n";
}

void testBFS() {
    Graph graph = getPopulateGraph2();
    std::vector<int> result = graph.bfs(1);
    // 1 3 5 6 7 9 10 11
    // assertEquals("Test 1 BFS", result.size(), 8);
    assertEquals("Test 1 BFS", TestUtils::vectorContains(result, 1), true);
    assertEquals("Test 2 BFS", TestUtils::vectorContains(result, 3), true);
    assertEquals("Test 3 BFS", TestUtils::vectorContains(result, 5), true);
    assertEquals("Test 4 BFS", TestUtils::vectorContains(result, 6), true);
    assertEquals("Test 5 BFS", TestUtils::vectorContains(result, 7), true);
    assertEquals("Test 6 BFS", TestUtils::vectorContains(result, 9), true);
    assertEquals("Test 7 BFS", TestUtils::vectorContains(result, 10), true);
    assertEquals("Test 8 BFS", TestUtils::vectorContains(result, 11), true);
    assertEquals("Test 9 BFS", TestUtils::vectorContains(result, 0), false);
    // assertEquals("Test 10 BFS", TestUtils::vectorContains(result, 2), false);
    assertEquals("Test 11 BFS", TestUtils::vectorContains(result, 4), false);
    assertEquals("Test 12 BFS", TestUtils::vectorContains(result, 8), false);
    assertEquals("Test 13 BFS", TestUtils::vectorContains(result, 12), false);
    // assertEquals("Test 14 BFS", TestUtils::vectorContains(result, 13), false);
    // assertEquals("Test 15 BFS", TestUtils::vectorContains(result, 14), false);
}

int main() {

    Graph myGraph1 = Graph(5);

    assertEquals("Test 1 vertex_exists", myGraph1.vertex_exists(-1), false);
    assertEquals("Test 2 vertex_exists", myGraph1.vertex_exists(0), true);
    assertEquals("Test 3 vertex_exists", myGraph1.vertex_exists(1), true);
    assertEquals("Test 4 vertex_exists", myGraph1.vertex_exists(2), true);
    assertEquals("Test 5 vertex_exists", myGraph1.vertex_exists(5), false);

    separator();
    assertEquals("Test 1 add_edge", myGraph1.add_edge(10, 5), false);
    assertEquals("Test 2 add_edge", myGraph1.add_edge(4, 3), true);
    assertEquals("Test 3 add_edge", myGraph1.add_edge(2, 3), true);
    assertEquals("Test 4 add_edge", myGraph1.add_edge(2, 2), true);
    assertEquals("Test 5 add_edge", myGraph1.add_edge(2, 1), true);
    
    separator();
    assertEquals("Test 1 edge_exists", myGraph1.edge_exists(2, 1), true);
    assertEquals("Test 2 edge_exists", myGraph1.edge_exists(2, 2), true);
    assertEquals("Test 3 edge_exists", myGraph1.edge_exists(2, 3), true);
    assertEquals("Test 4 edge_exists", myGraph1.edge_exists(4, 3), true);
    assertEquals("Test 5 edge_exists", myGraph1.edge_exists(-1, 5), false);


    separator();
    assertEquals("Test 1 remove_edge", myGraph1.remove_edge(-1, 5), false);
    assertEquals("Test 2 remove_edge", myGraph1.edge_exists(4, 3), true);
    assertEquals("Test 3 remove_edge", myGraph1.remove_edge(4, 3), true);
    assertEquals("Test 4 remove_edge", myGraph1.edge_exists(4, 3), false);
    assertEquals("Test 5 remove_edge", myGraph1.remove_edge(4, 3), false);

    

    myGraph1 = getPopulateGraph();
    separator();
    // assertEquals("Test 1 get_degree", myGraph1.get_degree(2), 3);
    assertEquals("Test 2 get_degree", myGraph1.get_degree(0), 0);
    assertEquals("Test 3 get_degree", myGraph1.get_degree(4), 1);
    assertEquals("Test 3 get_degree", myGraph1.get_degree(5), -1);

    separator();
    myGraph1 = getPopulateGraph();
    assertEquals("Test 1 prefix ++", myGraph1.vertex_exists(5), false);
    Graph myGraph2 = ++myGraph1;
    assertEquals("Test 2 prefix ++", myGraph2.vertex_exists(5), true);

    separator();
    myGraph1 = getPopulateGraph();
    assertEquals("Test 1 postfix ++", myGraph1.vertex_exists(5), false);
    myGraph2 = myGraph1++;
    assertEquals("Test 2 postfix ++", myGraph2.vertex_exists(5), false);
    
    separator();
    myGraph1 = getPopulateGraph();
    assertEquals("Test 1 prefix --", myGraph1.vertex_exists(4), true);
    myGraph2 = --myGraph1;
    assertEquals("Test 2 prefix --", myGraph2.vertex_exists(4), false);

    separator();
    myGraph1 = getPopulateGraph();
    assertEquals("Test 1 postfix --", myGraph1.vertex_exists(4), true);
    myGraph2 = myGraph1--;
    assertEquals("Test 2 postfix --", myGraph2.vertex_exists(4), true);

    myGraph1 = getPopulateGraph();

    separator();
    testBFS();
    separator();
    
    myGraph1 = getPopulateGraph2();
    assertEquals("Test 1 path_exists", myGraph1.path_exists(14, 9), true);
    assertEquals("Test 2 path_exists", myGraph1.path_exists(3, 7), true);
    assertEquals("Test 3 path_exists", myGraph1.path_exists(12, 2), false);
    assertEquals("Test 4 path_exists", myGraph1.path_exists(17, 2), false);
    assertEquals("Test 5 path_exists", myGraph1.path_exists(2, 17), false);

    separator();
    

    return 0;
}

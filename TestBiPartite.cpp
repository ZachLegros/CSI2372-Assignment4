#include "BiPartite.h"
#include <iostream>
#include <vector>
#include "TestUtils.h"


int main() {
    BiPartite graph(5);

    TestUtils::separator("Adding Valid Edges");

    TestUtils::assertEquals("Test 1 add valid edge", graph.add_edge(0, 1), true);
    TestUtils::assertEquals("Test 2 add valid edge", graph.add_edge(0, 2), true);
    TestUtils::assertEquals("Test 3 add valid edge", graph.add_edge(0, 3), true);
    TestUtils::assertEquals("Test 4 add valid edge", graph.add_edge(0, 4), true);

    TestUtils::separator("Adding Invalid Edges");
    TestUtils::assertEquals("Test 5 add invalid edge", graph.add_edge(1, 2), false);
    TestUtils::assertEquals("Test 6 add invalid edge", graph.add_edge(1, 3), false);
    TestUtils::assertEquals("Test 7 add invalid edge", graph.add_edge(1, 4), false);
    TestUtils::assertEquals("Test 8 add invalid edge", graph.add_edge(2, 3), false);
    TestUtils::assertEquals("Test 9 add invalid edge", graph.add_edge(2, 4), false);
    TestUtils::assertEquals("Test 10 add invalid edge", graph.add_edge(3, 4), false);

    // Complete bipartite graph

    BiPartite graph2(4);

    TestUtils::separator("Adding Valid Edges of Complete Bipartite Graph");

    TestUtils::assertEquals("Test 11 add valid edge", graph2.add_edge(0, 1), true);
    TestUtils::assertEquals("Test 12 add valid edge", graph2.add_edge(0, 3), true);
    TestUtils::assertEquals("Test 12 add valid edge", graph2.add_edge(2, 1), true);
    TestUtils::assertEquals("Test 12 add valid edge", graph2.add_edge(2, 3), true);

    TestUtils::separator("Adding Invalid Edges of Complete Bipartite Graph");

    TestUtils::assertEquals("Test 13 add invalid edge", graph2.add_edge(0, 2), false);
    TestUtils::assertEquals("Test 14 add invalid edge", graph2.add_edge(1, 3), false);
    

    
    return 0;
}
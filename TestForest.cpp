#include "Forest.h"
#include "TestUtils.h"
#include <iostream>
#include <string>

int main()
{

    TestUtils::separator("Test Forest Constructor");
    Forest f1(5);

    f1.add_edge(0, 1);
    f1.add_edge(0, 2);
    f1.add_edge(1, 3);
    f1.add_edge(2, 4);

    std::cout << f1 << std::endl;
    TestUtils::assertEquals("Test Forest Size", f1.size(), 5);
    TestUtils::assertEquals("Test 1 Add Edge fail because of Cycle", f1.add_edge(4, 3), false);
    TestUtils::assertEquals("Test 2 Add Edge fail because of Cycle", f1.add_edge(3, 4), false);

    return 0;
}
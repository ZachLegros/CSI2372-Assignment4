// Sébastien Girard 300133000
// Zachary Legros 300136274

#include "Tree.h"
#include "TestUtils.h"
#include <iostream>
#include <string>

int main()
{
    TestUtils::separator("Test Tree Constructor");
    Tree t1;
    ++t1;
    ++t1;
    t1.add_vertex(1);
    t1.add_vertex(0);
    ++t1;
    ++t1;
    t1.add_vertex(0);
    std::cout << t1 << std::endl;
    TestUtils::assertEquals("Test Tree Size", t1.size(), 8);

    t1.set_root(4);
    std::cout << t1 << std::endl;

    return 0;
}
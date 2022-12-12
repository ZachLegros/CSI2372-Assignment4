#include"Forest.h"
#include"TestUtils.h"
#include<iostream>
#include<string>

// Sébastien Girard 300133000
// Zachary Legros 300136274

int main() {


    TestUtils::separator("Test Forest Constructor");
    Forest f1(5);

    f1.add_edge(1,2);
    f1.add_edge(2,3);
    std::cout << f1 << std::endl;
    TestUtils::assertEquals("Test Forest Size", f1.size(), 5);
    TestUtils::assertEquals("Test 1 Add Edge fail because of Cycle", f1.add_edge(3, 1), false);
    TestUtils::assertEquals("Test 2 Add Edge fail because of Cycle", f1.add_edge(1, 3), false);
    
    
    return 0;
}
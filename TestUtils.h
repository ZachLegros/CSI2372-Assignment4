// Sébastien Girard 300133000
// Zachary Legros 300136274

#pragma once

#include <iostream>

namespace TestUtils
{
    void assertEquals(std::string testDescription, bool actual, bool expected)
    {
        std::cout << testDescription;
        if (actual == expected)
        {
            std::cout << " - Passed";
        }
        else
        {
            std::cout << " - Failed: Expected " << expected << " but got " << actual;
        }
        std::cout << "\n";
    }

    void assertEquals(std::string testDescription, int actual, int expected)
    {
        std::cout << testDescription;
        if (actual == expected)
        {
            std::cout << " - Passed";
        }
        else
        {
            std::cout << " - Failed: Expected " << expected << " but got " << actual;
        }
        std::cout << "\n";
    }

    void separator()
    {
        std::cout << "----------\n";
    }

    void separator(std::string title)
    {
        std::cout << "------ " << title << " ----\n";
    }

    template<typename T>
    bool vectorContains(std::vector<T> vect, T item) {
        for(auto it = vect.begin(); it != vect.end(); ++it) {
            if(*it == item) return true;
        }

        return false;
    }

}
PROJECT = "assignment4"

build:TestForest.cpp Forest.cpp Graph.cpp DoubleLinkedList.cpp
	g++ TestForest.cpp Forest.cpp Graph.cpp DoubleLinkedList.cpp -std=c++11 -ggdb3 -g -O0 -Wall -Wextra -o $(PROJECT)


buildGraph: TestGraph.cpp Graph.cpp DoubleLinkedList.cpp
	g++ TestGraph.cpp Graph.cpp DoubleLinkedList.cpp -std=c++11 -ggdb3 -g -O0 -Wall -Wextra -o $(PROJECT)


clean:
	rm $(PROJECT)*
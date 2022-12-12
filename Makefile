PROJECT = "assignment4"

buildTree: TestTree.cpp Tree.cpp Forest.cpp Graph.cpp
	g++ TestTree.cpp Tree.cpp Forest.cpp Graph.cpp -std=c++11 -ggdb3 -g -O0 -Wall -Wextra -o $(PROJECT)

buildForest: TestForest.cpp Forest.cpp Graph.cpp
	g++ TestForest.cpp Forest.cpp Graph.cpp -std=c++11 -ggdb3 -g -O0 -Wall -Wextra -o $(PROJECT)

buildGraph: TestGraph.cpp Graph.cpp
	g++ TestGraph.cpp Graph.cpp -std=c++11 -ggdb3 -g -O0 -Wall -Wextra -o $(PROJECT)

buildBipartite: TestBiPartite.cpp Graph.cpp BiPartite.cpp
	g++ TestBiPartite.cpp Graph.cpp BiPartite.cpp -std=c++11 -ggdb3 -g -O0 -Wall -Wextra -o $(PROJECT)
clean:
	rm $(PROJECT)*
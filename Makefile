PROJECT = "assignment2"

build:
	g++ TestGraph.cpp Graph.cpp DoubleLinkedList.cpp -o $(PROJECT)

clean:
	rm $(PROJECT)*
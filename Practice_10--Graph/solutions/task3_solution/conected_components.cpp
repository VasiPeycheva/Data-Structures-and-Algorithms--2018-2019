/*
* Author: Nikolay Denev
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <string.h>

int dfs(bool* taken, const std::vector<int>* graph, int currentVertex) {
	if (taken[currentVertex])
		return 0;

	int numTraversedVerticies = 1;
	taken[currentVertex] = true;
	
	for (const int neighbor : graph[currentVertex]) {
		numTraversedVerticies += dfs(taken, graph, neighbor);
	}
	
	return numTraversedVerticies;
}

int main() {
	std::ifstream fileStream("test.txt");

	int numVertices;
	fileStream >> numVertices;
	std::vector<int>* graph = new std::vector<int>[numVertices];
	for (int i = 0; i < numVertices; ++i) {
		int numNeighbors;
		fileStream >> numNeighbors;
		for (int j = 0; j < numNeighbors; ++j) {
			int neighborIndex;
			fileStream >> neighborIndex;
			graph[i].push_back(neighborIndex);
		}
	}

	bool* taken = new bool[numVertices];
	memset(taken, 0, sizeof(bool)*numVertices);

	int componentsCount = 0;

	for (int i = 0; i < numVertices; ++i) {
		if (taken[i] == false) {
			++componentsCount;
			const int resultComponentSize = dfs(taken, graph, i);
			std::cout << "Size of component number " << componentsCount << ": " << resultComponentSize << std::endl;
		}
	}

	delete[] graph;
	delete[] taken;

	return 0;
}
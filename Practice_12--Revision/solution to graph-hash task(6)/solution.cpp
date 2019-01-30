/*
* revision TASK 6
*
* Author    : Nikolay Denev
*/

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

struct StudentInfo {
	StudentInfo()
		: programStringHash(0)
	{}

	std::vector<int> friends;
	std::string program;
	unsigned programStringHash;
};

unsigned getStringHash(const std::string& string) {
	unsigned long long resultHash = 1;
	int stringSize = static_cast<int>(string.length());
	for (int i = 0; i < stringSize; ++i) {
		resultHash = (resultHash * 257 + string[i])%1000000007;
	}

	return static_cast<unsigned>(resultHash);
}

bool dfs(bool* taken, const StudentInfo* graph, int currentVertex) {
	if (taken[currentVertex])
		return false;

	taken[currentVertex] = true;

	for (const int friendIndex : graph[currentVertex].friends) {
		if (graph[currentVertex].programStringHash == graph[friendIndex].programStringHash &&
			graph[currentVertex].program == graph[friendIndex].program)
			return true;
	}

	for (const int friendIndex : graph[currentVertex].friends) {
		if (dfs(taken, graph, friendIndex) == false)
			return true;
	}

	return false;
}

int main() {
	int numVertices;
	std::cin >> numVertices;
	StudentInfo* graph = new StudentInfo[numVertices];
	for (int i = 0; i < numVertices; ++i) {
		int numNeighbors;
		std::cin >> numNeighbors;
		for (int j = 0; j < numNeighbors; ++j) {
			int neighborIndex;
			std::cin >> neighborIndex;
			graph[i].friends.push_back(neighborIndex);
		}
		std::cin.ignore(10, '\n');
		std::getline(std::cin, graph[i].program);
		graph[i].programStringHash = getStringHash(graph[i].program);
	}

	bool* taken = new bool[numVertices];
	memset(taken, 0, sizeof(bool)*numVertices);

	bool haveCheaters = false;
	for (int i = 0; i < numVertices; ++i) {
		haveCheaters = dfs(taken, graph, 0);
		if (haveCheaters) {
			break;
		}
	}
	if (haveCheaters) {
		std::cout << "There are cheaters in the class...\n";
	} else {
		std::cout << "All students have honour\n";
	}

	delete[] graph;
	delete[] taken;

	return 0;
}
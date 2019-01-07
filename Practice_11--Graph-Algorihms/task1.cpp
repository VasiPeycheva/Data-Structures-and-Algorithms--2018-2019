/*
*
* Author : Vasilena Peycheva
*/


#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::make_pair;

typedef vector<vector<pair<int, int>>> adj_list;

const unsigned int MAX_DISTANCE = std::numeric_limits<int>::max();

void addEdge(adj_list& list, int i, int j, int w) {
	list[i].push_back(make_pair(j, w));
	list[j].push_back(make_pair(i, w));
}

void printList(const adj_list& list) {
	for (int i = 1; i < list.size(); i++) {
		std::cout << "vertex [" << i << "] has successors : { ";
		for (pair<int,int> v : list[i]) {
			std::cout << "(" << v.first << ',' << v.second << "), ";
		}
		std::cout << " } \n";
	}
}

void initDistVector(vector<int>& distance) {
	for (size_t i = 0; i < distance.size(); i++)
	{
		distance[i] = MAX_DISTANCE;
	}
}

void initFinishedVector(vector<bool>&finished) {
	for (size_t i = 0; i < finished.size(); i++)
	{
		finished[i] = false;
	}
}

int getNextVertex(vector<int>& distance, vector<bool> & visited) {
	int currentMin = MAX_DISTANCE;
	int currentMinIndex = -1;
	for (size_t i = 0; i < distance.size(); i++)
	{
		if (distance[i] < currentMin && !visited[i]) {
			currentMin = distance[i];
			currentMinIndex = i;
		}
	}
	return currentMinIndex;
}

vector<int> path(const adj_list & list, int start) {
	int n = list.size();
	vector<bool> finished(n);
	initFinishedVector(finished);
	vector<int> distance(n);
	initDistVector(distance);
	distance[start] = 0;
	int current = getNextVertex(distance, finished);
	while (current != -1) {
		for (size_t i = 0; i < list[current].size(); i++)
		{
			int end = list[current][i].first;
			int weight = list[current][i].second;
			if (distance[end] > (distance[current] + weight))
			{
				distance[end] = distance[current] + weight;
			}
		}
		finished[current] = true;
		current = getNextVertex(distance, finished);
	}
	return distance;
}

void testFunc() {
	adj_list list;
	list.resize(7);
	addEdge(list, 1, 2, 1);
	addEdge(list, 1, 3, 11);
	addEdge(list, 1, 4, 7);
	addEdge(list, 1, 6, 33);
	addEdge(list, 2, 6, 20);
	addEdge(list, 2, 4, 3);
	addEdge(list, 3, 5, 4);
	addEdge(list, 4, 5, 5);
	addEdge(list, 5, 6, 1);

	
	printList(list);

	vector<int> result = path(list, 1);
	for (size_t i = 1; i < result.size(); i++)
	{
		std::cout << result[i] << '\n';
	}
}

int main()
{
	testFunc();
	return 0;
}

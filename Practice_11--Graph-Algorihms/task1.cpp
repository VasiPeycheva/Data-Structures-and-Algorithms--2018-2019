/*
 * Solution to the first task - shortest paths in graph,
 * using a simplified version of Dijkstra's algorithm.
 * Author: Vasilena Peycheva, co-author: Ivan Filipov
*/

#include <iostream> // std::cout
#include <vector>   // std::vector
#include <limits>   // std::numeric_limits
#include <utility>  // std::pair

// import some names
using std::vector;
using std::pair;
using std::make_pair;
// each edge is a pair: [ to vertex with weight ]
using edge = pair<int, int>; 
// the graph is represented as adjacency lists 
using graph = vector<vector<edge>>;
// mark for unknown distance
const unsigned int MAX_DISTANCE = std::numeric_limits<int>::max();

/// add a new edge into graph @adjLists
/// from vertex @i to vertex @j, with weight @w
/// and because the graph is undirected, add the opposite edge also.
void addEdge(graph& adjLists, int i, int j, int w) {
	
	adjLists[i].push_back(make_pair(j, w));
	adjLists[j].push_back(make_pair(i, w));
}

/// simply outputs the @adjLists graph's contain
void printGraph(const graph& adjLists) {
	
	for (size_t i = 1; i < adjLists.size(); i++) {
		std::cout << "vertex [" << i << "] has successors : { ";
		for (const edge& e : adjLists[i]) {
			std::cout << "(" << e.first << ',' << e.second << "), ";
		}
		std::cout << " }\n";
	}
}

/// get the index of the closed unvisited vertex, depending on
/// known distances @distance and already visited vertices - @visited
int getNextVertex(const vector<int>& distance, const vector<bool>& visited) {
	
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

/// solving the task in graph @adjLists from starting vertex with index @start
/// @retval - a vector with distances to all other vertices
vector<int> path(const graph& adjLists, int start) {
	
	int n = adjLists.size();
	// mark all vertices as non-visited
	vector<bool> finished(n, false);
	// create vector with N cells, each of it with value MAX_DISTANCE
	vector<int> distance(n, MAX_DISTANCE);
	// mark the starting vertex
	distance[start] = 0;
	// get the closest
	int current = getNextVertex(distance, finished);
	// until we have a closest unvisited
	while (current != -1) {
		// optimize distances with it
		for (size_t i = 0; i < adjLists[current].size(); i++)
		{
			int end = adjLists[current][i].first;
			int weight = adjLists[current][i].second;
			if (distance[end] > (distance[current] + weight))
			{
				distance[end] = distance[current] + weight;
			}
		}
		// mark it as done
		finished[current] = true;
		// get the next one
		current = getNextVertex(distance, finished);
	}
	return distance;
}

void testFunc() {
	
	/* initialize the graph */
	graph adjLists;
	adjLists.resize(7);
	addEdge(adjLists, 1, 2, 1);
	addEdge(adjLists, 1, 3, 11);
	addEdge(adjLists, 1, 4, 7);
	addEdge(adjLists, 1, 6, 33);
	addEdge(adjLists, 2, 6, 20);
	addEdge(adjLists, 2, 4, 3);
	addEdge(adjLists, 3, 5, 4);
	addEdge(adjLists, 4, 5, 5);
	addEdge(adjLists, 5, 6, 1);
	
	/*output the stating graph */
	printGraph(adjLists);
	
	/* run the algorithm */
	int startVertexInd = 1;
	vector<int> result = path(adjLists, startVertexInd);
	/*output the result distances */
	std::cout << "\nstarting from [" << startVertexInd << "]:\n";
	for (size_t i = 1; i < result.size(); i++)
	{
		std::cout << "distance to [" << i << "]: " 
		          << result[i] << '\n';
	}
}

int main()
{
	testFunc();
	return 0;
}

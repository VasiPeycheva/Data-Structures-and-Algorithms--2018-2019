/*
* Author : Vasilena Peycheva
*/

#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

/*
* Create adjacency matrix of oriented graph with n vertices
*/
void createMatrix (vector<vector<bool>>& matrix, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i].push_back(0);
		}
	}
}

//add edge (i,j) in the oriented graph 
void addEdge(vector<vector<bool>> &matrix, int i, int j) {
	matrix[i][j] = 1;
}

//print "beautiful" adjacency matrix
void printMatrix(const vector<vector<bool>> & matrix) {
	std::cout << "       ";
	for (int j = 0; j < matrix.size(); j++)
	{
		std::cout << j << ' ';
	}
	std::cout << "\n       ";
	for (int j = 0; j < matrix.size()*2; j++)
	{
		std::cout << '-';
	}
	std::cout << '\n';
	for (int i = 0; i < matrix.size(); i++)
	{
		std::cout << "row[" << i << "]|";
		for (int j = 0; j < matrix[i].size(); j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

//print "beautiful" adjacency list
void printList(const vector<list<int>>& list) {
	for (int i = 0; i < list.size(); i++) {
		std::cout << "vertex [" << i << "] has successors : {";
		for (int v : list[i]) {
			std::cout << ' ' << v << ',';
		}
		std::cout << "} \n";
	}
}

/*
* Converts graph representation from given adjacency matrix to adjacency list
*/
void convert(const vector<vector<bool>>& matrix, vector<list<int>> & list) {
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 1)
				list[i].push_back(j);
		}
	}
}

void basicExample() {
	int n = 10;
	vector<vector<bool>> adjacencyMatrix(n);
	createMatrix(adjacencyMatrix, n);
	addEdge(adjacencyMatrix, 1, 2);
	addEdge(adjacencyMatrix, 4, 5);
	addEdge(adjacencyMatrix, 3, 4);
	addEdge(adjacencyMatrix, 1, 5);
	addEdge(adjacencyMatrix, 1, 7);
	addEdge(adjacencyMatrix, 8, 9);
	addEdge(adjacencyMatrix, 6, 7);
	addEdge(adjacencyMatrix, 7, 1);
	addEdge(adjacencyMatrix, 6, 9);
	addEdge(adjacencyMatrix, 6, 7);
	printMatrix(adjacencyMatrix);
	vector<list<int>> adjacencyList(n);
	convert(adjacencyMatrix, adjacencyList);
	printList(adjacencyList);
}

int main()
{
	basicExample();
	return 0;
}
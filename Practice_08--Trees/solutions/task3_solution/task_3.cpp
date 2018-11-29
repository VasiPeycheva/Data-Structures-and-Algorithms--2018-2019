/*
 * A solution to task 3 - check if two trees are isomorphic.
 * This file is part of the "Data structures and algorithms" course. FMI 2018/19
 *
 * Author : Ivan Filipov	
 */

#include <iostream> // std::cin, cout
#include <vector>   // std::vector
#include <string>   // std::string
#include <stdlib.h> // atoi()

using std::string;

// simple structure to represent every tree node
struct node {
	// the useless value
	int value  = 0;
	// number of sub trees
	int degree = 0;
	// used for the algorithm
    bool visited = false;
	// contains all sons of the current node
	std::vector<node> sons;
};

// returns true if two trees are isomorphic 
// first tree is T1 in the below comments, T2 is the second one
bool are_isomorphic(node& root_lhs, node& root_rhs) {
	// can't be isomorphic
	if (root_lhs.degree != root_rhs.degree)
		return false;
	// we have only leaves for sons
	if (root_lhs.degree == root_lhs.sons.size() &&
		root_rhs.degree == root_rhs.sons.size())
		return true;
	// we have leaves
     if (root_lhs.degree == 0) // T1.degree == T2.degree
		return true;
    // have we found a subtree in T2 isomorphic to a son of T1
	bool found = false;

	// searching for a son from T2 , which is isomorphic to a son form T1 
	for (size_t i = 0; i < root_lhs.sons.size(); i++) {
		found = false;
		for (size_t j = 0; j < root_rhs.sons.size() && !found; j++) {
			if (root_lhs.sons[i].degree == root_rhs.sons[j].degree &&
				root_rhs.sons[j].visited == false) {
				root_rhs.sons[j].visited = true;

				// checks the subtrees for isomorphism
				if (are_isomorphic(root_lhs.sons[i], root_rhs.sons[j]))
					found = true;
				else
					root_rhs.sons[j].visited = false;
			}
		}

		if (!found)
			return false;
	}
	// every subtree of T1 has an isomorphic tree in T2
	// then found == true
	return found;
}

// reading the input relaying on that 
// the given expression is a valid one
void read_tree(node& root, const string& input, size_t& strpos) {

	while (input[strpos] != '\0') {
		// reading the root
		if (input[strpos] == '(') {
			strpos++;
			// reading a number
			char num[12];
			int numpos = 0;

			while (isdigit(input[strpos]))
             	num[numpos++] = input[strpos++];
			
			num[numpos] = '\0';
			root.value = atoi(num);
		}

		// end of current tree
		if (input[strpos] == ')') {
			strpos++;
			return;
		}

		// reading sons of current root
		if (input[strpos] == '{') {
			strpos++;
			if (input[strpos] == '}')
				root.degree = 0;

			while (input[strpos] != '}') {
				node new_son;
				// adding the new son
				root.sons.push_back(new_son);
				size_t back_ind = root.sons.size() - 1;
				// reading the children of the current son
				read_tree(root.sons[back_ind], input, strpos);
				//adding the new degree to the root's one
				root.degree += root.sons[back_ind].degree + 1;
			}
			strpos++;
		}
	}
}

int main() {
	
	string input;
	size_t read_pos = 0;

	// roots of the two trees
	node first, second;

	std::cin >> input;

	read_tree(first, input, read_pos);

	input.clear();

	std::cin >> input;

	read_pos = 0;
	read_tree(second, input, read_pos);

	if (are_isomorphic(first, second))
		std::cout << "YES! \n";
	else
		std::cout << "NO! \n";

	return 0;
}

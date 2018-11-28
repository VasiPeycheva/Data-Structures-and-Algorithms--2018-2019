#include <fstream>
#include <iostream>

struct node {
	int data;
	node * right;
	node * left;
	node(int data, node * right = nullptr, node * left = nullptr)
		:data(data)
		, right(right)
		, left(left)
	{}
};

void insert(node *& root, int element) {
	if (!root) {
		root = new node(element);
		return;
	}
	if (root->data > element) {
		insert(root->left, element);
	}
	else {
		insert(root->right, element);
	}
}

void printSortedAsc(node * root) {
	if (root->left) {
		printSortedAsc(root->left);
	}
	std::cout << root->data << ' ';
	if (root->right) {
		printSortedAsc(root->right);
	}
}

void printSortedDesc(node * root) {
	if (root->right) {
		printSortedDesc(root->right);
	}
	std::cout << root->data << ' ';
	if (root->left) {
		printSortedDesc(root->left);
	}
}

void clean(node * root) {

	if (root->left) {
		clean(root->left);
	}
	if (root->right) {
		clean(root->right);
	}
	delete root;
}


void simpleTest(char * fileName) {
	std::fstream in(fileName);
	node * root = nullptr;
	int number;

	std::cout << "Original data: ";

	while (!in.eof()) {
		in >> number;
		insert(root, number);
		std::cout << number << ' ';
	}

	std::cout << "\n\n";
	std::cout << "Data in ascending order (right-root-left) \n";
	printSortedAsc(root);
	std::cout << "\n\n";

	std::cout << "Data in descending order (left-root-right) \n";
	printSortedDesc(root);
	std::cout << "\n\n";
	clean(root);
}

int main() {
	simpleTest("task1_data.txt");
	return 0;
}
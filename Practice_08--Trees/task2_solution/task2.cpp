#include <fstream>
#include <iostream>
#include <string>


struct node {
	int key;
	int subNodes;
	node* right;
	node* left;
	node(int key, node* right = nullptr, node* left = nullptr)
		:key(key)
		, subNodes(1)
		, right(right)
		, left(left)
	{}
};

bool search(node* root, int element) {

	if (root == nullptr) {
		return false;
	}
	if (root->key == element) {
		return true;
	}
	if (root->key < element) {
		return search(root->right,element);
	}
	else {
		return search(root->left,element);
	}
}

void insert_helper(node*& root, int element) {
	if (root == nullptr) {
		root = new node(element);
	} else if (root->key < element) {
		root->subNodes++;
		insert_helper(root->right, element);
	}
	if(root->key > element) {
		root->subNodes++;
		insert_helper(root->left, element);
	}
}

void insert(node*& root, int element) {
	if (search(root, element)) {
		return;
	}
	insert_helper(root, element);
}

void read(node*& root, std::ifstream& in) {
	int number;
	while (!in.eof()) {
		in >> number;
		insert(root, number);
	}
}

void write(node* root, std::ofstream& out) {
	if (root) {
		out << root->key << ' ';
	}
	if (root->left) {
		write(root->left, out);
	}
	if (root->right) {
		write(root->right, out);
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

int getSubTreeRec(node * root, int n) {
		if (root == nullptr || root->subNodes < n) {
			return 0;
		}
		else if (root->subNodes == n) {
			return 1;
		}
		else {  // root->subNodes > n
			return (getSubTreeRec(root->left,n) +
				   getSubTreeRec(root->right, n));
		}
}

void simpleTest() {
	std::ifstream in("task2.txt");
	std::ofstream out("task2_out.txt");
	node * root = nullptr;
	read(root, in);
	std::cout << "Number of leaves : " << getSubTree(root, 1) << '\n';
	std::cout << "Number of subtrees with 2 vertices :" << getSubTree(root, 2) << '\n';
	std::cout << "Number of subtrees with 5 vertices :" << getSubTree(root, 0) << '\n';
	write(root, out);
	clean(root);
	in.close();
	out.close();
}

int main() {
	simpleTest();
}

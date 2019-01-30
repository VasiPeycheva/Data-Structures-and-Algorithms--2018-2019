/*
* revision
*
* Author    : Vasilena Peycheva
* Co-author : Ivan Filipov
*/
#include <iostream>
#include <vector>
#include <queue>

struct node {
	int data;
	node* rightChild;
	node* leftChild;

	node(int dataInput, node* right = nullptr, node* left = nullptr)
		:data(dataInput)
		,rightChild(right)
		,leftChild(left)
	{}
};

/**
*	Help functions
*/

void clean(node * root) {
	if (root->leftChild) {
		clean(root->leftChild);
	}
	if (root->rightChild) {
		clean(root->rightChild);
	}
	delete root;
}

void add(node *& root, int data) {
	if (!root) {
		root = new node(data);
		return;
	}
	if (root->data >= data) {
		add(root->leftChild, data);
	}
	else {
		add(root->rightChild, data);
	}
}

//print the BST in order left-root-right
void printTree(node * root) {
	if (root->leftChild) {
		printTree(root->leftChild);
	}
	std::cout << root->data << ' ';
	if (root->rightChild) {
		printTree(root->rightChild);
	}
}

/* -------- TASK 1 -------- */

// complexity O(nlogn)
void buildBstRec(const std::vector<int>& sequence, node*& root ,int begining, int end) {
	if (begining >= end) {
		return;
	}
	int middle = (begining + end) / 2;
	add(root, sequence[middle]);
	buildBstRec(sequence, root, begining, middle);
	buildBstRec(sequence, root, middle + 1, end);
}

node * builtBst(const std::vector<int>& sequence) {
	node * root = nullptr;
	buildBstRec(sequence, root, 0, sequence.size());
	return root;
}

// complexity O(n)
node* buildBstRecLinear(const std::vector<int>& sequence, int begining, int end) {
	if (begining >= end) {
		return nullptr;
	}
	const int middle = (begining + end) / 2;
	node* root = new node(sequence[middle]);
	root->leftChild = buildBstRecLinear(sequence, begining, middle);
	root->rightChild = buildBstRecLinear(sequence, middle + 1, end);
	return root;
}

node * builtBstLinear(const std::vector<int>& sequence) {
	return buildBstRecLinear(sequence, 0, sequence.size());
}


/* -------- TASK 2 -------- */
node* getCommonAncestor(node *root, int A, int B) {
	if (root->data > A && root->data > B) {
		return getCommonAncestor(root->leftChild,A,B);
	}
	if (root->data < A && root->data < B) {
		return getCommonAncestor(root->rightChild,A,B);
	}
	return root;
}

/* -------- TASK 3 -------- */
node* findPredecessor(node* root, int key)
{
	if (root == nullptr || root->data == key) {
		return nullptr;
	}
	std::queue<node*> queue;
	queue.push(root);
	node* previous = nullptr;
	while (!queue.empty()) {
		node* current = queue.front();

		if (current->leftChild) {
			if (current->leftChild->data == key) {
				return queue.back();
			}
			else {
				queue.push(current->leftChild);
			}
		}
		if (current->rightChild) {
			if (current->rightChild->data == key) {
				return queue.back();
			}
			else {
				queue.push(current->rightChild);
			}
		}
		queue.pop();
	}
	return nullptr;
}

int main() {
	node * root = nullptr;

	std::vector<int> sequence;
	sequence.push_back(2);
	sequence.push_back(4);
	sequence.push_back(5);
	sequence.push_back(6);
	sequence.push_back(8);
	sequence.push_back(11);

	//task 1
	root = builtBst(sequence);
	std::cout << "Tree elements in order left-root-right: ";
	printTree(root);
	std::cout << '\n';

	//task 2
	int A = 2;
	int B = 11;
	node * common = getCommonAncestor(root, A, B);
	std::cout << "Common ancestor of " << A << " and " << B << " is "<< common->data << '\n';

	//task 3
	int key = 10;
	node * predecessor = findPredecessor(root, key);
	if (predecessor) {
		std::cout << "Predecessor of " << key << " is " << predecessor->data << '\n';
	}
	else {
		std::cout << key <<" does not have predecessor(root) or is not element of the tree!\n";
	}

	clean(root);

	return 0;
}

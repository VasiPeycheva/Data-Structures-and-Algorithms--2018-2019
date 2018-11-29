/*
 * A solution to task 4 - basic variant.
 * This file is part of the "Data structures and algorithms" course. FMI 2018/19
 *
 * Author : Ivan Filipov	
 */

#include <iostream> // std::cout, std::cerr
#include <fstream>  // std::ifstream used to read the file's contain

// represents a node in binary tree
struct node {

	unsigned int val;
	node* left_ptr;
	node* right_ptr;

	node(unsigned int v = 0, node* l = nullptr, node* r = nullptr) :
		val(v), left_ptr(l), right_ptr(r) {}

	// C++ 11 way to forbid compile-generated copy constructor and operator=
	node& operator=(const node&) = delete;
	node(const node&)            = delete;
};

// needed to free the allocated memory
void destroy_tree(node* root) {

	if (root == nullptr)
		return;

	destroy_tree(root->left_ptr);
	destroy_tree(root->right_ptr);

	delete root;
}

// 1 reading
// reading a tree from a file recursively 
node* read_tree_from_file(std::ifstream& ifs) {

	char c = ifs.get();

	if (!ifs.good())
		return nullptr;

	char next_char;

	if (c == '(') {
		// empty tree case
		next_char = ifs.get();

		if (next_char == ')')
			return nullptr;
		else
			ifs.unget(); // returning it back

		node* tree = new node;

		// reading the value in the root
		ifs >> tree->val;

		// reading left subtree
		tree->left_ptr = read_tree_from_file(ifs);

		if (tree->left_ptr)
			ifs.get(); // reading the ')' bracket on the way back 

		// reading right subtree
		tree->right_ptr = read_tree_from_file(ifs);

		if (tree->left_ptr)
			ifs.get(); // reading the ')' bracket on the way back 

		return tree;
	}
	else
		return nullptr; // some kind of error in the input...
}

// 2 bloom tree
void bloom_tree(node* root) {

	if (root == nullptr)
		return;
	// is leaf
	if (root->left_ptr  == nullptr &&
		root->right_ptr == nullptr) {
		root->left_ptr  = new node(root->val);
		root->right_ptr = new node(root->val);

		return;
	}

	// else try it's children
	bloom_tree(root->left_ptr);
	bloom_tree(root->right_ptr);
}

// 3 accumulate tree
unsigned int accum_tree(const node* root) {

	if (root == nullptr)
		return 0;

	return root->val + accum_tree(root->left_ptr)
			         + accum_tree(root->right_ptr);
}

void test_tree_from_file(const char* file_path) {

	if (file_path == nullptr)
		return;

	std::cout << "reading the tree from " << file_path
		<< std::endl;

	std::ifstream ifs(file_path);

	if (!ifs.is_open()) {
		std::cerr << "can't open the file!" << std::endl;
		return;
	}

	node* root = read_tree_from_file(ifs);

	if (root == nullptr) {
		std::cerr << "empty tree or invalid file!" << std::endl;
		return;
	}

	unsigned int first_sum = accum_tree(root);
	std::cout << "accumulate : " << first_sum
		<< std::endl;

	bloom_tree(root);
	std::cout << "after blooming the tree" << std::endl;

	unsigned int second_sum = accum_tree(root);
	std::cout << "accumulate : " << second_sum
		<< std::endl;

	std::cout << "accum(T\') - accum(T) = " 
		<< second_sum - first_sum
		<< std::endl;

	// cleaning everything
	destroy_tree(root);
	root = nullptr;
	ifs.close();

	std::cout << std::endl;
}


int main() {

	test_tree_from_file("../tree.txt");

	test_tree_from_file("../tree1.txt");
	
	return 0;
}

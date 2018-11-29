/*
 * A solution to task 4 - advanced variant.
 * This file is part of the "Data structures and algorithms" course. FMI 2018/19
 *
 * Author : Ivan Filipov	
 */
 

#include <iostream> // std::cout, std::cerr
#include <fstream>  // std::ifstream
#include <math.h>   //log10
// needed for pretty_print
#include<queue> // std::queue, std::pair

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

//2 bloom tree + bonus
// helper test function
unsigned int inc(unsigned int x) {

	return x + 1;
}
template<typename Functor>
void bloom_tree(node* root, Functor f) {

	if (root == nullptr)
		return;
	// is leaf
	if (root->left_ptr  == nullptr &&
		root->right_ptr == nullptr) {
		root->left_ptr  = new node(f(root->val));
		root->right_ptr = new node(f(root->val));

		return;
	}

	// else try it's children
	bloom_tree(root->left_ptr, f);
	bloom_tree(root->right_ptr, f);
}

// 3 accumulate tree + bonus
typedef unsigned long long ull_int;
// helper test function
ull_int mul(ull_int x, ull_int y) {

	return x * y;
}

template<typename Functor>
ull_int accum_tree(const node* root, ull_int beg, Functor f) {

	if (root == nullptr)
		return beg;

	return f(root->val, f(accum_tree(root->left_ptr, beg, f),
						accum_tree(root->right_ptr, beg, f)));
}

// pretty printing bonus

// calculates a tree's height
unsigned int get_height(node* root) {

	if (root == nullptr)
		return 0;

	unsigned int left_sub_tree_height  = get_height(root->left_ptr);
	unsigned int right_sub_tree_height = get_height(root->right_ptr);

	return 1 + ((left_sub_tree_height > right_sub_tree_height) ?
				left_sub_tree_height :
				right_sub_tree_height);
}

// finds the biggest element in the tree
unsigned int find_max_elem(node* root) {

	if (root == nullptr)
		return 0;

	unsigned int res = root->val;

	unsigned int left_res = find_max_elem(root->left_ptr);
	unsigned int right_res = find_max_elem(root->right_ptr);

	if (left_res > res)
		res = left_res;

	if (right_res > res)
		res = right_res;

	return res;
}

void pretty_print(node* root) {

	std::cout << "\nthe tree looks something like this :\n\n";

	unsigned int height = get_height(root);

	unsigned int cur_level = 0;

	// how many spaces between the elements : 

	// the maximum value of children in a binary tree
	// with height h is 2 ^ ( h - 1) why?
	unsigned int max_children = 1 << (height - 1);
	// we will have at least one space between each children
	max_children <<= 1; // *= 2
	// which is the longest number
	unsigned int max_elem = find_max_elem(root);
	// how many digits it has
	unsigned int max_digits = static_cast<unsigned int>(log10(max_elem) + 1);
	// how many cells do we need in each line
	unsigned int indent = max_children * (max_digits + 1) - 1;

	// preforming BFS - pushing nodes form the tree and
	// empty ones in order to make the 'draw' easier

	// key - level of node
	std::queue<std::pair<node*, unsigned int>> wave;

	wave.push(std::make_pair(root, cur_level + 1));

	while (cur_level <= height) {
		if (cur_level < wave.front().second) {
			cur_level = wave.front().second;
			std::cout << std::endl;
			if (cur_level > height)
				return;
			// on each line below indent will be index / 2
			indent >>= 1;
		}

		for (unsigned int i = 0; i < indent; i++)
			std::cout << ' ';

		if (wave.front().first != nullptr)
			std::cout << wave.front().first->val;
		else
			std::cout << ' '; // empty node

		for (unsigned int i = 0; i <= indent; i++)
			std::cout << ' ';

		// if real node, pushing its children into the wave
		if (wave.front().first != nullptr) {
			if (wave.front().first->left_ptr != nullptr)
				wave.push(std::make_pair(wave.front().first->left_ptr,
					wave.front().second + 1));
			else
				wave.push(std::make_pair(nullptr, wave.front().second + 1));

			if (wave.front().first->right_ptr != nullptr)
				wave.push(std::make_pair(wave.front().first->right_ptr,
					wave.front().second + 1));
			else
				wave.push(std::make_pair(nullptr, wave.front().second + 1));

		} else { // fake node
			// pushing two fake children
			wave.push(std::make_pair(nullptr, wave.front().second + 1));
			wave.push(std::make_pair(nullptr, wave.front().second + 1));
		}

		wave.pop();
	}
}


int main() {

	std::ifstream ifs("../tree.txt");

	std::cout << "the tree from file tree.txt\n";

	if (!ifs.is_open()) {
		std::cerr << "can't open the file\n";
		return -1;
	}

	node* root = read_tree_from_file(ifs);

	pretty_print(root);

	ull_int first_res = accum_tree(root, 0, [](ull_int lhs, ull_int rhs) -> ull_int {
												return lhs + rhs;
	});
	std::cout << "accumulate with sum function : " << first_res;

	bloom_tree(root, [](ull_int x) { return x; });
	std::cout << "\nafter blooming with identity function T\': \n";
	pretty_print(root);

	ull_int second_res = accum_tree(root, 0, [](ull_int lhs, ull_int rhs) -> ull_int {
												return lhs + rhs;
	});
	std::cout << "\naccumulate with sum function : "
		  << second_res;

	std::cout << "\naccum(T\') - accum(T) = "
		  << second_res - first_res;

	// cleaning everything
	destroy_tree(root);
	root = nullptr;
	ifs.close();

	// testing another tree and bonus functions 
	ifs.open("../tree1.txt");

	std::cout << "\n\n\nthe tree from file tree1.txt\n";

	if (!ifs.is_open()) {
		std::cerr << "can't open the file\n";
		return -1;
	}

	root = read_tree_from_file(ifs);

	pretty_print(root);

	first_res = accum_tree(root, 1, mul);
	std::cout << "\naccumulate with multiply function : "
		  << first_res;

	bloom_tree(root, inc);
	std::cout << "\nafter blooming with +1 function T\': \n";
	pretty_print(root);

	second_res = accum_tree(root, 1, mul);
	std::cout << "\naccumulate with multiply function : "
 		  << second_res;
 
	std::cout << "\naccum(T\') - accum(T) = "
		  << second_res - first_res;
	
	// notice that these memory releases may be unnecessary
	destroy_tree(root);
	root = nullptr;
	ifs.close();

	return 0;
}

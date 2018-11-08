// C++ style solution. Example like - only the
// necessary stuff, written in the neck of time 

#include <iostream> // std::cout, std::endl
#include <stdlib.h> // rand(), srand()
#include <time.h>   // time()

// represents a single box
struct node {
	
	int   data;
	node* next_ptr;
	
	node(int d, node* p = nullptr) : data(d), next_ptr(p) {}
};

// the linked list structure
struct linked_list {
	
	node* front_ptr = nullptr; //default values ( C++11 after style )
	node* back_ptr = nullptr;
};

// checks if a linked list is empty
bool is_empty(const linked_list& context) {
	
	return (context.front_ptr == context.back_ptr) &&
			(context.front_ptr == nullptr);
}

// connects an existing box 'n' at the end of a list 'context'
void list_push_back_node(linked_list& context, node* n) {
	
	if(is_empty(context)) {
		
		context.front_ptr = n;
		context.back_ptr = context.front_ptr;
		return;
	}
	
	context.back_ptr->next_ptr = n;
	context.back_ptr = n;
}

// creates a new node, containing 'data', at the end of a list
void list_push_front(linked_list& context, int d) {
	
	if(is_empty(context)) {
		
		context.front_ptr = new node(d);
		context.back_ptr = context.front_ptr;
		return;
	}
	
	node* new_el = new node(d);
	new_el->next_ptr = context.front_ptr;
	context.front_ptr = new_el;
}

// destructor
void list_clear(linked_list& context) {
	
	if(is_empty(context)) return;
	
	node* d = context.front_ptr;
	
	while(d) {
		
		context.front_ptr = context.front_ptr->next_ptr;
		delete d;
		d = context.front_ptr;
	}
	
	context.front_ptr = nullptr;
	context.back_ptr = nullptr;
}

// appends list 's' to list 'f'
void append_lists(linked_list& f, const linked_list& s) {
	
	if(is_empty(f)) {
			
		f = s; //steal others data
		return;
	}
	
	f.back_ptr->next_ptr = s.front_ptr;
	f.back_ptr = s.back_ptr;
}

// just outputs a linked list
void print_list(const linked_list& context) {
	
	node* it = context.front_ptr;
	while(it) {
		
		std::cout << it->data << ' ';
		it = it->next_ptr;
	}
	std::cout << std::endl;
}

// the real task solving function
void divide_list(linked_list& list) {
	//creating two new empty lists, with memory O(1) -> just four pointers
	linked_list odds, evens;
	// for each element of the list -> O(n), where n is the size of the given list
	while(list.front_ptr != nullptr) {
		// decide in which part it belongs
		linked_list& in_which = (list.front_ptr->data % 2 == 0) ? evens : odds;
		// connect the box in the end of odd or even part. Memory O(1), Speed O(1)
		list_push_back_node(in_which, list.front_ptr);
		// remember where the box is
		node* broke_chain = list.front_ptr;
		// make forward step
		list.front_ptr = list.front_ptr->next_ptr;
		// disconnect the box from the other elements of the original list 
		broke_chain->next_ptr = nullptr;
	}
	// append the result lists into list evens, Memory O(1), Speed O(1)
	append_lists(evens, odds);
	// copy the pointers of the result list into the given one, Memory O(1), Speed O(1)
	list = evens;
	// TOTAL COMPLEXYTY : Memory O(1), Speed O(n)
}

void test_only_even() {
	
	std::cout << "TESTING WITH EVEN NUMBERS ONLY\n";
	linked_list ll;
	list_push_front(ll, 3);
	list_push_front(ll, 19);
	list_push_front(ll, 5);
	list_push_front(ll, 61);
	list_push_front(ll, 7);
	list_push_front(ll, 83);
	
	std::cout << "input : ";
	print_list(ll);
	
	divide_list(ll);
	std::cout << "output : ";
	print_list(ll);
	
	std::cout << "------------------------------\n";
	
	list_clear(ll);
}

void test_only_odd() {
	
	std::cout << "TESTING WITH ODD NUMBERS ONLY\n";
	linked_list ll;
	list_push_front(ll, 32);
	list_push_front(ll, 4);
	list_push_front(ll, 50);
	list_push_front(ll, 6);
	list_push_front(ll, 76);
	list_push_front(ll, 8);
	
	std::cout << "input : ";
	print_list(ll);
	
	divide_list(ll);
	std::cout << "output : ";
	print_list(ll);
	
	std::cout << "------------------------------\n";
	list_clear(ll);
}

void test_random() {
	
	std::cout << "TESTING WITH RANDOM NUMBERS\n";
	linked_list ll;
	
	for(int i = 0; i < 10; i++) 
		list_push_front(ll, rand() % 100);
	
	std::cout << "input : ";
	print_list(ll);
	
	divide_list(ll);
	std::cout << "output : ";
	print_list(ll);
	
	std::cout << "------------------------------\n";
	list_clear(ll);
}


int main() {
	
	/* seed the random generator */
	srand(time(nullptr));
	/* try what happens when there are only even number */
	test_only_even();
	/* and the case with only odd elements */
	test_only_odd();
	/* general case test */
	test_random();
	
	return 0;
}

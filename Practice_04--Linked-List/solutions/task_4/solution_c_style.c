// C style solution. Example like - only the
// necessary stuff, written in the neck of time 

#include <stdio.h>  // printf(), putchar()
#include <stdlib.h> // rand(), srand(), malloc(), free()
#include <time.h>   // time()
#include <stdbool.h> // bool in C

// represents a single box
typedef struct node {
	
	int              data;
	struct node* next_ptr;
} node;

// a C - style constructor
node* create_node(int data) {
	
	node* n = malloc(sizeof(node));
	n->data = data;
	n->next_ptr = NULL;
	
	return n;
}

// the linked list structure
typedef struct {
	
	node* front_ptr;
	node* back_ptr;
} linked_list;

// checks if a linked list is empty
bool is_empty(linked_list* const context) {
	
	return  (context->front_ptr == context->back_ptr) && 
			(context->front_ptr == NULL);
}

// attaches a node in the back of a list
void list_push_back_node(linked_list* context, node* n) {
	
	if(is_empty(context)) {
		
		context->front_ptr = n;
		context->back_ptr = context->front_ptr;
		return;
	}
	
	context->back_ptr->next_ptr = n;
	context->back_ptr = n;
}

// creates a new node, containing 'data', in front of a list
void list_push_front(linked_list* context, int data) {
	
	if(is_empty(context)) {
		
		context->front_ptr = create_node(data);
		context->back_ptr = context->front_ptr;
		return;
	}
	
	node* new_el = create_node(data);
	new_el->next_ptr = context->front_ptr;
	context->front_ptr = new_el;
}

// C - style destructor
void list_clear(linked_list* context) {
		
	node* destoyer = context->front_ptr;
	
	while(destoyer) {
		
		context->front_ptr = context->front_ptr->next_ptr;
		free(destoyer);
		destoyer = context->front_ptr;
	}
	
	context->front_ptr = NULL;
	context->back_ptr = NULL;
}

// appends list 's' to list 'f'
void append_lists(linked_list* f, linked_list* s) {
	
	if(is_empty(f)) {
			
		*f = *s; //steal others data
		return;
	}
	
	f->back_ptr->next_ptr = s->front_ptr; // connect them
	f->back_ptr = s->back_ptr; // change the back  
}

// just outputs a linked list
void print_list(linked_list* const context) {
	
	node* it = context->front_ptr;
	while(it) {
		
		printf("%d ", it->data);
		it = it->next_ptr;
	}
	putchar('\n');
}

// the real task solving function
void devide_list(linked_list* list) {
	
	// creating two new empty lists, with memory O(1) -> just four pointers
	linked_list odds = {.front_ptr = NULL, .back_ptr = NULL };
	linked_list evens = {.front_ptr = NULL, .back_ptr = NULL };
	
	// for each element of the list -> O(n), where n is the size of the given list
	while(list->front_ptr != NULL) {
		// decide in which part it belongs
		linked_list* in_which = (list->front_ptr->data % 2 == 0) ? &evens : &odds;
		// connect the box in the end of odd or even part. Memory O(1), Speed O(1)	
		list_push_back_node(in_which, list->front_ptr);
		// remember where the box is
		node* broke_chain = list->front_ptr;
		// make forward step
		list->front_ptr = list->front_ptr->next_ptr;
		// disconnect the box from the other elements of the original list 
		broke_chain->next_ptr = NULL;
	}
	// append the result lists into list evens, Memory O(1), Speed O(1)
	append_lists(&evens, &odds);
	// copy the pointers of the result list into the given one, Memory O(1), Speed O(1)
	*list = evens; 
	
	// TOTAL COMPLEXYTY : Memory O(1), Speed O(n)
}

void test_only_even() {
	
	printf("TESTING WITH EVEN NUMBERS ONLY\n");
	linked_list ll = {.front_ptr = NULL, .back_ptr = NULL };
	
	list_push_front(&ll, 3);
	list_push_front(&ll, 19);
	list_push_front(&ll, 5);
	list_push_front(&ll, 61);
	list_push_front(&ll, 7);
	list_push_front(&ll, 83);
	
	printf("input : ");
	print_list(&ll);
	
	devide_list(&ll);
	printf("output : ");
	print_list(&ll);
	
	printf("------------------------------\n");
	
	list_clear(&ll);
}

void test_only_odd() {
	
	printf("TESTING WITH EVEN NUMBERS ONLY\n");
	linked_list ll = {.front_ptr = NULL, .back_ptr = NULL };
	
	list_push_front(&ll, 32);
	list_push_front(&ll, 4);
	list_push_front(&ll, 50);
	list_push_front(&ll, 6);
	list_push_front(&ll, 76);
	list_push_front(&ll, 8);
	
	printf("input : ");
	print_list(&ll);
	
	devide_list(&ll);
	printf("output : ");
	print_list(&ll);
	
	printf("------------------------------\n");
	list_clear(&ll);
}

void test_random() {
	
	printf("TESTING WITH RANDOM NUMBERS\n");
	linked_list ll = {.front_ptr = NULL, .back_ptr = NULL };
	
	for(int i = 0; i < 10; i++) 
		list_push_front(&ll, rand() % 100);
	
	printf("input : ");
	print_list(&ll);
	
	devide_list(&ll);
	printf("out : ");
	print_list(&ll);
	
	printf("------------------------------\n");
	list_clear(&ll);
}


int main() {
	
	/* seed the random generator */
	srand(time(NULL));
	/* try what happens when there are only even number */
	test_only_even();
	/* and the case with only odd elements */
	test_only_odd();
	/* general case test */
	test_random();
	
	return 0;
}






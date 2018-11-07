/*
 * A solution to Hanoi tower's task. Used algorithm : https://en.wikipedia.org/wiki/Tower_of_Hanoi - Recursive solution
 * This file is part of the "Data structures and algorithms" course. FMI 2018/19
 *
 * Author : Ivan Filipov	
 */
#include <iostream>
#include <stack> // include your own version of stack, it is important to support
				 // push, pop, top, empty methods

// just for easier writing
typedef std::stack<int> tower;
// the three towers
tower At, Bt, Ct;
// how many elements in each tower
const int ECOUNT = 4; 

// make a step, moving the top of "src" to "des"
void move(tower& src, tower& des) {

	des.push(src.top());
	src.pop();
}

char char_from_tower(int level, tower& t) {
	
	char ret;
	if (t.size() == level) {
		ret = (t.top() + '0');
		t.pop();
	}
	else
		ret = ' ';
	return ret;
}

void print_current(tower A, tower B, tower C) {// a copies on purpose
	
	char a, b, c;
	std::cout << "current towers : \n";
	for(int i = ECOUNT; i > 0; i--) {
			
		a = char_from_tower(i, A);
		b = char_from_tower(i, B);
		c = char_from_tower(i, C);  
		std::cout << "| " << a << "| | " << b << "| | " << c << "|\n" 
	              << "|__| |__| |__|\n";
	}
}
void solve_Hanoi(tower& A, tower& C, tower& B, int step) {
	
	if (step == 1) {
			
		move(A, C);
		print_current(At, Bt, Ct); // using the global variables, due to correct order
		return;
	}
	
	solve_Hanoi(A, B, C , step - 1);
	
	move(A, C);
	print_current(At, Bt, Ct);
	
	solve_Hanoi(B, C, A, step - 1);
}


int main() {

	for (int i = ECOUNT; i > 0; --i) {

		At.push(i);
	}
	print_current(At, Bt, Ct);
	solve_Hanoi(At, Ct, Bt, At.size());
	std::cout << "\n\nresult in C \n";
	for(int i = Ct.size(); i > 0; i--) {
		std::cout << "| " << Ct.top() << "|\n"
	              << "|__|\n";
		Ct.pop();
	}

	return 0;
}

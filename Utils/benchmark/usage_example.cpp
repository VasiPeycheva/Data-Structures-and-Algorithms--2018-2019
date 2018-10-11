//simple example how to use the benchmark library

#include <math.h>
//in your application just include the header and
//call "benchmark_test_fnc" with parameter the function
//you want to test
#include "benchmark.hpp"

void sum_sq_large() {
	
	unsigned long long int sum = 1;
	for(unsigned long long i = 2; i < 1000000; i++)
		sum += sqrt(i); //sum probably overflows, but not important for the example
}

class Calc_sum_sq {

public :
	void operator() () const {
		
		unsigned long long int sum = 1;
		for(unsigned long long i = 2; i < 1000000; i++)
			sum += sqrt(i); //sum probably overflows, but not important for the example
	}
} calc_obj;


int main() {

	//ordinary function
	//without function's name
	benchmark_test_fnc(sum_sq_large);
	//with function's name
	benchmark_test_fnc(sum_sq_large, fnc_name_to_str(sum_sq_large));
	
	//object with operator() with custom name
	benchmark_test_fnc(calc_obj, fnc_name_to_str(calc_obj.operator()));
	
	//lambda function
	benchmark_test_fnc([](){ 
		unsigned long long int sum = 1;
		for(unsigned long long i = 2; i < 1000000; i++)
			sum += sqrt(i); //sum probably overflows, but not important for the example
	});

	return 0;
}

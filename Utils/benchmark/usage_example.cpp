//simple example how to use the benchmark library

#include <math.h>

/*
basic : 
in your application just include the header and
call "benchmark_test_fnc" with parameter the function
you want to test
*/

/*
advanced :
there are three more parameters : 
 1) first is a time formatter - one from                       ( F_MICRO, F_MILLI, F_SEC, F_MIN, F_ALL )
	using this parameter the time will be formatted as follow : microseconds, milliseconds, seconds, minutes, all formated
	[default] : F_MICRO
	
 2) second is a name - just a string for easier output understanding
	fnc_name_to_str - could be used to create a string from function's name
	[default] : "" empty string, so nothing will be outputted
	
 3) output stream - could be each from C++ out streams
    [default] : std::cout 
*/
#include "benchmark.hpp"

void sum_sq_large() {
	
	unsigned long long int sum = 1;
	for(unsigned long long i = 2; i < 10000000; i++)
		sum += sqrt(i); //sum probably overflows, but not important for the example
}
 
class calc_sum_sq {
public :
	void operator() () const {
		
		unsigned long long int sum = 1;
		for(unsigned long long i = 2; i < 10000000; i++)
			sum += sqrt(i); //sum probably overflows, but not important for the example
	}
} calc_obj;


 int main() {
	
	std::cout << "Testing with different time formats :" << std::endl;
	//ordinary function
	//without function's name
	//using different time formats
	benchmark_test_fnc(sum_sq_large, T_FORMAT::F_MICRO);
	benchmark_test_fnc(sum_sq_large, T_FORMAT::F_MILLI);
	benchmark_test_fnc(sum_sq_large, T_FORMAT::F_SEC);
	benchmark_test_fnc(sum_sq_large, T_FORMAT::F_MIN);
	benchmark_test_fnc(sum_sq_large, T_FORMAT::F_ALL);
	
	std::cout << "------------------------------------" << std::endl
			  << "Testing other options :" << std::endl;
	
	//with function's name
	benchmark_test_fnc(sum_sq_large, T_FORMAT::F_MICRO, fnc_name_to_str(sum_sq_large));
	//object with operator() with custom name
	benchmark_test_fnc(calc_obj, T_FORMAT::F_MICRO, fnc_name_to_str(calc_obj.operator()));
	
	//lambda function
	benchmark_test_fnc([](){ 
		unsigned long long int sum = 1;
		for(unsigned long long i = 2; i < 10000000; i++)
			sum += sqrt(i); //sum probably overflows, but not important for the example
	});
 	return 0;
}

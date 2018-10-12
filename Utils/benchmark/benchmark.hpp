//a basic benchmarking generic function
//for the students to test their own algorithms

#pragma once

#include <chrono>
#include <iostream>
#include <string>

//a function which receives Functor as a parameter
//runs it and outputs the microseconds that running took

//Functor could be :
// - ordinary function
// - an object from class which implements operator()
// - a lambda function ( we will talk about them throughout the semester ) 

#define fnc_name_to_str(f) #f

template<typename Functor>
void benchmark_test_fnc(Functor f, const std::string& name = "", std::ostream& os = std::cout) {

//using some dark c++ 11 magic to calculate the time 
//needed from the function in microseconds
//1 second = 1000* 1 millisecond = 1000 * 1000 * 1 microsecond 
//the running time may vary to your machine's current available resources

	//starting time
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	//run the function
	f();
	
	//end time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	
	//output human readable results
	if (!name.empty()) os << '[' << name << "] ";
	
	os << "running took : "
	   <<  std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
	   << " microseconds" << std::endl;
}

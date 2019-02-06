/**
*
* @author Vasilena Peycheva
* @compiler VC
*
*/

#include <iostream>
#include <fstream>
#include "Student.h"
#include "DynamicArray.h"
#include "StudentsTable.h"

#include <string>

int main(int argc, char *argv[])
{
	StudentsTable table(argv[1]);
	table.sortBy(argv[2], argv[3]);

	return 0;
}

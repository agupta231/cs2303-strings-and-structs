#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {
	// Create test employees
	struct Employee* mike = makeEmployee(1952, 1999, "Mike Ciaraldi");
	struct Employee* ankur = makeEmployee(1999, 2008, "Ankur Gupta");

	// Print out the employees in a human readable format
	printf("Printing out Employees in a human readable format: \n");
	printEmployee(mike);
	printEmployee(ankur);

	// Generate and print out random employees
	printf("\nPrinting out randomly generated employees");
	printEmployee(randomEmployee());
	printEmployee(randomEmployee());
	printEmployee(randomEmployee());

	// Create an array of random employees
	struct Employee** eBase = randomArray(20);
	
	// Print out the arry of random employees
	printf("\nPrinting out a randomly generated array of random Employees\n");
	printEmployeeArray(eBase, 20);

	// Shallow copy the random employee array
	struct Employee** sCopy = shallowCopy(eBase, 20);

	// Print out the shallow copied array, as well as explainations to show how it
	// works
	printf("\nPrinting out the shallow copied array. ");
	printf("You can tell that it is a shallow copy becuase the pointer address ");
	printf("changes, but the memory of the struct and name char array remain untouched.\n");
	printEmployeeArray(sCopy, 20);

	// Deep copy the random employee array. Please note that I am NOT copying the
	// shallow copied array in order to keep things constant
	sCopy = deepCopy(eBase, 20);

	// Print out the deep copied array. Also print out the explainations to show
	// how it work
	printf("\nPrinting out the deep copied array. ");
	printf("You can tell that is a deep copy becuase all of the memory addresses ");
	printf("have been changed.\n");
	printEmployeeArray(sCopy, 20);

	// Attempt to delete the array. If there is an issue, there should be a
	// segfault.
	printf("\nAbout to delete the Employees array. If there are no errors, that ");
	printf("means that the function ran properly.\n");
	deleteEmployeesArray(sCopy, 20);

	return 0;
}

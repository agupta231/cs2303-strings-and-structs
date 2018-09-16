#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {

	struct Employee* mike = makeEmployee(1952, 1999, "Mike Ciaraldi");
	struct Employee* ankur = makeEmployee(1999, 2008, "Ankur Gupta");

	printf("Printing out Employees in a human readable format: \n");
	printEmployee(mike);
	printEmployee(ankur);

	printf("\nPrinting out randomly generated employees");
	printEmployee(randomEmployee());
	printEmployee(randomEmployee());
	printEmployee(randomEmployee());

	struct Employee** eBase = randomArray(20);
	
	printf("\nPrinting out a randomly generated array of random Employees\n");
	printEmployeeArray(eBase, 20);

	struct Employee** sCopy = shallowCopy(eBase, 20);

	printf("\nPrinting out the shallow copied array. ");
	printf("You can tell that it is a shallow copy becuase the pointer address ");
	printf("changes, but the memory of the struct and name char array remain untouched.\n");
	printEmployeeArray(sCopy, 20);

	sCopy = deepCopy(eBase, 20);

	printf("\nPrinting out the deep copied array. ");
	printf("You can tell that is a deep copy becuase all of the memory addresses ");
	printf("have been changed.\n");
	printEmployeeArray(sCopy, 20);

	printf("\nAbout to delete the Employees array. If there are no errors, that ");
	printf("means that the function ran properly.\n");
	deleteEmployeesArray(sCopy, 20);

	return 0;
}

#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {

	struct Employee* mike = makeEmployee(1952, 1999, "Mike Ciaraldi");
	struct Employee* ankur = makeEmployee(1999, 2008, "Ankur Gupta");

	printEmployee(mike);
	printEmployee(ankur);
	printEmployee(randomEmployee());
	printEmployee(randomEmployee());
	printEmployee(randomEmployee());

	struct Employee** eBase = randomArray(20);
	
	printf("Rando array:\n");
	printEmployeeArray(eBase, 20);

	struct Employee** sCopy = shallowCopy(eBase, 20);

	printf("Shallow Copied array:\n");
	printEmployeeArray(sCopy, 20);

	deleteEmployeesArray(sCopy, 20);
	return 0;
}

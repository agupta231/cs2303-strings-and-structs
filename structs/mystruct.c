/** mystruct.c
 * @author Mike Ciaraldi
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

int nameLength = 10;

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee* e = (struct Employee*) malloc(sizeof(struct Employee));
	e->birth_year = birth;
	e->start_year = start;
	strcpy(e->name, name);

	return e;
}

/**
 *
 */
void printEmployee(struct Employee *e) {
	printf(
			"Employee %s was born in %d and started in %d.\n",
			e->name,
			e->birth_year,
			e->start_year);
}

int randomAge() {
	int offset = rand() % 119;
	return offset + 1900;
}

char* randomName(int length) {
	char* name = (char*) malloc(sizeof(char) * (length + 1));

	for(int i = 0; i < length; i++) {
		name[i] = 'A' + (rand() % 26);
	}

	name[length] = '\0';

	return name;
}

struct Employee* randomEmployee() {
	return makeEmployee(randomAge(), randomAge(), randomName(nameLength));
}

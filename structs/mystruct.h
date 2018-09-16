/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

typedef struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
} Employee;

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
struct Employee* randomEmployee();
struct Employee** randomArray(int count);
void printEmployeeArray(struct Employee** arr, int count);
struct Employee** shallowCopy(struct Employee** old, int count);
void deleteEmployeesArray(struct Employee** arr, int count);
struct Employee** deepCopy(struct Employee** old, int count);

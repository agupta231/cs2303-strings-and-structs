#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * @author Ankur Gupta
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
	char a1[MAX_CHARS + 1]; // Character array--initially empty
	char a2[] = "Hello"; // Character array--unsized but initialized
	char a3[MAX_CHARS + 1]; // Character array--we will underfill it
	char* p1 = "Hello"; // Pointer to constant string
	char* p2 = NULL;           // Will be a pointer to dynamically-allocated string
	char* p3 = "Hi"; // Pointer to another constant string
	int copy_limit;     // Maximum characters to copy.

	strcpy(a3, "Hello, one more time."); // Initialize underfilled character array

	/* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
	 */
	printf("Initial state:\n");
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
	printf("          p1 = %p p2 = %p\n", p1, p2);

	strcpy(a1, p3); // Initialize character array

	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
	printf("a3 = %s\n", a3);

	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("For string /%s/, strlen() returns %ld\n", p1, strlen(p1));
	printf("For string /%s/, mystrlen1() returns %ld\n", p1, mystrlen1(p1));
	printf("For string /%s/, mystrlen2() returns %ld\n", p1, mystrlen2(p1));

	// Duplicate a string, using strdup(), then print
	printf("\nBefore calling strdup(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = strdup(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function, then print
	printf("\nBefore calling mystrdup1(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = mystrdup1(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function, then print
	printf("\nBefore calling mystrdup2(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = mystrdup2(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';

	// Concatenate two character arrays, then print.
	strcpy(a1, p3); // Reset character array
	strcat(a1, a2);
	printf("Using strcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays safely, then print.
	strcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf("Using strncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0) strncat(a1, a3, copy_limit);
	printf("a1 = %s\n", a1);

	// Copy a string using mystrcopy
	printf("\n\n=== START mystrcpy ====\n");

	char *z1 = "Hello, World!"; // Create test string
	char xs[15]; // Create unitilized array of correct size
	char *z2 = xs; // Create a pointer to the array

	printf("Before mystrcpy:\n");
	printf("Pointer z1 = %p, contents = %s\n", z1, z1);
	printf("Pointer z2 = %p, contents = %s\n", z2, z2);
	
	mystrcpy(z2, z1);

	printf("\n\nAfter mystrcpy:\n");
	printf("Pointer z1 = %p, contents = %s\n", z1, z1);
	printf("Pointer z2 = %p, contents = %s\n", z2, z2);

	printf("=== END mystrcpy ====\n");


	// Concatenate two character arrays, then print.
	printf("\n\n=== START mystrcat ====\n");
	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';

	strcpy(a1, p3); // Reset character array
	mystrcat(a1, a2);
	printf("Using mystrcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	printf("=== END mystrcat ====\n");


	// Start mystrncat
	printf("\n\n=== START mystrncat ====\n");

	// Initialize strings
	char a_lenShorterThan[20] = "Hello";
	char a_lenShorterThan_my[20] = "Hello";
	char a_exactly[20] = "Hello";
	char a_exactly_my[20] = "Hello";
	char a_greater[20] = "Hello";
	char a_greater_my[20] = "Hello";
	char b_6[6] = "World";

	// Do a variable dump so that one can see the state of the whole system before
	// it is modified
	printf("Variable configuration before running mystrncat\n");
	printf("str a_lenShorterThan: address = %p, value = %s\n", 
			a_lenShorterThan, 
			a_lenShorterThan);
	printf("str a_lenShorterThan_my: address = %p, value = %s\n", 
			a_lenShorterThan_my, 
			a_lenShorterThan_my);
	printf("str a_exactly: address = %p, value = %s\n", 
			a_exactly, 
			a_exactly);
	printf("str a_exactly_my: address = %p, value = %s\n", 
			a_exactly_my, 
			a_exactly_my);
	printf("str a_greater: address = %p, value = %s\n", 
			a_greater, 
			a_greater);
	printf("str a_greater_my: address = %p, value = %s\n", 
			a_greater_my, 
			a_greater_my);
	printf("str b_6: address = %p, value = %s\n", b_6, b_6);
	

	printf("Concat a string when the length of the string is shorter than n\n");
	strncat(a_lenShorterThan, b_6, 8);
	mystrncat(a_lenShorterThan_my, b_6, 8);

	printf("str a_lenShorterThan: address = %p, value = %s\n", 
			a_lenShorterThan, 
			a_lenShorterThan);
	printf("str a_lenShorterThan_my: address = %p, value = %s\n", 
			a_lenShorterThan_my, 
			a_lenShorterThan_my);

	printf("Concat a string when the lenght of the string is exaclty equal to n\n");
	strncat(a_exactly, b_6, 5);
	mystrncat(a_exactly_my, b_6, 5);

	printf("str a_exactly: address = %p, value = %s\n", 
			a_exactly, 
			a_exactly);
	printf("str a_exactly_my: address = %p, value = %s\n", 
			a_exactly_my, 
			a_exactly_my);

	printf("Concat a string when the length of the string is greater than n\n");
	strncat(a_greater, b_6, 2);
	mystrncat(a_greater_my, b_6, 2);

	printf("str a_greater: address = %p, value = %s\n", 
			a_greater, 
			a_greater);
	printf("str a_greater_my: address = %p, value = %s\n", 
			a_greater_my, 
			a_greater_my);

	printf("=== End mystrncat ====\n");

	printf("\n\n=== START mystrncpy ====\n");
	printf("=== END mystrncpy ====\n");
	return 0;
}

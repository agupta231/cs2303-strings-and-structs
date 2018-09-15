/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

	// Orginial Version
  // length = strlen(src) + 1;  // Leave space for the terminator
	
	// Use mystrlen1. As it is the exact same prototype, the only change that is
	// required is to do a simple refactor
	length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string using mystrlen2
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

	// Orginial Version
  // length = strlen(src) + 1;  // Leave space for the terminator
	
	// Use mystrlen1. As it is the exact same prototype, the only change that is
	// required is to do a simple refactor
	length = mystrlen2(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/**
 * @brief Determine the length of a string by using subscripts
 *
 * @param s pointer to char array
 *
 * @return the length of the string defined as per s.
 */
long int mystrlen1(const char* s) {
	// Initialize Counter
	long int i = 0;
	// Intialize Length
	long int len = 0;

	// While the current char isn't the terminator
	while(s[i] != '\0') {
		// Increment length and counter
		len++;
		i++;
	}

	// Return length
	return len;
}

/**
 * @brief Determine the length of a string using pointer incrementation
 *
 * @param s pointer to char array
 *
 * @return the length of the string defined as per s.
 */
long int mystrlen2(const char* s) {
	// Create a back up pointer that will point to the beginning of the str
	const char* s_backup = s;

	// Initialize length
	long int len = 0;

	// While the current char isn't the terminator
	while(*s != '\0') {
		// Increment length and pointer
		len++;
		s++;
	}

	// Return string to the beginning of the string.
	s = s_backup;

	// Return length
	return len;
}


/**
 * @brief Creates a copy of one string to another
 *
 * @param dest pointer to the char array where to copy the string to
 * @param src pointer to the char array to copy
 *
 * @return pointer to dest
 */
char* mystrcpy(char* dest, char* src) {
	// Create backup pointer that points to the first char in the string
	char* dest_backup = dest;
	char* src_backup = src;

	// While the current char isn't a terminator
	while(*src != '\0') {
		// Set the current value of the dest as the current char in src
		*dest = *src;

		// Increment pointers
		src++;
		dest++;
	}

	// Copy over the terminator
	*dest = *src;

	// reset pointers to the beginning of the array
	dest = dest_backup;
	src = src_backup;

	// Return pointer to destination str
	return dest_backup;
}

char* mystrcat(char* dest, char* src) {
	// Create "working pointers" - pointers that will traverse the string but
	// won't mess with the pointer to the starting element in the char array
	char* d = dest;
	char* s = src;

	// Traverse until the terminator in the dest
	while(*d != '\0') {
		d++;
	}
	
	// Copy over all of src to dest
	while(*s != '\0') {
		*d = *s;
		d++;
		s++;
	}

	// Copy over terminator to dest
	*d = *s;
	
	// Reset poisition of d
	d = dest;
	return d;
}

char* mystrncat(char* dest, char* src, size_t n) {
	// Create "working pointers" - pointers that will traverse the string but
	// won't mess with the pointer to the starting element in the char array
	char* d = dest;
	char* s = src;

	while(*d != '\0') {
		d++;
	}

	for(int i = 0; i < n; i++) {
		d = s;
		d++;
		s++;
	}

	d = '\0';

	return dest;
}

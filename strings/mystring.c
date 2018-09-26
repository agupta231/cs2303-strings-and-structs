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

/**
 * @brief Concatinate src onto dest. Not safe, and will continue for the entire
 * length of the string.
 *
 * @param dest string to copy to
 * @param src string to be copied
 *
 * @return Concatinated string
 */
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

/**
 * @brief concatinate up to n characters from src to dest
 *
 * @param dest string to concatinate to
 * @param src sting to be copied
 * @param n number of characters to copy over
 *
 * @return concatinated string
 */
char* mystrncat(char* dest, char* src, size_t n) {
	// Create "working pointers" - pointers that will traverse the string but
	// won't mess with the pointer to the starting element in the char array
	char* d = dest;
	char* s = src;

	// Start at the null terminator of d
	while(*d != '\0') {
		d++;
	}

	// Iterate through the src string for the desired size
	for(int i = 0; i < n; i++) {
		// Copy over the value
		*d = *s;
		
		// Increment the pointers
		d++;
		s++;
	}

	// Insert a null terminator
	d = '\0';

	// Return the pointer to the start of the dest string
	return dest;
}

/**
 * @brief copy a string to another address upto n characters
 *
 * @param dest where the new address of the string should be
 * @param src where to copy the string from
 * @param n how many characters should be copied
 *
 * @return pointer to dest
 */
char* mystrncpy(char* dest, const char* src, size_t n) {
	// create working pointers
	char* d = dest;
	const char* s = src;

	// Iterate the number of characters
	for(int i = 0; i < n; i++) {
		// Copy the value of the src to the dest
		*d = *s;

		// In case the source is smaller than the number of characters
		if(*s == '\0') {
			break;
		}

		// Increment pointers
		d++;
		s++;
	}

	// Return pointer to new address in memeory
	return dest;
}

/**
 * @brief Duplicate a string up tp n charactesr
 *
 * @param str string to duplicate
 * @param n number characters to duplicate up to
 *
 * @return a pointer to the new string
 */
char* mystrndup(const char* str, size_t n) {
	// Create a char buffer of n + 1. This way, there will always be space for a
	// null terminator at the end
	char* newstr = (char*) malloc(n + 1); // Must cast!

	// If no memory was available, return null pointer immediately
	if (newstr == 0) return (char *) 0;

	// Iterate through the characters
	for(int i = 0; i < n; i++) {
		newstr[i] = str[i];

		// If src has a null terminator, the function will stop copying and return
		// right there
		if(str[i] == '\0') {
			return newstr;
		}
	}

	// Attach a null terminaotor to the end
	newstr[n] = '\0';
	return newstr;
}

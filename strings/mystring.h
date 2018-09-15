/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

// Function prototype(s):
char* mystrdup1(const char* src);
char* mystrdup2(const char* src);

long int mystrlen1(const char* s);
long int mystrlen2(const char* s);

char* mystrcpy(char* dest, char* src);
char* mystrcat(char* dest, char* src);
char* mystrncat(char* dest, char* src, size_t n);
char* mystrncpy(char* dest, const char* src, size_t n);

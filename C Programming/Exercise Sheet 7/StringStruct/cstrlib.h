#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char const *string;
    int length;
    int hash;
}  str_t;


/*
 * Initialise a string object from a C-string
 * example usage:
 * str_t a;
 * str_init("test", & a);
 */
void str_init(char const *str, str_t *out);

/*
 * Copy a string object into another (already allocated) string object
 */
void str_cpy(str_t *in, str_t *out);

/*
 * Provide the length of the string
 * @Return the length of the string
 */
int str_len(str_t *str);

/*
 * Calculate a hash value for the string,
 * i.e., construct a fixed-size value from the * string that acts like a fingerprint for it.
 * @Return the integer
 */
int str_hash(str_t *str);

/*
 * Check if both string are equal
 * @Return true if the strings are equal
 */
bool str_equal(str_t *a, str_t *b);

/*
 * Compare two strings using the shortlex order (see below)
 * @Return 0 if they are equal, -1 if a < b, +1 if a > b
 */
int str_cmp(str_t *a, str_t *b);

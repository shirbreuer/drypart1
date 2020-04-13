#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *stringDuplicator(char *s, int times) { // 1. Variable's name should be clear ( s => string), 2. brackets should be in new line.
 assert(!s); // A. can't use assert to validate input from user.
 assert(times > 0); // if times is non-positive, malloc will return NULL anyway
 int LEN = strlen(s); // 3. Variable's name should be lowercase only (LEN => len)
 char *out = malloc(LEN * times); // should allocate one more byte (for \0)
 assert(out); // C. assert cannot be used for malloc validating. (assert => if)
 for (int i = 0; i < times; i++) {
 out = out + LEN; // will change the pointer, We don't want that.
 strcpy(out, s);
 }
 return out;
}
// 4. Indentation problems

// conventions problems are listed by numbers.
// programming problems are listed by letters.


// Fixed Version:

#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *stringDuplicator(char *string, int times)
{
    if((!string) || (times <= 0)) {
        return NULL;
    }
    int len = strlen(string);
    char *out = malloc(len * times + 1);
    if (!out) {
        return NULL;
    }  
    for (int i = 0; i < times; i++) {
        strcpy(out+i*len, string);
    }
    return out;
}
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *stringDuplicator(char *s, int times) { // Variable's name should be clear ( s => string)
 assert(!s); // will not work while NDEBUG is defined
 assert(times > 0); // if times is non-positive, malloc will return NULL anyway
 int LEN = strlen(s); // Variable's name should be lowercase only (LEN => len)
 char *out = malloc(LEN * times); // should allocate one more byte (for \0)
 assert(out); // assert cannot be used for malloc validating. (assert => if)
 for (int i = 0; i < times; i++) {
 out = out + LEN; // will change the pointer, We don't want that.
 strcpy(out, s);
 }
 return out;
}
// Indentation problems (as shown bellow) - one for "block" and one for "for"




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
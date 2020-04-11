#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

char *stringDuplicator(char *string, int times)
{
    if((!string) || (times <= 0)){
        return NULL;
    }
    int len = strlen(string);
    char *out = malloc(len * times + 1); // + 1 => for \0
    if (!out) {
        return NULL;
    }
        
    for (int i = 0; i < times; i++) {
        strcpy(out+i*len,string);
    }
    return out;
}

int main()
{
char *stringtest = "Hello";
stringtest = stringDuplicator(stringtest, 3);
printf("%s", stringtest);
return 0;
}
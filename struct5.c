#include <stdio.h>
#include <string.h>


struct Token {
   int type;
   char value[1000];
};


int main() {
    struct Token tokens[3];
    
    tokens[0].type = 0;
    strcpy(tokens[0].value, "5");

    tokens[1].type = 0;
    strcpy(tokens[1].value, "+");

    tokens[2].type = 0;
    strcpy(tokens[2].value, "3");

    for (int i = 0; i < 3; i++) {
        printf("Token: %d, type:%d, value:%s\n", i, tokens[i].type, tokens[i].value);
    }

    return 0;
 }


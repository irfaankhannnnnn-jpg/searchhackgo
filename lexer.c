#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main() {
    char *source = "let x = 5 + 3;";


    for (int i = 0; source[i] != '\0'; i++) {
	 char c = source[i];
  
	 if (isalpha(c)) {
             char word[100];
	     int pos = 0;
	     while (isalpha(source[i])) {
		 word[pos++] = source[i];
		 i++;
	     }
	     word[pos] = '\0';
	     

	     if (strcmp(word, "let") == 0) {
		 printf("KEYWORD: %s\n", word);
	     } else {
		 printf("IDENTIFIER: %s\n", word);
	     }
	     i--;
	   }
           else if (isdigit(c)) {
           printf("'%c'is a NUMBER\n", c);
           }
           else if (c == '+' || c == '-' || c == '=' || c == ';') {
           printf("'%c' is an OPERATOR\n", c);
           }
  
        }

           return 0;
    }


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define BYTES_PER_LINE 16

void print_hex_line( const unsigned char *data, int len, int offset) {
     printf("%08x", offset);

     for ( int i = 0; i < BYTES_PER_LINE; i++) {
	 if (i < len)
	     printf("%02x", data[i]);
         else
             printf("  ");

	 if (i == 7) printf("  ");
     }


     printf(" |");
     for (int i = 0; i < len; i++) {
	 printf("%c", isprint(data[i]) ? data[i] : '.');
     }

     for (int i = len; i < BYTES_PER_LINE; i++) {
	 printf("  ");
     }
     printf("|\n");
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
       printf("Usage: %s <filename>\n", argv[0]);
       return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
	perror("Error opening file");
	return 1;
    }

    unsigned char buffer[BYTES_PER_LINE];
    int offset = 0;
    int bytes_read;
    
    while((bytes_read = fread(buffer, 1, BYTES_PER_LINE, fp)) > 0) {
	  print_hex_line(buffer, bytes_read, offset);
	  offset += bytes_read;
    }

    fclose(fp);
    return 0;
}




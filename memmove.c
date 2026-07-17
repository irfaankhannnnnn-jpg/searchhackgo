#include <stdio.h>
#include <string.h>


void *ft_memmove(void *dest, const void *src, size_t n) 
{
	unsigned char *d = (unsigned char*)dest;
	const unsigned char *s = (const unsigned char*)src;


	if ( d < s) {
	   for (size_t i = 0; i < n; i++) 
	       d[i] = s[i];

	} else {
	   for (size_t i = n; i > 0; i--)
	       d[i - 1] = s[i - 1];
	}

	   return dest;
	   
}


int main() {

	char a[20] = "Helloworld!";

	printf("Before: %s\n", a);
	ft_memmove(a + 2, a, 5);
	printf("After: %s\n", a);

	return 0;
}


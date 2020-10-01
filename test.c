#include <stdio.h>

int main()
{
	int color = 16777214;
    unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	b = src[2];
    printf ("b: %u\n", b);
	g = src[1];
    printf ("g: %u\n", g);
	r = src[0];
    printf ("r: %u\n", r);
	return (0);
}
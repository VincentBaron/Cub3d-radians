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

	char s = '2'
	char *s = "127"
	unsigned char x = 230

	unsigned char s[16];

	s[0] =  '4';
	w[1] = '9';

	s[0] + w[1] = 
}
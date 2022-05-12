#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;
	double d;

	d = 47.8;
	printf("d=%.0lf\n", d);
	
	c = d + 0.5;
	printf("my round of d = %d\n", c);

	d = 2 / 3.;
	printf("d=%.2lf\n", d);

	b = 5;
	b = b * 2;
	b *= 2;
	printf("b=%d\n", b);


	return 0;
}
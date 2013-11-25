#define NEG1(type) (~((type)0))
#define NEG1UL NEG1(unsigned long)
#define BITS(h, l) (NEG1UL<<1<<(h) ^ NEG1UL<<(l))

#include <stdio.h>
#include <stdlib.h>

#ifndef H
#define H 25
#endif

#ifndef L
#define L 3
#endif

int bindump(unsigned long val)
{
	int i;
	unsigned long m = 1<<(sizeof(unsigned long)*8-1);

	for(i=0;i<sizeof(unsigned long)*8;i++){
		char c;
		c = val & m ? '1' : '0';
		m>>=1;
		putchar(c);
		if(i%4==3) putchar(' ');
	}
	return 0;
}

int main(int argc, char *argv[])
{
	unsigned long val; 
	val = BITS(H, L);

	printf("BITS(%2d,%2d): ", H, L);
	printf("0x%08lX, ", val);
	bindump(val);
	putchar('\n');
	return 0;
}


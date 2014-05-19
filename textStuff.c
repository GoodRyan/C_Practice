/*
 * Practice for manipulating text input via console
 */
#include <stdio.h>
#include "textStuff.h"

/*
 * type characters then press enter to receive a character
 * count. Note: %ld means long integer (it's a letter L not
 * a number 1.
 */
void characterCounting()
{
	long nc;

	nc = 0;
	while (getchar() != EOF){
		++nc;
	}
	printf("%ld\n", nc);
}

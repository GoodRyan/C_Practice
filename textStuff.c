/*
 * Practice for manipulating text input via console
 */
#include <stdio.h>
#include "textStuff.h"

/*
 * type characters then press enter and terminate program
 * to receive a character count. Note: %ld means long integer
 * (it's a letter L not * a number 1.)
 */
void characterCounting()
{
	double nc;

	for (nc = 0; getchar() != EOF; ++nc){
		;
	}
	printf("number of characters: %.0f\n", nc);
}

/*
 * Counts number of lines (last line before program terminates
 * doesn't count
 */
void lineCounting()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("number of lines: %d\n", nl);
}

/*
 * counts all blanks, new lines, and tabs
 * that the user inputs into the console
 */
void blankTabNewlineCounting()
{
	int c, blanks, tabs, nl;
	blanks = 0;
	nl = 0;
	tabs = 0;

	while((c = getchar()) != EOF){
		if (c == ' '){
			++blanks;
		}
		else if(c == '\t'){
			++tabs;
		}
		else if(c == '\n'){
			++nl;
		}
	}
	printf("number of blanks: %d\n", blanks);
	printf("number of tabs: %d\n", tabs);
	printf("number of lines: %d\n", nl);
}

/*
 * Removes extra blanks when there is more
 * than one blank in series.
 */
void removeExtraBlanks()
{
	int c, p = EOF;
	while ((c = getchar()) != EOF) {
	    if ((c != ' ') + (p != ' ') > 0) putchar(c);
	    p = c;
	    fflush(stdout);
	}
}

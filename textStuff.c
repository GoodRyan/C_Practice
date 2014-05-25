/*
 * Practice for manipulating text input via console
 */
#include <stdio.h>
#include "textStuff.h"

#define MAXLINE 1000 /* maximum input line size for printLongestInputLine

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
	    if ((c != ' ') + (p != ' ') > 0){
	    	putchar(c);
	    	p = c;
	    }

	    fflush(stdout);
	}
}

/**
 * Takes tab and backslash inputs and converts
 * them to their character equivalents. I also
 * attempted to do this with backspace, however
 * the terminal eats the character before it
 * can be processed.
 */
void unambiguousText()
{
	int c;

	while((c = getchar()) != EOF) {
		if(c == '\t'){
			printf("\\t");
		}
		else if(c == '\b'){
			printf("\\b");
		}
		else if(c == '\\'){
			printf("\\\\");
		}
		else{
			putchar(c);
		}
		fflush(stdout);
	}
}

/*
 * Takes input and places one word per line.
 */
void seperateWordsByLine(){
	char c;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t'){
			putchar('\n');
		}
		else{
		putchar(c);
		}
		fflush(stdout);
	}
}

/*
 * Helper function for wordLengthHistogram
 * returns word length after it sees a space or new line
 */
int getWordLength(){
	int wordLength = 0;
	int inputCharacter;
	wordLength++;
	while((inputCharacter = getchar()) != ' ' && inputCharacter != '\n'){
		wordLength++;
	}
	return wordLength;
}

/*
 *	Helper function for wordLengthHistogram
 *	prints a bar based on barLength (compased of dashes)
 */
void printBar(int barLength){
	int counter = 0;

	while (counter < barLength){
		printf("-");
		counter++;
	}
}

/*
 * Prints histogram of word lengths
 * Works for words up to 10 characters long.
 */
void wordLengthHistogram(){
	int wordLengths[10];
	int counter = 0;
	int input, wordLength;

	//initialize all array values to zero
	while (counter < 10){
		wordLengths[counter] = 0;
		counter++;
	}

	//get word lengths of input
	while((input = getchar() != EOF)){
		wordLength = getWordLength();
		wordLengths[wordLength]++;

		wordLength = 0;
	}

	//print histogram
	counter = 0;
	while(counter < 10){
		printf("Length %d: ", counter);
		printBar(wordLengths[counter]);
		printf("\n");
		counter++;
	}
}

/*
 * read a line into s, return length
 */
int getLine(char s[], int lim){
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/*
 * copy from 'from' into 'to'
 * assume 'to' is big enough
 */
void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0'){
		++i;
	}
}

/*
 * print longest input line
 */
void printLongestInputLine(){
	int len;	//current line length
	int max;	//maximum length seen so far
	char line[MAXLINE]; //current input line
	char longest[MAXLINE]; //longest line saved here

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0){
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0){ //there was a line
		printf("%s", longest);
		printf("%d", max-1);
	}
}

/*
 *
 */
void printLongerThanEighty(){
	int len;	//current line length
	char line[MAXLINE]; //input line

	while ((len = getLine(line, MAXLINE)) > 0){
		if(len > 80){
			printf("%s", line);
			fflush(stdout);
		}
	}
}

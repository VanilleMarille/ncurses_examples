#include <stdio.h>
#include <curses.h>

int main(void){
	initscr();
	noecho();
	int ch;
	for( ; ; ){
		ch=getch();
		clear();
		refresh;
		printw("Key Number:%d", ch);
	}
	return 0;
}

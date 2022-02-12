#include <curses.h>
#include <stdio.h>

int detectkey() {
	
	int key = 1;
    	
	if (getch() == '\033') { 
		getch();

    		switch(getch()) { 

       			case 'A':
				key = 2;
       				break;
       			case 'B':
				key = 3;
       				break;
       			case 'C':
				key = 4;
       				break;
       			case 'D':
				key = 5;
	        		break;
    		}

 	}
 	return key;
}

int drawbox(int box_x, int box_y, int box_width, int box_height) {

	int box_right=box_width + box_x;
	int box_left;
	int i;

	int characters=box_width;
	move(box_y,box_x);
	addch(ACS_ULCORNER);
	for(characters; characters--;){
		addch(ACS_HLINE);	
	}	
	addch(ACS_URCORNER);
	i=0;
	for(box_height; box_height--;){
		i++;
		box_left=i+box_y;
		move(box_left,box_x);
		addch(ACS_VLINE);
		move(box_left,box_right+1);
		addch(ACS_VLINE);
	}

	move(box_left+1,box_x+box_height+1);
	addch(ACS_LLCORNER);
	characters=box_width;
	for(characters; characters--;){
		addch(ACS_HLINE);
	}
	addch(ACS_LRCORNER);
	return 0;
}

int main(void) {
 	initscr();
 	curs_set(0);
 	noecho();

	drawbox(1,1,10,5);
	drawbox(13,1,10,5);

	move(8,3);
	printw("Key pressed:");

    for( ; ; ){	
	
    	int key = detectkey();

	move(8,3);
	printw("Key pressed: %d", key);
	refresh();
    }

    endwin();

    return 0;
}




#include <curses.h>
#include <stdio.h>

int slist(char* list[], int elements, int pos_x, int pos_y) {

	move(pos_y, pos_x);

	int i = 0;
	for(elements; elements--;){
		printw("[ ] ");
		printw("%s", list[i]);
		i++; pos_y++;
		move(pos_y, pos_x);
	}

	refresh;
	return 0;
}

int detectkey() {

	int key = 0;


	int pressed_key;

	pressed_key=getch();

	switch(pressed_key){
		case 32:
			key=1;
			break;
		case 65:
			key=2;
			break;
		case 66:
			key=3;
			break;
	}

	return key;
}

int main(void) {
	initscr();
	noecho();

	int pos_x = 10;
	int pos_y = 1;

	int elements = 4;

	char* list[] = {
		"First Entry",
		"Second Entry",
		"Third Entry",
		"Fourth Entry"
	};


	slist(list, elements, pos_x, pos_y);


	int cursor_y = pos_y;
	int cursor_x = pos_x+1;
	move(cursor_y,cursor_x);

	
	
	int selected=0;

	int checklist[elements];
	for (int i = 0; i < elements; i++){
		checklist[i]=0;
	}

	for( ; ; ){

		int key = detectkey();	

		switch(key){
			case 1:
				if(checklist[selected] != 1){
					checklist[selected]=1;
					printw("*");
				}
				else {
					checklist[selected]=0;
					printw(" ");
				}
				break;
			case 2:
				if (selected != 0){
					selected--;
					cursor_y--;
				}
				break;
			case 3:
				if (selected != elements - 1){
					selected++;
					cursor_y++;
				}
				break;
		}

		move(1,1);
		
		for (int i = 0; i < elements; i++){
			printw("%d", checklist[i]);
		}


		move(cursor_y,cursor_x);

		refresh;

	}
	endwin();


}

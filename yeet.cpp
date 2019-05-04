#include <iostream>
#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h> 
 
using namespace std;

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);								/* 0, 0 gives default characters 
					 						* for the vertical and horizontal
											 * lines			*/
	wrefresh(local_win);								/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}

int main()
{
	WINDOW *gamewin;
	int startx, starty, width, height; 						 //Parameters for gamewin(dow)
	int ch;
	char mesg[]="Welcome to Doodle Jump! Press Any Button";				/* message to be appeared on the screen */
	int row,col;									/* to store the number of rows and *
					 						* the number of colums of the screen */
	initscr();									/* start the curses mode */
	raw();
	noecho();
	cbreak();
	getmaxyx(stdscr,row,col);							/* get the number of rows and columns */
	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);                                	/* print the message at the center of the screen */
	mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
	refresh();
	getch();

	keypad(stdscr, TRUE);
	
	height = 50;
	width = 60;
	starty = (LINES - height) / 2;							/* Calculating for a center placement */
	startx = (COLS - width) / 2;							/* of the window		*/
	printw("Press Q to exit");
	refresh();
	gamewin = create_newwin(height, width, starty, startx);

	while((ch = getch()) != 'q'){
		keypad(gamewin, TRUE);
	}
	endwin();

	return 0;
}

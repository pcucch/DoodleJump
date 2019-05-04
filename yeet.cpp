#include <iostream>
#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h>
#include <unistd.h>            //Important for sleep function
 
using namespace std;

class Gameobject {
public:
    virtual void draw(WINDOW *win) const = 0;
};

class Doodler : public Gameobject {
public:

    int xpos, ypos;
    int yVelocity;
    int xspeed;

    Doodler(){
        xpos = 31;          //x position of doodler at start of the game
        ypos = 10;          //y position of doodler at start of the game
        yVelocity = 0;
    }
    void draw(WINDOW *win) const{
        mvwprintw(win, ypos, xpos, "X");
    }
};


class Gameobject {
public:
    virtual void draw(WINDOW *win) const = 0;
};

class Doodler : public Gameobject {
public:

    int xpos, ypos;
    int yVelocity;
    int xspeed;

    Doodler(){
        xpos = 31;          //x position of doodler at start of the game
        ypos = 10;          //y position of doodler at start of the game
        yVelocity = 0;
    }
    void draw(WINDOW *win) const{
        mvprintw(ypos, xpos, "X");
    }
};


WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);								/* 0, 0 gives default characters 
					 						* for the vertical and horizontal
											 * lines			*/
	wrefresh(local_win);								/* Show that box 		*/

	return local_win;
}

int main()  {

	WINDOW *gamewin;
	Doodler doodler;
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

	keypad(stdscr, TRUE);    //enables use of keypad on specified window
	
	height = 50;
	width = 61;
	starty = (LINES - height) / 2;							/* Calculating for a center placement */
	startx = (COLS - width) / 2;							/* of the window		*/
	printw("Press Q to exit");
	refresh();
	gamewin = create_newwin(height, width, starty, startx);
	keypad(gamewin,TRUE);

	while((ch = getch()) != 'q') {                       //play game
        usleep(50);
        switch (ch) {
            case KEY_LEFT:
                doodler.xpos--;
                break;
            case KEY_RIGHT:
                doodler.xpos++;
                break;
        }
        doodler.draw(gamewin);
        wrefresh(gamewin);
        usleep(500);     //will stall the loop by one second
    }
	endwin();

	return 0;
}

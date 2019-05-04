#include <iostream>
#include <ncurses.h>			/* ncurses.h includes stdio.h */
#include <string.h>
#include <unistd.h>            //Important for sleep function
#include "doodlejump.h"

using namespace std;



int main()  {

    WINDOW *gamewin;
    Doodler doodler;
    int startx, starty, width, height; 						 //Parameters for gamewin(dow)
    int ch = 0;
    char mesg[]="Welcome to Doodle Jump! Press Any Button";				/* message to be appeared on the screen */
    int row,col;									/* to store the number of rows and *
					 						* the number of colums of the screen */
    initscr();									/* start the curses mode */
    raw();
    noecho();
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
    curs_set(0);

    while(ch != 'q') {                       //play game
        halfdelay(1);
        ch = getch();
        if (ch != ERR) {
            switch (ch) {
                case KEY_LEFT:
                    doodler.xpos--;
                    break;
                case KEY_RIGHT:
                    doodler.xpos++;
                    break;
                default:
                    break;
            }
        }
        else {doodler.ypos++;}
        doodler.draw(gamewin);
        doodler.clearPrev(gamewin);
        wrefresh(gamewin);
        usleep(1);     //will stall the loop by half of one second
    }
    endwin();

    return 0;
}

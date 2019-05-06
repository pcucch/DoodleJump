#include <iostream>
#include <ncurses.h>			/* ncurses.h includes stdio.h */
#include <string.h>
#include <unistd.h>            //Important for sleep function
#include "doodlejump.h"
#include <cstdlib>
#include <curses.h>
#include <termio.h>
#include <sys/ioctl.h>
#include <vector>
#include <time.h>

using namespace std;

float physicsM = 1;       //neccesary for keeping the physics time

int main()  {

    WINDOW *gamewin;
    Doodler doodler;
    DeathSpikes spikes;
    Platform startplat(31, 42);             //starting position of first platform
    Platform startplat1(20,30);
    Platform startplat2 (40, 25);
    Platform startplat3 (40, 12);
    vector<Platform> platforms;
    platforms.push_back(startplat);
    platforms.push_back(startplat1);
    platforms.push_back(startplat2);
    platforms.push_back(startplat3);


    int startx, starty, width, height; 						    //Parameters for gamewin(dow)
    int score = 0;                                          //keeps the score and can display it
    int ch = 0;
    char mesg[]="Welcome to Moodle Jump! Press Any Button";				/* message to be appeared on the screen */
    char scoremsg[] = "Your Current GPA Is";
    srand(time(0));
    int row,col;        							    		/* to store the number of rows and *
					 	            			    	    	* the number of columns of the screen */
    initscr();						            			    /* start the curses mode */
    raw();                                      //no input buffering
    start_color();  //color enable
    init_pair(1, COLOR_GREEN, COLOR_YELLOW);
    noecho();
    getmaxyx(stdscr,row,col);							        /* get the number of rows and columns */
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);                                	/* print the message at the center of the screen */
    mvprintw(row - 2, 0, "%s %d\n", scoremsg, score);                   //Print Score
    refresh();
    getch();
    keypad(stdscr, TRUE);                 //enables use of keypad on specified window
    height = 50;
    width = 61;
    starty = (LINES - height) / 2;							/* Calculating for a center placement */
    startx = (COLS - width) / 2;							/* of the window		*/
    printw("Press Q to exit");
    refresh();
    gamewin = create_newwin(height, width, starty, startx);
    keypad(gamewin,TRUE);
    curs_set(0);        //make cursor invisible

    while(ch != 'q') {                       //play game
        if (_kbhit()) {
            ch = getch();
            switch (ch) {
                case KEY_LEFT:
                    doodler.moveLeft(1);
                    break;
                case KEY_RIGHT:
                    doodler.moveRight(1);
                    break;
                case 'a':
                    doodler.moveLeft(2);
                    break;
                case 'd':
                    doodler.moveRight(2);
                default:
                    break;
            }
        }
        else {
            usleep(100000 / physicsM);
            doodler.prevypos = doodler.ypos;
            doodler.prevxpos = doodler.xpos;
            doodler.jump(platforms);            //checks for jump
            if (doodler.jumptrue == 1){
                doodler.ypos--;
            }
            else if (doodler.jumptrue == 0) {
                doodler.ypos++;
            }
        }
        if (doodler.checkDeath() == 1){
            break;
        }
        doodler.time_stone();
        if (doodler.reachLim() == 1){
            score++;
            mvprintw(row - 2, 0, "%s %d\n", scoremsg, score);
            clearPrevPlatform(platforms, gamewin);
            moveEverything(doodler, platforms);
        }
        if (platforms[platforms.size() - 1].ycen >= 8) {
            addPlat(platforms);
        }
        destroyPlatform(platforms);             //Checks for platforms going offscreen and deletes them from the vector to stop a memory leak
        spikes.draw(gamewin);
        doodler.clearPrev(gamewin);
        drawPlatforms(platforms, gamewin);
        wattron(gamewin, 1);
        doodler.draw(gamewin);
        wattroff(gamewin, 1);
        wrefresh(gamewin);
    }
    endwin();

    return 0;
}

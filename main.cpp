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

    //Initialize objects and vectors
    WINDOW *gamewin;
    Doodler doodler;
    DeathSpikes spikes;
    vector<Enemy> enemies;
    vector<Boolet>boolets;

    int startx, starty, width, height; 						    //Parameters for gamewin(dow)
    int score = 0;                                          //keeps the score and can display it
    int ch = 0;
    int quitorreplay;                  //later, you choose whether to quit or replay the game
    char mesg[]="Welcome to Moodle Jump! Press Any Button";				/* message to be appeared on the screen */
    char scoremsg[] = "Your Current GPA Is";
    srand(time(0));
    int dead = 1;
    int strike;
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

    keypad(gamewin,TRUE);
    curs_set(0);        //make cursor invisible

    while (1) {

        ch = 'w';
        score = 0;
        dead = 1;
        doodler.xpos = 31;
        doodler.ypos = 38;
        gamewin = create_newwin(height, width, starty, startx);
        Platform startplat(31, 42);             //starting position of first platform
        Platform startplat1(20,30);
        Platform startplat2 (40, 25);
        Platform startplat3 (40, 12);
        vector<Platform> platforms;
        platforms.push_back(startplat);
        platforms.push_back(startplat1);
        platforms.push_back(startplat2);
        platforms.push_back(startplat3);

        while (ch != 'q') {                       //play game
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
                        break;
                    case ' ' :
                        if (strike = doodler.align(enemies)) {
                            doodler.shootEnemy(enemies[strike], gamewin);
                            enemies[strike - 1].destroy(gamewin);
                            enemies.erase(enemies.begin() + strike);
                        } else {
                            doodler.shootNothing(gamewin);
                        }
                        break;
                    default:
                        break;
                }
            } else {
                usleep(100000 / physicsM);
                doodler.prevypos = doodler.ypos;
                doodler.prevxpos = doodler.xpos;
                if (dead) {
                    doodler.jump(platforms);            //checks for jump
                }
                if (doodler.jumptrue == 1) {
                    doodler.ypos--;
                } else if (doodler.jumptrue == 0) {
                    doodler.ypos++;
                }
            }
            if (doodler.checkDeath() == 1) {
                break;
            }

            doodler.time_stone();

            if (doodler.reachLim() == 1) {
                score++;
                mvprintw(row - 2, 0, "%s %d\n", scoremsg, score);
                clearPrevPlatform(platforms, gamewin);
                if (enemies.size() != 0) {
                    clearPrevEnemy(enemies, gamewin);
                }
                moveEverything(doodler, platforms, enemies);
            }
            if (platforms[platforms.size() - 1].ycen >= 8) {
                addPlat(platforms);
                if (rand() % 10 == 3) {
                    addEnem(enemies);
                }
            }
            doodler.contact(enemies, dead, gamewin);
            refreshBoard(doodler, platforms, enemies, spikes, gamewin, dead);
        }
        clearBoard(gamewin, platforms, enemies);
        erase();                                        //clears board of text

        printQuote(row, col);
        mvprintw((row/2) + 3,col/2 - 4,"Your GPA was %d", score);
        mvprintw((row/2) + 4,(col-strlen(mesg))/2,"Press Q to exit, Press any button to play again!");
        usleep(100000);
        while (quitorreplay = getch()){
            if (quitorreplay == 'q'){
                break;
            }
            else {
                break;
            }
        }
        if (quitorreplay == 'q'){
            break;
        }
    }
    endwin();       //completely ends the game

    return 0;
}

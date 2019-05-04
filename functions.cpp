#include <iostream>
#include <curses.h>
#include "doodlejump.h"

using namespace std;

Doodler::Doodler() {
    xpos = 31;          //x position of doodler at start of the game
    ypos = 10;          //y position of doodler at start of the game
    yVelocity = 0;
}

void Doodler::draw(WINDOW *win) const {
    mvwprintw(win, ypos, xpos, "X");
    return;
}

void Doodler::clearPrev(WINDOW *win){
    mvwprintw(win, ypos, xpos-1, " ");
    mvwprintw(win, ypos, xpos+1, " ");
    mvwprintw(win, ypos-1, xpos, " ");
    mvwprintw(win, ypos+1, xpos, " ");
    return;
}


void Platform::draw(void) {
	cout << "￣￣￣" << endl;
}


void Enemy::draw(void) {
	cout << "________" << endl;
	cout << "|RISBUD|" << endl;
	cout << "￣￣￣￣" << endl;
}


void Boolet::draw(void) {
	cout << "|" << endl;
}

WINDOW *create_newwin(int height, int width, int starty, int startx){

    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);								/* 0, 0 gives default characters
					 						* for the vertical and horizontal
											 * lines			*/
    wrefresh(local_win);								/* Show that box 		*/

    return local_win;
}



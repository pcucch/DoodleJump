#include <iostream>
#include <curses.h>
#include <unistd.h>
#include "doodlejump.h"

using namespace std;

Doodler::Doodler() {
    xpos = 31;          //x position of doodler at start of the game
    ypos = 40;          //y position of doodler at start of the game
    yVelocity = 0;
}

void Doodler::draw(WINDOW *win) const {
    mvwprintw(win, ypos, xpos, "X");
    return;
}

void Doodler::shootEnemy(WINDOW *win, Enemy e) {
	Boolet b(ypos, xpos);
	while(b.ypos >= 0) {
		b.draw(win);
		b.clearPrevBoolet(win);
		if(b.ypos == e.ypos) {
		     	return;
		}
		b.ypos--;

	}
	return;
}

void Doodler::shootNothing(WINDOW *win) {
	Boolet b(ypos,xpos);
	while(b.ypos != 0) {
		b.draw(win);
		b.clearPrevBoolet(win);
		b.ypos--;
		wrefresh(win);
		usleep(20000);
	}
	return;
}


void Doodler::clearPrevDood(WINDOW *win){
    mvwprintw(win, ypos, xpos-1, " ");
    mvwprintw(win, ypos, xpos+1, " ");
    mvwprintw(win, ypos-1, xpos, " ");
    mvwprintw(win, ypos+1, xpos, " ");
    mvwprintw(win, ypos-1, xpos-1, " ");
    mvwprintw(win, ypos+1, xpos+1, " ");
    mvwprintw(win, ypos-1, xpos+1, " ");
    mvwprintw(win, ypos+1, xpos-1, " ");
    return;
}

void Boolet::clearPrevBoolet(WINDOW *win){
    mvwprintw(win, ypos, xpos-1, " ");
    mvwprintw(win, ypos, xpos+1, " ");
    mvwprintw(win, ypos-1, xpos, " ");
    mvwprintw(win, ypos+1, xpos, " ");
    mvwprintw(win, ypos-1, xpos-1, " ");
    mvwprintw(win, ypos+1, xpos+1, " ");
    mvwprintw(win, ypos-1, xpos+1, " ");
    mvwprintw(win, ypos+1, xpos-1, " ");
    return;
}



void Platform::draw(WINDOW *win) const {
	mvwprintw(win, ypos, xpos, "￣￣￣");
}

Enemy::Enemy(int y, int x, int speed) {
	ypos = y;
	xpos = x;
}

void Enemy::draw(WINDOW *win) const {
	mvwprintw(win, ypos, xpos, "________");
	mvwprintw(win, ypos, xpos, "|RISBUD|");
	mvwprintw(win, ypos, xpos, "￣￣￣￣");
}

Boolet::Boolet(int y, int x) {
	xpos = x;
	ypos = y;
}

void Boolet::draw(WINDOW *win) const {
	mvwprintw(win, ypos, xpos,"|");
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



#include <iostream>
#include <ncurses.h>
#include "doodlejump.h"
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <vector>
#include <unistd.h>

using namespace std;

//DEATHSPIKES

DeathSpikes::DeathSpikes() {
    for(int i = 1; i <= 61; i++){
        xpos[i] = i;
    }
    ypos = 49;
}

void DeathSpikes::draw(WINDOW *win) const {
    for (int i = 1; i <= 59; i++){
        mvwprintw(win, ypos, xpos[i], "^");
    }
}

//ENEMY

Enemy::Enemy(int x, int y) {
    xcen = x;
    ycen = y;
}

Enemy::~Enemy() {}

void Enemy::draw (WINDOW *win) const {
    //mvwprintw(win, ycen , xcen, "-");
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 2; j++) {
            if(j == 0 && (ycen - 1 > 2)) {
                mvwprintw(win, ycen - 1, xplace[i], "-");
            }
            if(j == 1 && (ycen > 2)) {
                if(i == 0) {
                    mvwprintw(win, ycen, xplace[i], "|");
                }
                if(i == 1) {
                    mvwprintw(win, ycen, xplace[i], "R");
                }
                if(i == 2) {
                    mvwprintw(win, ycen, xplace[i], "I");
                }
                if(i == 3) {
                    mvwprintw(win, ycen, xplace[i], "S");
                }
                if(i == 4) {
                    mvwprintw(win, ycen, xplace[i], "B");
                }
                if(i == 5) {
                    mvwprintw(win, ycen, xplace[i], "U");
                }
                if(i == 6) {
                    mvwprintw(win, ycen, xplace[i], "D");
                }
                if(i == 7) {
                    mvwprintw(win, ycen, xplace[i], "|");
                }
            }
            if(j == 2 && (ycen + 1 > 2)) {
                mvwprintw(win, ycen + 1, xplace[i], "-");
            }
        }
    }
    usleep(100);
}

void Enemy::init ()  {
    xplace[0] = xcen - 4;
    xplace[1] = xcen - 3;
    xplace[2] = xcen - 2;
    xplace[3] = xcen - 1;
    xplace[4] = xcen;
    xplace[5] = xcen + 1;
    xplace[6] = xcen + 2;
    xplace[7] = xcen + 3;
}

void Enemy::clear(WINDOW *win) const {
    for (int i = 0; i <= 7; i++) {
        mvwprintw(win, ycen-1, xplace[i], " ");
    }
}

void Enemy::destroy(WINDOW *win) {
    for (int i = 0; i <= 7; i++) {
        mvwprintw(win, ycen-1, xplace[i], " ");
        mvwprintw(win, ycen, xplace[i], " ");
        mvwprintw(win, ycen+1, xplace[i], " ");
    }
}





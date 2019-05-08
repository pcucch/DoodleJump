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

//DOODLER

Doodler::Doodler() {
    xpos = 31;          //x position of doodler at start of the game
    ypos = 38;          //y position of doodler at start of the game
    jumptrue = 0;
    prevxpos = 31;
    prevypos = 40;
    yVelocity = 0;
    count = 0;
    jumpheight = 15;
    timekeep = 0;
}

void Doodler::draw(WINDOW *win) const {     //draw
    start_color();
    mvwprintw(win, ypos, xpos, "X");
    return;
}

void Doodler::clearPrev(WINDOW *win){           //clears previous location of doodler
    mvwprintw(win, prevypos, prevxpos, " ");
    return;
}

int Doodler::checkDeath() {           //check if doodler dies
    if (ypos >= 49){
        return 1;
    }
    else {return 0;}
}

void Doodler::moveLeft(int amount) {        //moves left
    prevypos = ypos;
    prevxpos = xpos;
    if (timekeep > 3){
        xpos = xpos - 1 - amount;
    }
    else if (timekeep > 5){
        xpos = xpos - 3 - amount;
    }
    else {
        xpos -= amount;
    }
    if (xpos <= 0){
        xpos = 59;
    }
    else if (xpos >= 60){
        xpos = 1;
    }
    return;
}

void Doodler::moveRight(int amount) {  //moves right
    prevypos = ypos;
    prevxpos = xpos;
    if (timekeep > 3) {
        xpos = xpos + 1 + amount;
    }
    else if (timekeep > 5) {
        xpos = xpos + 3 + amount;
    }
    else {
        xpos += amount;
    }
    if (xpos >= 60){
        xpos = 1;
    }
    else if (xpos <= 0){
        xpos = 59;
    }
    return;
}

void Doodler::jump(vector<Platform> &plats) {
    if (jumptrue == 0){
        for (int i = 0; i < plats.size(); i++){
            for (int j = 0; j < 5; j++) {
                if(xpos == plats[i].xplace[j]) {
                    if(ypos == plats[i].ycen - 1){
                        jumptrue = 1;
                    }
                }
            }
        }
    }
}

void Doodler::time_stone() {
    extern float physicsM;

    if (jumptrue == 1 && count == 0) {
        jumpheight = 20;
        physicsM = 2;
        count++;
        timekeep = 10;
    }

    if (jumpheight > 0 && jumptrue == 1){
        jumpheight--;
        physicsM -= .07;
    }

    if (jumpheight == 0){
        physicsM = 1;
        jumpheight++;
        jumptrue = 0;
        count = 0;
        timekeep = 0;
    }

    if (jumptrue == 0) {
        physicsM += .07;
        timekeep++;
    }
}

int Doodler::reachLim() {
    if (ypos <= 25){
        return 1;
    }
    else {
        return 0;
    }
}

void Doodler::contact(vector<Enemy> &en, int &jump, WINDOW *win) {
    for(int i = 0; i < en.size(); i++) {
        for (int j = 0; j <= 7; j++) {
            if (xpos == 1 + en[i].xplace[j]) {
                if (en[i].ycen - 2 == ypos) {
                    jumptrue = 1;
                    en[i].destroy(win);
                    en[i].clear(win);
                    en.erase(en.end());
                }
                if (en[i].ycen == ypos) {
                    jump = 0;
                }
            }
        }
    }
}


int Doodler::align(vector<Enemy> &en) {
    for (int i = 1; i <= en.size(); i++) {
        if(xpos >= en[i-1].xcen - 4 && xpos <= en[i-1].xcen + 3) {
            return i;
        }
    }
    return 0;
}


void Doodler::shootEnemy(Enemy &en, WINDOW *win) {
    Boolet b(ypos, xpos);
    while(b.ypos >  2) {
        b.draw(win);
        b.clearPrevBoolet(win);
        if(b.ypos == en.ycen + 1) {
            return;
        }
        b.ypos--;

    }
    b.clearPrevBoolet(win);
    return;
}

void Doodler::shootNothing(WINDOW *win) {
    Boolet b(ypos,xpos);
        b.draw(win);
        b.clearPrevBoolet(win);
        b.ypos--;
        wrefresh(win);
        usleep(2000);
    }
    b.clearPrevBoolet(win);
    return;
}



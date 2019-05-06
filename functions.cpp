#include <iostream>
#include <ncurses.h>
#include "doodlejump.h"
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <vector>


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

//DOODLER

Doodler::Doodler() {
    xpos = 31;          //x position of doodler at start of the game
    ypos = 20;          //y position of doodler at start of the game
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

//PLATFORM

    Platform::Platform() {
    //fill later
}

    Platform::Platform(int x, int y) {
    xcen = x;
    ycen = y;
    xplace[0] = xcen - 2;
    xplace[1] = xcen - 1;
    xplace[2] = xcen;
    xplace[3] = xcen + 1;
    xplace[4] = xcen + 2;
}

    Platform::~Platform() {

}

void Platform::draw(WINDOW *win) const {
    for (int i = 0; i <= 4; i++){
        mvwprintw(win, ycen, xplace[i], "-");
    }
}

//ENEMY

void Enemy::draw(void) {
	cout << "________" << endl;
	cout << "|RISBUD|" << endl;
	cout << "￣￣￣￣" << endl;
}


void Boolet::draw(void) {
	cout << "|" << endl;
}

//FUNCTIONS

WINDOW *create_newwin(int height, int width, int starty, int startx){

    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);								/* 0, 0 gives default characters
					 						* for the vertical and horizontal
											 * lines			*/
    wrefresh(local_win);								/* Show that box 		*/

    return local_win;
}

int _kbhit() {                          //kbhit without conio.h, essential for main.cpp
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;


}

void drawPlatforms(const vector<Platform> &plat, WINDOW *win){
    for (int i = 0; i < plat.size(); i++){
        plat[i].draw(win);
    }
}


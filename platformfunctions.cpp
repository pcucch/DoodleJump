#include <iostream>
#include <ncurses.h>
#include "doodlejump.h"
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <vector>

using namespace std;

//PLATFORM

Platform::Platform(int x) {
    ycen = 1;
    xcen = x;
    xplace[0] = xcen - 2;
    xplace[1] = xcen - 1;
    xplace[2] = xcen;
    xplace[3] = xcen + 1;
    xplace[4] = xcen + 2;
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

Platform::~Platform() {}

void Platform::draw(WINDOW *win) const {
    for (int i = 0; i <= 4; i++) {
        mvwprintw(win, ycen, xplace[i], "-");
    }
}

void Platform::clear(WINDOW *win) const {
    for (int i = 0; i <= 4; i++) {
        mvwprintw(win, ycen, xplace[i], " ");
    }
}
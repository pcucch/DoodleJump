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

Boolet::Boolet(int y, int x) {
    xpos = x;
    ypos = y;
}

Boolet::~Boolet() {}

void Boolet::clearPrevBoolet(WINDOW *win) {
    mvwprintw(win, ypos-1, xpos, " ");
    mvwprintw(win, ypos+1, xpos, " ");
    return;
}

void Boolet::draw(WINDOW *win) const {
    mvwprintw(win, ypos, xpos,"|");
    return;
}
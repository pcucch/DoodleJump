#include <iostream>
#include <ncurses.h>
#include "doodlejump.h"
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <vector>


using namespace std;

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

void moveEverything(Doodler &doodler, vector<Platform> &plat){
    doodler.ypos++;
    for (int i = 0; i < plat.size(); ++i) {
        plat[i].ycen++;
    }
}

void clearPrevPlatform(vector<Platform> &plat, WINDOW *win){
    for (int i = 0; i < plat.size(); i++){
            plat[i].clear(win);
    }
}

void addPlat(vector<Platform> &v) {
    Platform p(rand() % 50 + 5);
    v.push_back(p);
    return;
}

void destroyPlatform(vector<Platform> &plat){
    if(plat[0].ycen >= 50){
        plat.erase(plat.begin());
    }
}


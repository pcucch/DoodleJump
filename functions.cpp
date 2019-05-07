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

void destroy_win(WINDOW *local_win) {
    wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(local_win);
    delwin(local_win);
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

void drawEnemies(const vector<Enemy> &en, WINDOW *win) {
    for (int i = 0; i < en.size(); i++) {
        en[i].draw(win);
    }
}

void moveEverything(Doodler &doodler, vector<Platform> &plat, vector<Enemy> &enemy){
    doodler.ypos++;
    for (int i = 0; i < plat.size(); ++i) {
        plat[i].ycen++;
        if(i < enemy.size()) {
            enemy[i].ycen++;
        }
    }
    usleep(100);
}

void clearPrevPlatform(vector<Platform> &plat, WINDOW *win){
    for (int i = 0; i < plat.size(); i++){
        plat[i].clear(win);
    }
}

void clearPrevEnemy(vector<Enemy> &enem, WINDOW *win) {
    for (int i = 0; i < enem.size(); i++) {
        enem[i].clear(win);
    }
}

void addPlat(vector<Platform> &v) {
    Platform p(rand() % 50 + 5);
    v.push_back(p);
    return;
}

void addEnem(vector<Enemy> &v) {
    Enemy e(rand() % 40 + 10, 2);
    e.init();
    v.push_back(e);
}

void destroyPlatform(vector<Platform> &plat){
    if(plat[0].ycen >= 50) {
        plat.erase(plat.begin());
    }
}

void destroyEnemy(vector<Enemy> &en) {
    if (en.size() != 0) {
        if (en[0].ycen >= 50) {
            en.erase(en.begin());
        }
    }
}

void emptyPlatVector(vector<Platform> &plat){
    if (plat.size() != 0){
        plat.erase(plat.begin(), plat.begin() + plat.size());
    }
}

void emptyEnemyVector(vector<Enemy> &en){
    if (en.size() != 0){
        en.erase(en.begin(), en.begin() + en.size());
    }
}

void clearBoard(WINDOW *win, vector<Platform> &plat, vector<Enemy> &en){
    destroy_win(win);
    emptyPlatVector(plat);
    emptyEnemyVector(en);

}

void refreshBoard(Doodler &doodler, vector<Platform> &platforms, vector<Enemy> &enemies, DeathSpikes &spikes, WINDOW *gamewin, int dead){
    destroyPlatform(platforms);             //Checks for platforms going offscreen and deletes them from the vector to stop a memory leak
    destroyEnemy(enemies);
    spikes.draw(gamewin);
    doodler.clearPrev(gamewin);
    drawPlatforms(platforms, gamewin);
    drawEnemies(enemies, gamewin);
    wattron(gamewin, dead);
    doodler.draw(gamewin);
    wattroff(gamewin, dead);
    wrefresh(gamewin);
}

void printQuote(int row, int col){
    switch (rand() % 9) {
        case 0:
            mvprintw(row/2,col/2 - 20,"%s","\"I Suppose That Is Just The Nature of Things\"");
            mvprintw(row/2 + 1,col/2 - 5,"%s","-S. Mintchev");
            break;
        case 1:
            mvprintw(row/2,col/2 - 20,"%s","\"At Columbia, They Use L O N G Transistors\"");
            mvprintw(row/2 + 1,col/2 - 5,"%s","-T. Cumberbatch");
            break;
        case 2:
            mvprintw(row/2,col/2 - 20,"%s","\"Let's Begin\"");
            mvprintw(row/2 + 1,col/2 - 5,"%s","-A. Wolf");
            break;
        case 3:
            mvprintw(row/2,col/2 - 20,"%s","\"The Answer Is Simple\"");
            mvprintw(row/2 + 1,col/2 - 5,"%s","-Z. Akkerman");
            break;
        case 4:
            mvprintw(row/2,col/2 - 6,"%s","*sips water*");
            mvprintw(row/2 + 1,col/2 - 5,"%s","-L. Vulakh");
            break;
        case 5:
            mvprintw(row/2,col/2 - 20,"%s","*draws stem-leaf plot*");
            mvprintw(row/2 + 1,col/2 - 5,"%s","-R. Smyth");
            break;
        case 6:
            mvprintw(row/2,col/2 - 20,"%s","\"You Know How This Works, Man");
            mvprintw(row/2 + 1, col/2 - 20, "%s", "The Guy With The Gun Gets to Tell The Truth\"");
            mvprintw(row/2 + 2,col/2 - 5,"%s","-K. Kolack");
            break;
        case 7:
            mvprintw(row/2,col/2 - 20,"%s","\"It Smells Like Updog in Here\"");
            mvprintw(row/2 + 1,col/2 - 5,"%s","-Revans");
            break;
        case 8:
            mvprintw(row/2,col/2 - 20,"%s","\"Ouch\"");
            mvprintw(row/2 + 1,col/2 - 5,"%s","-R. Smyth");
            break;
    }

}
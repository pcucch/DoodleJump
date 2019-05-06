#ifndef DOODLEJUMP_H
#define DOODLEJUMP_H
#include <vector>

using namespace std;

//CLASSES

class Gameobject {
public:
    virtual void draw(WINDOW *win) const = 0;
};

class DeathSpikes : public Gameobject {
public:
    int xpos[61];
    int ypos;

    DeathSpikes();

    void draw(WINDOW *win) const;
};


class Platform : public Gameobject {
public:
    int xcen, ycen;
    int xplace[5];

    Platform();

    Platform(int x, int y);

    ~Platform();

    void draw(WINDOW *win) const ;
};

class Doodler : public Gameobject {
public:

    int xpos, ypos;
    int prevxpos, prevypos;
    int jumptrue;       //1 if doodler is jumping
    int yVelocity;
    int xspeed;
    int count;
    int jumpheight;
    int timekeep;

    Doodler();

    void draw(WINDOW *win) const;

    void clearPrev(WINDOW *win);

    int checkDeath();

    void moveLeft(int amount);

    void moveRight(int amount);

    void jump(vector<Platform> &plats);

    void time_stone();

};

class Enemy : public Gameobject {
public:
    void draw();
};

class Boolet : public Gameobject {
public:
    void draw();
};

//FUNCTIONS

WINDOW *create_newwin(int height, int width, int starty, int startx);

int _kbhit();

void drawPlatforms(const vector<Platform> &plat, WINDOW *win);

#endif // DOODLEJUMP_H ///:~



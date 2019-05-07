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
    int prevxpos, prevypos;

    Platform(int x);

    Platform(int x, int y);

    ~Platform();

    void draw(WINDOW *win) const;

    void clear(WINDOW *win) const;
};

class Enemy : public Gameobject {
public:
    int xcen, ycen;
    int xplace[8];
    int prevxpos, preypos;

    Enemy(int x, int y);

    ~Enemy();

    void draw(WINDOW *win) const;

    void init();

    void clear(WINDOW *win) const;

    void destroy(WINDOW *win);

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

    int reachLim();

    void contact(vector<Enemy> &en, int &jump, WINDOW *win);

};


class Boolet : public Gameobject {
public:
    void draw();
};

//FUNCTIONS

WINDOW *create_newwin(int height, int width, int starty, int startx);

int _kbhit();

void drawPlatforms(const vector<Platform> &plat, WINDOW *win);

void drawEnemies(const vector<Enemy> &en, WINDOW *win);

void clearPrevPlatform(vector<Platform> &plat, WINDOW *win);

void clearPrevEnemy(vector<Enemy> &enem, WINDOW *win);

void moveEverything(Doodler &doodler, vector<Platform> &plat, vector<Enemy> &enem);

void addPlat(vector<Platform> &v);

void addEnem(vector<Enemy> &v);

void destroyPlatform(vector<Platform> &plat);

void destroyEnemy(vector<Enemy> &en);

#endif // DOODLEJUMP_H ///:~



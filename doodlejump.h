#ifndef DOODLEJUMP_H
#define DOODLEJUMP_H

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

class Doodler : public Gameobject {
public:

    int xpos, ypos;
    int prevxpos, prevypos;
    int jumptrue;       //1 if doodler is jumping
    int yVelocity;
    int xspeed;
    float timekeep;

    Doodler();

    void draw(WINDOW *win) const;

    void clearPrev(WINDOW *win);

    int checkDeath();

    void moveLeft(int amount);

    void moveRight(int amount);

    void jump();

    void time_stone();

};


class Platform : public Gameobject {
public:
    void draw();
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

#endif // DOODLEJUMP_H ///:~



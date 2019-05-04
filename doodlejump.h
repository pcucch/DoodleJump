#ifndef DOODLEJUMP_H
#define DOODLEJUMP_H

class Gameobject {
public:
    virtual void draw(WINDOW *win) const = 0;
};

class DeathSpikes : public Gameobject {
public:

};

class Doodler : public Gameobject {
public:

    int xpos, ypos;
    int yVelocity;
    int xspeed;

    Doodler();

    void draw(WINDOW *win) const;

    void clearPrev(WINDOW *win);

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

WINDOW *create_newwin(int height, int width, int starty, int startx);

#endif // DOODLEJUMP_H ///:~



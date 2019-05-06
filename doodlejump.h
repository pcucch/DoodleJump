#ifndef DOODLEJUMP_H
#define DOODLEJUMP_H

class Gameobject {
public:
    virtual void draw(WINDOW *win) const = 0;
};

class DeathSpikes : public Gameobject {
public:

};

class Enemy : public Gameobject {
public:
    Enemy(int y, int x, int speed = 0);
    int xpos, ypos;
    void draw(WINDOW *win) const;
};

class Platform : public Gameobject {
public:
    Platform(int x, int speed);
    int xpos, ypos;
    int yVelocity;
    int xspeed;
    void draw(WINDOW *win) const;
};

class Doodler : public Gameobject {
public:

    int xpos, ypos;
    int yVelocity;
    int xspeed;

    Doodler();

    void draw(WINDOW *win) const;
    void shootEnemy(WINDOW *win, Enemy e);
    void shootNothing(WINDOW *win);
    void clearPrevDood(WINDOW *win);

};

class Boolet : public Gameobject {
	int xpos;
	int yVelocity;
public:
    	Boolet(int y, int x);
	int ypos;
    	void draw(WINDOW *win) const;
	void clearPrevBoolet(WINDOW *win);
};


//level class
class Level {
public:
	Level(int difficulty);
};

WINDOW *create_newwin(int height, int width, int starty, int startx);

#endif // DOODLEJUMP_H ///:~



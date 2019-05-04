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

    Doodler(){
        xpos = 31;          //x position of doodler at start of the game
        ypos = 10;          //y position of doodler at start of the game
        yVelocity = 0;
    }
    void draw(WINDOW *win) const{
        mvwprintw(win, ypos, xpos, "X");
    }
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

#endif // DOODLEJUMP_H ///:~

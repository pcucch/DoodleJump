#ifndef DOODLEJUMP_H
#define DOODLEJUMP_H

class Gameobject {
public:
        virtual void draw() = 0;
  
};
   
class Doodler : public Gameobject {
public:
        void draw();
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

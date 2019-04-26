#include <iostream>
#include "doodlejump.h"
using namespace std;

int main() {
        Doodler d;
        Platform p;
        Enemy Risbud;
        Boolet b;
        Risbud.draw();
        cout << "\n\n\n" << endl;
        b.draw();
        cout << "\n\n\n" << endl;
        d.draw();
        p.draw();
        return 0;
}


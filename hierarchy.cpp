#include <iostream>
#include "doodlejump.h"

using namespace std;


void Doodler::draw(void) {
	cout << "H" << endl;
}


void Platform::draw(void) {
	cout << "￣￣￣" << endl;
}


void Enemy::draw(void) {
	cout << "________" << endl;
	cout << "|RISBUD|" << endl;
	cout << "￣￣￣￣" << endl;
}


void Boolet::draw(void) {
	cout << "|" << endl;
}



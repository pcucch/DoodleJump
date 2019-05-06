#include <iostream>
#include <level>

Level Start {
	stk.push(Platform);
	stk.push();
    for (int i=0; i<10; i++)
    {
        cout << "Popping: " << intStack.top() << endl;
        intStack.pop();
    }

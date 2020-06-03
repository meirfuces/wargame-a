/**
  Demo for the war-game exercise.

  @author Oz Levi
  @since  2020-05
**/

#include <iostream>
#include "DemoGame.hpp"  

using namespace std;

using namespace WarGame;
int main() {
DemoGame demoGame;
	cout << "The winner is:\n " << demoGame.play() << endl;
    return 0;
}

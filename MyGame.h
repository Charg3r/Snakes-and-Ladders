#pragma once
#include "Board.h"
#include "Dice.h"
#include <string>

using namespace std;

class MyGame
{
public:
	MyGame();
	void start(Board);
	~MyGame();

private:
	int num_players;
	Dice dice;

};
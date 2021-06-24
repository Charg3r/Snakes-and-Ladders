#include "Dice.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

Dice::Dice()
{
	srand(time(0));
}

void Dice::rollDice()
{
	dice = (rand() % 6) + 1;
}

int Dice::getDice()
{
	return dice;
}

Dice::~Dice()
{
}

#pragma once

class Dice
{
public:
	Dice();
	void rollDice();
	int getDice();
	~Dice();

private:
	int dice;
};
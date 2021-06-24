#pragma once
#include "Player.h"
#include <string>

using namespace std;

class Tile
{
public:
	Tile();
	Tile(int, int, char);
	void setReward(int);
	void setPenalty(int);
	void setType(char);
	int getPenalty();
	int getReward();
	char getType();
	~Tile();

private:
	int reward, penalty;
	char type;
};
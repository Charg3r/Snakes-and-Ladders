#include "Tile.h"

using namespace std;

Tile::Tile()
{
	penalty = -3;
	reward = 3;
	type = 'N';
}

Tile::Tile(int p, int r, char t)
{
	penalty = -p;
	reward = r;
	type = t;
}

void Tile::setReward(int r)
{
	reward = r;
}

void Tile::setPenalty(int p)
{
	penalty = p;
}

void Tile::setType(char t)
{
	type = t;
}

int Tile::getPenalty()
{
	return penalty;
}

int Tile::getReward()
{
	return reward;
}

char Tile::getType()
{
	return type;
}

Tile::~Tile()
{
}
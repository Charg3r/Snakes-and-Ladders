#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player();
	void setTurn(int);
	void setPlayerNum(int);
	void setTileNum(int);
	int getTurn();
	int getPlayerNum();
	int getTileNum();
	~Player();

private:
	int turn, player_num, tile_num;
};
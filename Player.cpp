#include "Player.h"

using namespace std;

Player::Player()
{
	turn = 1;
	tile_num = 1;
}

void Player::setTurn(int t)
{
	turn = t;
}

void Player::setPlayerNum(int pn)
{
	player_num = pn;
}

void Player::setTileNum(int tn)
{
	tile_num = tn;
}

int Player::getTurn()
{
	return turn;
}

int Player::getPlayerNum()
{
	return player_num;
}

int Player::getTileNum()
{
	return tile_num;
}


Player::~Player()
{
}
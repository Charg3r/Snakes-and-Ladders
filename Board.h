#pragma once
#include "Tile.h"
#include "Snake.h"
#include "Ladder.h"
#include "Player.h"
#include <string>
#include <vector>

using namespace std;

class Board
{
public:
	Board();
	Board(int, int, int, int, int, int, int, char);
	int getNumPlayers();
	int getNumTiles();
	int getNumTurns();
	char getGameType();
	void setNumPlayers(int);
	void setNumTiles(int);
	void setNumTurns(int);
	void setGameType(char);

	int getPlayerTileNum(int);
	int getPlayerTurn(int);
	int getPlayerNum(int);
	void setPlayerTileNum(int, int);
	void setPlayerTurn(int, int);

	char getTileType(int);
	int getTileReward(int);
	int getTilePenalty(int);

	~Board();

	// friend ostream& operator << (ostream&, Board);

private:
	int num_tiles, num_players, num_snakes, num_ladders, num_turns;
	char game_type;
	Tile* tiles;
	Player* players;
};
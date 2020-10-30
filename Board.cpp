#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

Board::Board()
{
	num_tiles = 30;
	num_turns = 25;
	num_players = 2;
	num_snakes = 3;
	num_ladders = 3;
	game_type = 'M';

	//Change array size
	tiles = new Tile[num_tiles];
	players = new Player[num_players];

	//Fill player array
	for (int i = 0; i < num_players; i++)
	{
		players[i].setPlayerNum(i + 1);
	}

	//Fill tile array
	for (int i = 0; i < num_tiles; i++)
	{
		tiles[i].setType('N');
	}

	//Fill random snakes
	for (int i = 0; i < num_snakes; i++)
	{
		int random_number = rand() % (num_tiles - 2) + 1;

		while (tiles[random_number].getType() != 'N')
		{
			int random_number = rand() % (num_tiles - 2) + 1;
		}

		while (tiles[random_number].getType() == 'N')
		{
			tiles[random_number].setType('S');
		}
	}

	//Fill random ladders
	for (int i = 0; i < num_ladders; i++)
	{
		int random_number = rand() % (num_tiles - 2) + 1;

		while (tiles[random_number].getType() != 'N')
		{
			int random_number = rand() % (num_tiles - 2) + 1;
		}

		while (tiles[random_number].getType() == 'N')
		{
			tiles[random_number].setType('L');
		}
	}
}

Board::Board(int t, int s, int l, int p, int r, int pl, int tu, char gt)
{
	num_tiles = t;
	num_turns = tu;
	num_players = pl;
	num_snakes = s;
	num_ladders = l;
	game_type = gt;

	//Change array size
	tiles = new Tile[num_tiles];
	players = new Player[num_players];

	//Fill player array
	for (int i = 0; i < num_players; i++)
	{
		players[i].setPlayerNum(i + 1);
	}

	//Fill tile array
	for (int i = 0; i < num_tiles; i++)
	{
		tiles[i].setType('N');
	}

	//Fill random snakes
	for (int i = 0; i < num_snakes; i++)
	{
		int random_number = rand() % (num_tiles - 2) + 1;

		while (tiles[random_number].getType() != 'N')
		{
			int random_number = rand() % (num_tiles - 2) + 1;
		}

		while (tiles[random_number].getType() == 'N')
		{
			tiles[random_number].setType('S');
			tiles[random_number].setPenalty(p);
		}
	}

	//Fill random ladders
	for (int i = 0; i < num_ladders; i++)
	{
		int random_number = rand() % (num_tiles - 2) + 1;

		while (tiles[random_number].getType() != 'N')
		{
			int random_number = rand() % (num_tiles - 2) + 1;
		}

		while (tiles[random_number].getType() == 'N')
		{
			tiles[random_number].setType('L');
			tiles[random_number].setReward(r);
		}
	}
}

int Board::getNumPlayers()
{
	return num_players;
}

int Board::getNumTiles()
{
	return num_tiles;
}

int Board::getNumTurns()
{
	return num_turns;
}

char Board::getGameType()
{
	return game_type;
}

int Board::getPlayerTileNum(int i)
{
	return players[i].getTileNum();
}

int Board::getPlayerTurn(int i)
{
	return players[i].getTurn();
}

int Board::getPlayerNum(int i)
{
	return players[i].getPlayerNum();
}

void Board::setNumPlayers(int np)
{
	num_players = np;
}

void Board::setNumTiles(int nt)
{
	num_tiles = nt;
}

void Board::setNumTurns(int tu)
{
	num_turns = tu;
}

void Board::setGameType(char gt)
{
	game_type = gt;
}

void Board::setPlayerTileNum(int tn, int i)
{
	players[i].setTileNum(tn);
}

void Board::setPlayerTurn(int tu, int i)
{
	players[i].setTurn(tu);
}

char Board::getTileType(int i)
{
	return tiles[i].getType();
}

int Board::getTileReward(int i)
{
	return tiles[i].getReward();
}

int Board::getTilePenalty(int i)
{
	return tiles[i].getPenalty();
}

Board::~Board()
{
}
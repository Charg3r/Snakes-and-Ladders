#include "MyGame.h"
#include "Player.h"
#include "Dice.h"
#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

MyGame::MyGame()
{
}

void MyGame::start(Board board)
{
	int current_turn = 1, winner = 0; // Control variable
	char menu = 'C'; // Control variable GameType

	if (board.getGameType() == 'M') {
		cout << "Press enter to start the game..." << endl;
		cin.get(); // wait for input
	}

	// The game stops when there's a winner or there are no more turns
	while (current_turn <= board.getNumTurns() && winner == 0 && menu == 'C') {
		for (int i = 0; i < board.getNumPlayers(); i++) {
			dice.rollDice();
			board.setPlayerTurn(current_turn, i); // Update player turn
			
			// If the player lands on L
			if (board.getTileType(board.getPlayerTileNum(i)) == 'L') {
				cout << board.getPlayerTurn(i) << " " << board.getPlayerNum(i) << " " << board.getPlayerTileNum(i) << " " << dice.getDice() << " " << board.getTileType(board.getPlayerTileNum(i)) << " " << board.getPlayerTileNum(i) + dice.getDice() + board.getTileReward(board.getPlayerTileNum(i)) << endl;
				board.setPlayerTileNum(board.getPlayerTileNum(i) + dice.getDice(), i); // Update player position
			}
			
			// If the player lands on S
			else if (board.getTileType(board.getPlayerTileNum(i)) == 'S') {
				cout << board.getPlayerTurn(i) << " " << board.getPlayerNum(i) << " " << board.getPlayerTileNum(i) << " " << dice.getDice() << " " << board.getTileType(board.getPlayerTileNum(i)) << " " << board.getPlayerTileNum(i) + dice.getDice() + board.getTilePenalty(board.getPlayerTileNum(i)) << endl;
				board.setPlayerTileNum(board.getPlayerTileNum(i) + dice.getDice(), i); // Update player position
			}

			// If the player lands on a normal tile
			else {
				cout << board.getPlayerTurn(i) << " " << board.getPlayerNum(i) << " " << board.getPlayerTileNum(i) << " " << dice.getDice() << " " << board.getTileType(board.getPlayerTileNum(i)) << " " << board.getPlayerTileNum(i) + dice.getDice() << endl;
				board.setPlayerTileNum(board.getPlayerTileNum(i) + dice.getDice(), i); // Update player position
			}

			// Breaks the loop if there's a winner
			if (board.getPlayerTileNum(i) >= board.getNumTiles()) {
				winner = i + 1;
				break;
			}
			
			// Input in case the game was Manual
			if (board.getGameType() == 'M' || board.getGameType() == 'm') {
				cin >> menu;

				if (menu == 'E')
					break;
			}
		}

		current_turn++; // Increase current turn
	}
	if (winner != 0) // 
		cout << "Player " << winner << " is the winner" << endl;

	cout << "Thanks for playing!!" << endl;
}

MyGame::~MyGame()
{
}
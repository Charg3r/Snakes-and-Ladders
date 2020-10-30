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

	if (board.getGameType() == 'M')
	{
		cout << "Press enter to start the game..." << endl;
		cin.get(); // wait for input
	}

	while (current_turn <= board.getNumTurns() && winner == 0 && menu == 'C') //Loop que se detiene cuando se alcanza el máximo de turnos o ya hay un ganador
	{
		for (int i = 0; i < board.getNumPlayers(); i++)
		{
			dice.rollDice();
			board.setPlayerTurn(current_turn, i); //Actualizar el turno del jugador 

			if (board.getTileType(board.getPlayerTileNum(i)) == 'L') //Condicional si el jugador cae en una escalera
			{
				cout << board.getPlayerTurn(i) << " " << board.getPlayerNum(i) << " " << board.getPlayerTileNum(i) << " " << dice.getDice() << " " << board.getTileType(board.getPlayerTileNum(i)) << " " << board.getPlayerTileNum(i) + dice.getDice() + board.getTileReward(board.getPlayerTileNum(i)) << endl;
				board.setPlayerTileNum(board.getPlayerTileNum(i) + dice.getDice(), i); //Actualizar Posición del jugador
			}

			else if (board.getTileType(board.getPlayerTileNum(i)) == 'S') //Condicional si el jugador cae en una serpiente
			{
				cout << board.getPlayerTurn(i) << " " << board.getPlayerNum(i) << " " << board.getPlayerTileNum(i) << " " << dice.getDice() << " " << board.getTileType(board.getPlayerTileNum(i)) << " " << board.getPlayerTileNum(i) + dice.getDice() + board.getTilePenalty(board.getPlayerTileNum(i)) << endl;
				board.setPlayerTileNum(board.getPlayerTileNum(i) + dice.getDice(), i); //Actualizar posición del jugador
			}

			else //Condicional si cae en una casilla normal
			{
				cout << board.getPlayerTurn(i) << " " << board.getPlayerNum(i) << " " << board.getPlayerTileNum(i) << " " << dice.getDice() << " " << board.getTileType(board.getPlayerTileNum(i)) << " " << board.getPlayerTileNum(i) + dice.getDice() << endl;
				board.setPlayerTileNum(board.getPlayerTileNum(i) + dice.getDice(), i); //Actualizar posición del jugador
			}

			if (board.getPlayerTileNum(i) >= board.getNumTiles()) //Condicional para determinar si ya ha habido un ganador
			{
				winner = i + 1; //Actualizar variable que representa al ganador
				break; //Romper el for loop
			}

			if (board.getGameType() == 'M') // Input para continuar el juego en caso de que sea manual
			{
				cin >> menu;

				if (menu == 'E')
					break;
			}
		}

		current_turn++; // Aumentar en 1 el turno actual
	}
	if (winner != 0) // Condicional por si el jugador decide salirse a medio juego
	{
		cout << "Player " << winner << " is the winner" << endl;
	}

	cout << "Thanks for playing!!" << endl;
}

MyGame::~MyGame()
{
}
/*  main.cpp
    This is an object oriented program that simulates a S&L board
*/

#include <iostream>
#include <string>
#include "MyGame.h"

using namespace std;

int main()
{
    int tiles, snakes, ladders, penalty, reward, players, turns;
    char game_type;

    cout << "Select number of tiles: " << endl;
    cin >> tiles;
    cout << "Select number of snakes: " << endl;
    cin >> snakes;
    cout << "Select number of ladders: " << endl;
    cin >> ladders;
    cout << "Select the penalty for landing on a snake tile: " << endl;
    cin >> penalty;
    cout << "Select the reward for landing on a ladder tile: " << endl;
    cin >> reward;
    cout << "Select number of players: " << endl;
    cin >> players;
    cout << "Select number of turns: " << endl;
    cin >> turns;
    cout << "Select Game Type, A for Automatic, M for Manual" << endl;
    cin >> game_type;


    while (game_type != 'A' && game_type != 'M' && game_type != 'a' && game_type != 'm') {
        cout << "Type a valid character, A for Automatic, M for Manual: " << endl;
        cin >> game_type;
    }

    Board board(tiles, snakes, ladders, penalty, reward, players, turns, game_type);

    MyGame Game1;
    Game1.start(board);

    return 0;
}
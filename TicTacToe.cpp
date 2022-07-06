#include "TicTacToe.h"
#include<iostream>
#include <stdlib.h>
using namespace std;
bool TicTacToe::verify(int pos)
{
	if (board[pos] <= 57 && board[pos]>=48)
		return true;
	return false;
}
bool TicTacToe::check(int i, int jumps) {
		if (board[i] == board[i + (jumps)] && board[i] == board[i + (2*jumps)]) {
			cout << "\033[31m" << board[i] << " WINS!" << "\033[0m" << endl;
			score(board[i]);
			victory = true;
			return true;
		}
		return false;
}

bool TicTacToe::check()
{
	for (int  i = 0; i < 7; i+=3)
	{
		if (check(i, 1)) {
			return true;
		}

	}
	for (int i = 0; i < 3; i++)
	{
		if (check(i, 3)) {
			return true;
		}
	}
	for (int i = 0; i < 3; i+=2)
	{
		if (i == 0) {
			if (check(i, 4)) {
				return true;
			}
		}
		else {
			if (check(i, 2)) {
				return true;
			}
		}
	}
	return false;
}
void TicTacToe::render()
{
	system("CLS");

	cout << "Score: Player-1(X): " << score_p1 << " || Player-2(O): " << score_p2 << endl;
	for (int i = 1; i <= 9; i++)
	{

		if (i % 3 == 0 ) {
			cout << " " << board[i - 1] << " " << endl;
			if (i == 9)
				continue;
			cout << "---|---|---" << endl;
			continue;
		}
		cout << " " << board[i - 1] << " " << '|';
	}
	cout << endl;

}

void TicTacToe::score(char temp)
{
	if (temp == 'X') {
		++score_p1;
	}
	else
	{
		++score_p2;
	}
}

void TicTacToe::play()
{
	int player;
	int pos;
	
	while (counter < 9) {

		if (counter % 2 == 0) {
			player = 1;
		}
		else {
			player = 2;
		}

		render();
		if (counter >= 4) {
			if (check()) {
				break;
			}
		}

		cout << "Player " << player << " Enter a number: ";
		cin >> pos;
		while (!verify(pos)) {
			cout << endl << "Enter a valid position number: ";
			cin >> pos;
		}
		if (player == 1) {
			board[pos] = 'X';
		}
		else {
			board[pos] = 'O';
		}
		counter++;
	}
	if (!victory) {
		cout << "\033[31m" << "DRAW!" << "\033[0m" << endl << "1)Play again\n2)exit";
	}
	cout << "\n1)Continue\n2)Reset\n3)exit\n";
	string tmp;
	while (1) {
		cin >> tmp;
		if (tmp == "1" || tmp == "2") {
			int fill = 48;

			for (int i = 0; i < 9; i++)
			{
				board[i] = fill;
				fill++;
			}
			counter = 0;
			victory = false;
			if (tmp == "2") {
				score_p1 = 0, score_p2 = 0;
			}
			play();
		}
		else if (tmp == "3") {
			return;
		}
		else {
			cout << "\nEnter a correct number " << endl;
		}
	}
}

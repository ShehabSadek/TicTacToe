#pragma once
class TicTacToe
{
private:
	char board[9] = {'0','1', '2', '3', '4', '5', '6', '7', '8'};
	int counter = 0;
	int score_p1=0, score_p2=0;
	bool victory = false;
	bool verify(int pos);
	bool check(int i, int jumps);
	bool check();
	void render();
	void score(char temp);
public :
	void play();
};
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
using namespace std;

class Game
{
	int tries;
	char board[5][5];
	char mask[5][5];
	map<string, char> boardMap;
	map<string, char&> maskedMap;
public:
	Game()
	{
		tries = 0;
		board[0][0] = '#';
		char letterLegend = 'A';
		char numberLegend = '1';
		char guess[8] = { '!', '$', '*', '%', '+', '-', '@', '=' };
		int k = 0;
		for (size_t i = 1; i < 5; i++)
		{
			board[0][i] = letterLegend;
			letterLegend++;
			board[i][0] = numberLegend;
			numberLegend++;
		}

		for (size_t i = 1; i < 5; i++)
		{
			for (size_t j = 1; j < 5; j++)
			{
				board[i][j] = guess[k++];
				if (k == 8)
					k = 0;
			}
		}

		for (size_t i = 0; i < 5; i++)
		{
			mask[0][i] = board[0][i];
			mask[i][0] = board[i][0];
		}

		for (size_t i = 1; i < 5; i++)
		{
			for (size_t j = 1; j < 5; j++)
			{
				mask[i][j] = '?';
			}
		}

		boardMap = { {"A1", board[1][1]}, {"A2", board[2][1]}, {"A3", board[3][1]}, {"A4", board[4][1]},
					{"B1", board[1][2]}, {"B2", board[2][2]}, {"B3", board[3][2]}, {"B4", board[4][2]},
					{"C1", board[1][3]}, {"C2", board[2][3]}, {"C3", board[3][3]}, {"C4", board[4][3]},
					{"D1", board[1][4]}, {"D2", board[2][4]}, {"D3", board[3][4]}, {"D4", board[4][4]} };

		maskedMap = { {"A1", mask[1][1]}, {"A2", mask[2][1]}, {"A3", mask[3][1]}, {"A4", mask[4][1]},
					{"B1", mask[1][2]}, {"B2", mask[2][2]}, {"B3", mask[3][2]}, {"B4", mask[4][2]},
					{"C1", mask[1][3]}, {"C2", mask[2][3]}, {"C3", mask[3][3]}, {"C4", mask[4][3]},
					{"D1", mask[1][4]}, {"D2", mask[2][4]}, {"D3", mask[3][4]}, {"D4", mask[4][4]} };
	}
	
	void display()
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
				cout << mask[i][j] << "\t";
			cout << endl << endl;
		}
	}

	void reset(char cell1, char cell2)
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (cell1 != cell2)
				{
					if (mask[i][j] == cell1 || mask[i][j] == cell2)
						mask[i][j] = '?';
				}
			}
		}
	}

	string getInput()
	{
		string guess;
		cin >> guess;
		while (!verifyInput(guess))
		{
			if (guess == "x" || guess == "X")
				break;
			cout << "Wrong input! Try again!" << endl;
			cout << "Cell 1: ";
			cin >> guess;
		}
		return guess;
	}

	bool verifyInput(string cell)
	{
		map<string, char>::iterator it = boardMap.find(cell);
		if (it != boardMap.end())
			return true;
		return false;
	}

	bool isMatch(char cell1, char cell2)
	{
		return cell1 == cell2;
	}

	bool quit(string guess)
	{
		if (guess == "x" || guess == "X")
		{
			cout << "\nYou wanna leave a memory!" << endl;
			return true;
		}
		return false;

	}

	bool endGame()
	{
		for (size_t i = 1; i < 5; i++)
			for (size_t j = 1; j < 5; j++)
				if (mask[j][i] != board[j][i])
					return false;
		return true;
	}

	void playGame()
	{
		string guess;
		string guess2;
		char cell1, cell2;
		
		while (1)
		{
			system("cls");
			cout << "Enter 'x' to exit game." << endl;
			cout << "Enter cell number to open: (for example: enter A1, or B2 to open one cell on board)" << endl;	
			display();
			cout << "Cell 1: ";
			guess = getInput();		
			if (quit(guess))
				break;
			maskedMap.find(guess)->second = boardMap.find(guess)->second;
			cell1 = boardMap.find(guess)->second;
			display();

			//-------------------------------------------------------------

			cout << "Guess cell to match, Cell 2: ";
			guess2 = getInput();
			cout << endl;
			while (guess == guess2) 
			{
				if (guess2 == "x" || guess2 == "X")
					break;
				cout << "Cell " << guess << " is already open!" << endl;
				cout << "Guess cell to match, Cell 2: ";
				cin >> guess2;
			}
			if (quit(guess2))
				break;
			maskedMap.find(guess2)->second = boardMap.find(guess2)->second;
			cell2 = boardMap.find(guess2)->second;
			display();
			tries++;
			if (!isMatch(cell1, cell2))
			{
				reset(cell1, cell2);
				cout << "Guess again!" << endl;
			}
			else
				cout << "Great! You found a match!" << endl;

			if (endGame())
			{
				cout << "Congratulations!\nYou made a memory!\nYou needed " << tries << " tries to complete the game!" << endl;
				break;
			}
			system("pause");
		}		
	}
};
#endif


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

class Player {
	int score = 0;
	int handSum = 0;

public:

	void hand() {
		;
	}
	int move(int j) {
		return 0;
	}


	int& get_Score()
	{
		return score;
	}
	int& getHand()
	{
		return handSum;
	}
};



class HumanPlayer : public Player {
	int score = 0;
	int handSum = 0;
public:
	void hand();
	int move(int j);
	int& getHand();
	int& get_Score();
};

void HumanPlayer::hand()
{
	int n, m;
	cout << "How many coins do You wan't?" << endl;
	cin >> m;
	if (m > 0)
	{
		std::vector<int> kune(m);
		cout << "What coins do You wan't?" << endl;
		for (size_t i = 0; i < kune.size(); )
		{
			cin >> n;
			if (n == 0 || n == 1 || n == 2 || n == 5)
			{
				kune[i] = n;
				i++;
			}
			else
				cout << "You chose the coin that doesn't exist! Enter 1, 2 or 5 to continue." << endl;
		}
		handSum = accumulate(kune.begin(), kune.end(), handSum);
	}
	else if (m == 0)
		handSum = 0;
}

int HumanPlayer::move(int j)
{
	int guess;
	cout << "Guess  the sum in player " << j << " hand: " << endl;
	cin >> guess;
	return guess;
}

int& HumanPlayer::get_Score()
{
	return score;
}
int& HumanPlayer::getHand()
{
	return handSum;
}


class Computer : public Player {
	int score = 0;
	int handSum = 0;
public:
	void hand()
	{
		int r;
		int n = 3;
		vector<int> coins{ 1, 2, 5 };
		for (size_t i = 0; i < 3; i++)
		{
			r = rand() % n;
			handSum += coins[r];
			coins.erase(coins.begin() + r);
			n--;
		}
	}
	int move(int j)
	{
		vector<int> moves{ 1, 2, 3, 5, 6, 7, 8 };
		cout << "Guess  the sum in player " << j << " hand: " << endl;
		return moves[rand() % 7];
	}
	int& get_Score()
	{
		return score;
	}
	int& getHand()
	{
		return handSum;
	}
};

#endif
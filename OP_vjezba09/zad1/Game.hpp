#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"

class Game
{
	int score, numberOfPlayers;
public:
	Game(int s, int n)
	{
		score = s;
		numberOfPlayers = n;
	};

	bool checkScore(vector<Player> scr) {
		for (size_t i = 0; i < scr.size(); i++)
		{
			if (scr[i].get_Score() >= score)
				return true;
		}
		return false;
	};

	vector<Player> getPlayers()
	{
		int h;
		cout << "How many humans?" << endl;
		cin >> h;
		vector<HumanPlayer> humans(h);
		vector<Computer> computers(numberOfPlayers - h);
		vector<Player> players(numberOfPlayers);

		for (size_t i = 0; i < humans.size(); i++)
			players.push_back(humans[i]);
		for (size_t i = 0; i < computers.size(); i++)
			players.push_back(computers[i]);

		return players;
	}

	void playGame()
	{
		int r = 0;

		vector<Player> players = getPlayers();

		while (!checkScore(players))
		{
			int guess;
			for (size_t i = 0; i < players.size(); i++)
			{
				cout << "Round " << ++r << endl;
				for (size_t k = 0; k < players.size(); k++)
				{
					cout << "Player " << k << ":" << endl;
					players[k].hand();
				}

				for (size_t j = 0; j < players.size(); j++)
				{
					if (j == i)
						j++;
					if (j >= players.size())
						break;
					cout << "Player " << i << ":" << endl;
					players[i].move(j);
					cin >> guess;
					if (guess == players[j].getHand())
					{
						cout << "Great! Score + 1!" << endl;
						players[i].get_Score()++;
						cout << players[i].get_Score() << endl;
					}
				}
				if (checkScore(players))
					break;
			}

		}
		for (size_t i = 0; i < players.size(); i++)
		{
			if (players[i].get_Score() >= score)
			{
				cout << "Congratulations! Player " << i << " won!" << endl;
				break;
			}
		}
	}

};

#endif 


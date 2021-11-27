#ifndef HANGMANCONTROLLER_H
#define HANGMANCONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HangmanController {
public:
    char letter{};
    vector<char> used_letters;

    void userEntry()
    {
        cout << "Enter letter: " << endl;
        cin >> letter;
        used_letters.push_back(letter);
    }

    void checkLetter(char letter, string movie, string& guess_movie, int& lives)
    {
        string tmp = movie;

        for (int i = 0; i < (int)movie.size(); i++)
        {
            tmp[i] = tolower(movie[i]);
            if (letter == tolower(movie[i]))
                guess_movie[i] = movie[i];
        }
        string::iterator it;
        it = find(tmp.begin(), tmp.end(), letter);
        if (it == tmp.end())
            lives--;
    }

    bool is_game_over(string movie, string guess_movie, int lives)
    {
        if (lives <= 0)
            return true;
        else if (movie == guess_movie)
            return true;
        else
            return false;
    }
};

#endif

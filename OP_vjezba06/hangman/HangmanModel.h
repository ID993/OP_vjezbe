#ifndef HANGMANMODEL_H
#define HANGMANMODEL_H

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;

class HangmanModel {
public:
    string movie;
    string guess_movie;
    int lives = 8;
    

    void get_movie(string& movie)
    {
        srand(time(NULL));
        vector<string> line(37);
        ifstream myfile("movie.txt");
        if (myfile.is_open())
        {
            for (int i = 0; i < 37; i++)
                getline(myfile, line[i]);
        }
        myfile.close();
        movie = line[rand() % 37];
    }

    void get_guess_movie(string movie, string& guess_movie)
    {
        guess_movie = movie;
        for (int i = 0; i < (int)guess_movie.size(); i++) {
            if (isalpha(guess_movie[i]) || isdigit(guess_movie[i]))
                guess_movie[i] = '-';
        }
    }
};

#endif
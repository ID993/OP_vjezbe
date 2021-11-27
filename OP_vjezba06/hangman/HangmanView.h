#ifndef HANGMANVIEW_H
#define HANGMANVIEW_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HangmanView {
public:

    void display_progress(string guess_movie)
    {
        cout << guess_movie << endl;
    }

    void display_used_letters(vector<char> used_letters)
    {
        for (int i = 0; i < (int)used_letters.size(); i++)
            cout << used_letters[i] << " ";
    }

    void display_Hangman(int lives)
    {

        if (lives == 8)
        {
            cout << "    _______" << endl;
            cout << "    | /    " << endl;
            cout << "    |/     " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
        else if (lives == 7)
        {
            cout << "    _______" << endl;
            cout << "    | / |  " << endl;
            cout << "    |/     " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
        else if (lives == 6)
        {
            cout << "    _______" << endl;
            cout << "    | / |  " << endl;
            cout << "    |/  O  " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
        else if (lives == 5)
        {
            cout << "    _______" << endl;
            cout << "    | / |  " << endl;
            cout << "    |/  O  " << endl;
            cout << "    |   |  " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
        else if (lives == 4)
        {
            cout << "    _______" << endl;
            cout << "    | / |  " << endl;
            cout << "    |/  O  " << endl;
            cout << "    |  /|  " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
        else if (lives == 3)
        {
            cout << "    _______" << endl;
            cout << "    | / |  " << endl;
            cout << "    |/  O  " << endl;
            cout << "    |  /|\\" << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
        else if (lives == 2)
        {
            cout << "    _______" << endl;
            cout << "    | / |  " << endl;
            cout << "    |/  O  " << endl;
            cout << "    |  /|\\" << endl;
            cout << "    |   |  " << endl;
            cout << "    |      " << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
        else if (lives == 1)
        {
            cout << "    _______" << endl;
            cout << "    | / |  " << endl;
            cout << "    |/  O  " << endl;
            cout << "    |  /|\\" << endl;
            cout << "    |   |  " << endl;
            cout << "    |  /   " << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
        else if (lives == 0)
        {
            cout << "    _______" << endl;
            cout << "    | / |  " << endl;
            cout << "    |/  O  " << endl;
            cout << "    |  /|\\" << endl;
            cout << "    |   |  " << endl;
            cout << "    |  / \\" << endl;
            cout << "    |      " << endl;
            cout << "___ | ____ " << endl;
        }
    }
};


#endif
#include "HangmanModel.h"
#include "HangmanView.h"
#include "HangmanController.h"


int main()
{
    HangmanModel hm;
    HangmanController hc;
    HangmanView hv;
    hm.get_movie(hm.movie);
    cout << hm.movie << '\n';
    hm.get_guess_movie(hm.movie, hm.guess_movie);
    cout << hm.guess_movie << '\n';
    while (!hc.is_game_over(hm.movie, hm.guess_movie, hm.lives))
    {
        hc.userEntry();
        hc.checkLetter(hc.letter, hm.movie, hm.guess_movie, hm.lives);
        hv.display_progress(hm.guess_movie);
        cout << "\nUsed letters: ";
        hv.display_used_letters(hc.used_letters);
        cout << "\nCurrent lives: " << hm.lives << '\n';
        cout << "============" << '\n';
        hv.display_Hangman(hm.lives);
        cout << "============" << '\n';
        Sleep(3000);
        system("cls");
        if (hm.movie == hm.guess_movie)
        {
            cout << "============" << '\n';
            hv.display_Hangman(hm.lives);
            cout << "============" << '\n';
            cout << "CONGRATULATIONS! YOU WON!" << endl;
            break;
        }
        else if (hm.lives <= 0)
        {
            cout << "============" << '\n';
            hv.display_Hangman(hm.lives);
            cout << "============" << '\n';
            cout << "SORRY! YOU LOST!" << endl;
            break;
        }
    }
}

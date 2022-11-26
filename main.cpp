
#include <bits/stdc++.h>
#include "TicTacToe.h"

using namespace std;

int main()
{
    TicTacToe game;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Press 1 for Singleplayer " << endl;
        cout << "Press 2 for Multiplayer " << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Do you want to start first (y/n)" << endl;
            char c;
            cin >> c;
            if (c == 'y')
            {
                game.singlePlayer(0);
            }
            else if (c == 'n')
            {
                game.singlePlayer(1);
            }
            else
            {
                cout << "INVALID ENTRY" << endl;
            }
        }
        else if (choice == 2)
        {

            game.multiPlayer();
        }
        else
        {
            cout << "INVALID ENTRY" << endl;
        }

        cout << "\n\n\n\t\tWant to play again? (y/n) ";
        cin >> ch;
    }

    return 0;
}
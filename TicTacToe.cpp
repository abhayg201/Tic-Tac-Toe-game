
#include <bits/stdc++.h>
#include "TicTacToe.h"
// #include "AI.h"

using namespace std;

TicTacToe::TicTacToe()
{
    for (int turn = 0; turn < 2; turn++)
    {
        player[turn] = Player();
    }
    canvas = Canvas();
}

void TicTacToe::multiPlayer()
{
    string name;
    char symbol;
    int turn;
    int row, col;
    // this for loop is for taking information about player and its symbol
    for (turn = 0; turn < 2; turn++)
    {
        cout << "\nEnter name of Player " << turn + 1 << " : ";
        getline(cin >> ws, name);
        symbol = ' ';

        while (symbol != 'x' && symbol != 'X' && symbol != 'o' && symbol != 'O')
        {
            cout << "\nChoose Symbol(X/O) for " << name << " : ";
            cin >> symbol;
            if (symbol != 'x' && symbol != 'X' && symbol != 'o' && symbol != 'O')
            {
                cout << "\n Please Enter only 'X' or 'O'";
            }
        }
        player[turn].setName(name);
        player[turn].setSymbol(symbol);
    }

    canvas.clearBoard();
    canvas.displayBoard();

    // this loop will help us play the game and make moves turn by turn

    turn = 0; // reset turn
    while (true)
    {
        do
        { // we use do-while here since we dont have the value of row and column in the beginning
            // so we want it to run at least once
            cout << "\n"
                 << player[turn].getName() << " Enter the row for move: ";
            cin >> row;
            cout << "\n"
                 << player[turn].getName() << " Enter the column for move: ";
            cin >> col;
        } while (!canvas.isValidMove(row, col));

        canvas.updateBoard(row, col, player[turn].getSymbol());
        canvas.displayBoard();

        won w = won(player[turn], &canvas);
        // check winning condition before changing turn
        if (w.hasWon(player[turn]))
        {
            cout << "\n"
                 << player[turn].getName() << " won the game !!!!! ";
            break;
        }

        turn = (turn + 1) % 2; // change turn

        // tie condition is only there if canvas is full
        if (canvas.isFull())
        {
            cout << "\nThis is a TIE!!!";
            break;
        }
    }
}

void TicTacToe ::singlePlayer(int turn)
{
    int depth = 0;
    int row, col;
    string name;
    char symbol;
    // int turn;

    cout << "\nEnter name of Player "
         << ": ";
    getline(cin >> ws, name);
    symbol = ' ';

    while (symbol != 'x' && symbol != 'X' && symbol != 'o' && symbol != 'O')
    {
        cout << "\nChoose Symbol(X/O) for " << name << " : ";
        cin >> symbol;
        if (symbol != 'x' && symbol != 'X' && symbol != 'o' && symbol != 'O')
        {
            cout << "\n Please Enter only 'X' or 'O'";
        }
    }

    

    // setting the name and symbol of the user using user inputs
    player[0].setName(name);
    player[0].setSymbol(symbol);

    // assigning name and symbol to the computer

    player[1].setName("Computer");
    if (symbol == 'x' || symbol == 'X')
    {
        player[1].setSymbol('O');
    }
    else
    {
        player[1].setSymbol('X');
    }

    canvas.clearBoard();
    canvas.displayBoard();

    while (true)
    {
        if (turn == 1) // computer's turn
        {
            // AI object used here

            int blockNumber = comp.bestMove(depth);

            row = blockNumber / 3;
            col = blockNumber % 3;
        }
        else if (turn == 0) // player's turn
        {
            do
            { // we use do-while here since we dont have the value of row and column in the beginning
                // so we want it to run at least once
                cout << "\n"
                     << player[turn].getName() << " Enter the row for move: ";
                cin >> row;
                cout << "\n"
                     << player[turn].getName() << " Enter the column for move: ";
                cin >> col;
            } while (!canvas.isValidMove(row, col));
        }

        depth++; // after each person turn we will increase the depth
        
        cout << "Board after " << player[turn].getName() << "'s turn"
             << "\n\n";

        canvas.updateBoard(row, col, player[turn].getSymbol());
        canvas.displayBoard();

        // instance of won to check win condition

        won w = won(player[turn], &canvas);
        if (w.hasWon(player[turn]))
        {
            cout << "\n"
                 << player[turn].getName() << " won the game !!!!! ";
            break;
        }

        turn = (turn + 1) % 2; // change turn

        if (canvas.isFull())
        {
            cout << "\nThis is a TIE!!!";
            break;
        }
    }
}

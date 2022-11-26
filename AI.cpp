#include <bits/stdc++.h>
#include "AI.h"
// #include "TicTacToe.h"

using namespace std;

AI::AI(Canvas *canvas, Player player[])
{
    // this->tictactoe = tictactoe;
    // cout << "check 1" << endl;

    this->canvas = canvas;
    this->player = player;
    this->w1 = new won(player[0], canvas);
    this->w2 = new won(player[1], canvas);
}


int AI ::minMax(int depth, bool isAI)
{
    if (w1->hasWon(player[0]) == true) // if player wins
    {
        return -1;
    }
    if (w2->hasWon(player[1]) == true) // if computer  wins
    {
        return 1;
    }

    int score = 0, bestScore = 0;

    if (depth < 9)
    {
        if (isAI)
        {                        // it is AI turn right now
            bestScore = INT_MIN; // since AI will try to increase its score
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (canvas->getSymbol(x, y) == ' ')
                    {
                        canvas->updateBoard(x, y, player[1].getSymbol());
                        score = minMax(depth + 1, false);
                        canvas->updateBoard(x, y, ' ');

                        if (score > bestScore)
                        {
                            bestScore = score;
                        }
                    }
                }
            }

            return bestScore;
        }
        else
        {                        // it is players's turn
            bestScore = INT_MAX; // since player will try to increase its score
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (canvas->getSymbol(x, y) == ' ')
                    {
                        canvas->updateBoard(x, y, player[0].getSymbol());
                        score = minMax(depth + 1, true);
                        canvas->updateBoard(x, y, ' ');

                        if (score < bestScore)
                        {
                            bestScore = score;
                        }
                    }
                }
            }
            return bestScore;
        }
    }
    else // if depth is more than and equal to 9 or board is full
        return 0;
}

int AI ::bestMove(int depth)
{
    int i, j;
    int score = 0;
    int bestScore = INT_MIN;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (canvas->getSymbol(x, y) == ' ')
            {
                canvas->updateBoard(x, y, player[1].getSymbol());

                score = minMax(depth + 1, false);
                canvas->updateBoard(x, y, ' ');

                if (score > bestScore)
                {

                    bestScore = score;
                    // cout << "bestScore: " << bestScore << endl;
                    i = x;
                    j = y;
                }
                
            }
        }
    }
    
    return (i * 3 + j); // we return the blocknumber cause how else
    // we can return the coordinates of row and column
}
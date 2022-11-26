#include <bits/stdc++.h>
#include "canvas.h"

Canvas::Canvas()
{

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            board[x][y] = ' ' ;
        }
    }
}

bool Canvas::isFull()
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[x][y] == ' ')
                return false;
        }
    }
    return true;
}

void Canvas::displayBoard()
{
    for (int x = 0; x < 3; x++)
    {
        cout << " | ";
        for (int y = 0; y < 3; y++)
        {
            cout << board[x][y] << " | ";
        }
        cout << "\n";
    }
}

bool Canvas::isValidMove(int row, int col)
{
    if (row < 3 && col < 3 && row >= 0 && col >= 0 && board[row][col] == ' ')
    {
        return true;
    }
    return false;
}

void Canvas::clearBoard()
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            board[x][y] = ' ';
        }
    }
}

bool Canvas::updateBoard(int row, int col, char symbol)
{

        board[row][col] = symbol;
        return true;
    
}

// 'canvas.h'

#pragma once

#include <bits/stdc++.h>
#include "player.h"

class Canvas
{
private:
    char board[3][3];

public:
    Canvas();
    bool isFull();                                   // checks if the current board is full or not
    bool isValidMove(int row, int col);              // checks if the move made by the player is valid or not
    void updateBoard();                              // updates the moves done by lpayer on the board
    void displayBoard();                             // displays the board
    void clearBoard();                               // clears the board
    bool updateBoard(int row, int col, char symbol); // updates the entered sybmol by the player on the board
    char getSymbol(int row, int col)
    {
        return board[row][col];
    }
};

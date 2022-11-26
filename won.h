
#pragma once

#include <bits/stdc++.h>
#include "canvas.h"

class won
{
private:
    Player player;
    Canvas *canvas;

public:
    won(Player player, Canvas *canvas)
    {
        // cout << "check 1" << endl;
        this->canvas = canvas;
        this->player = player;
    }

    bool hasWon(Player p)
    { // checks if the player p has won or not
        char c1, c2, c3;

        for (int i = 0; i < 3; i++)
        {
            c1 = canvas->getSymbol(i, 0);
            c2 = canvas->getSymbol(i, 1);
            c3 = canvas->getSymbol(i, 2);

            if (c1 == p.getSymbol() && c2 == p.getSymbol() && c3 == p.getSymbol())
                return true;
            // if a player has his symbol in all 3 column in a row then he wins

            c1 = canvas->getSymbol(0, i);
            c2 = canvas->getSymbol(1, i);
            c3 = canvas->getSymbol(2, i);

            if (c1 == p.getSymbol() && c2 == p.getSymbol() && c3 == p.getSymbol())
                return true;
            // if a player has his symbol in all 3 row in a column then he wins
        }

        bool flag = true;

        for (int i = 0; i < 3; i++) // if a player has his symbol in a diagonal
        {
            if (p.getSymbol() != canvas->getSymbol(i, i))
            {
                flag = false;
                break;
            }
        }
        if(flag) return true;
        for (int i = 0; i < 3; i++)
        {
            if (p.getSymbol() != canvas->getSymbol(i, 2 - i))
            {
                flag = false;
                break;
            }
        }

        return flag;        
    }
};
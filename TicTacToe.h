// TicTacToe.h
#pragma once

#include <bits/stdc++.h>

#include "AI.h"


// class AI;
class TicTacToe 
{
private:
    Player player[2];
    Canvas canvas;
    
    AI comp = AI(&(this->canvas),this->player);   //calling instance of AI class using user defined constructor

public:
    TicTacToe();
    void multiPlayer();  //for player vs player 
    void singlePlayer(int turn);  //for player vs computer (AI)
};


#pragma once

#include <bits/stdc++.h>
#include "canvas.h"
#include "won.h"
// class TicTacToe;

class AI
{
private:
    Canvas *canvas;
    Player *player;
    won * w2;
    won * w1;

public:
    AI(Canvas *canvas, Player player[]);
    int minMax(int depth, bool isAI);
    int bestMove(int depth);
};

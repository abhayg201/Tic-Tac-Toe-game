// player.h

#pragma once

#include <bits/stdc++.h>

using namespace std;

class Player
{
private:
    string name;
    char symbol;

public:
    Player()
    {
        name = "";
        symbol = ' ';
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    void setSymbol(char symbol)
    {
        this->symbol = symbol;
    }
    char getSymbol()
    {
        return this->symbol;
    }
};


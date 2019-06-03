// Shamsadean Mirghani
//
// Project 1
//
#ifndef GOLDMINE2
#define GOLDMINE2

#include<iostream>
#include<string>
#include "twoDim.h"
using namespace std;

class Goldmine {
    public:

    Goldmine();
    void resetGame();
    void randomRowColumn(int &row, int &column);
    string rainbowMessage();
    void revealSelection(int row, int column);
    void printGoldMine();
    int getGold();

    private:
        twoDim<bool> visited;
        twoDim<char> boxType;
        twoDim<int> goldAmount;
        int gold;
};

#endif

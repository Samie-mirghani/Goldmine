// Shamsadean Mirghani
//
// Project 1
//
#ifndef DIM1
#define DIM1

#include<iostream>
#include<string>
using namespace std;
template<class LE> 
class twoDim { 
    public:
        twoDim();
        LE getElement(int row, int col) const;
        void setElement(int row, int col, LE element);
    private:
        LE array[6][6];     

};
#include "twoDim.cpp"
#endif

// Shamsadean Mirghani
//
// Project 1
//
#ifndef TWODIM1
#define TWODIM1

#include<iostream>
#include<string>
#include "twoDim.h"

using namespace std;
    template<class LE>
// Default constructor, is not used
    twoDim<LE>::twoDim() { 

    }
// A template return type. Returns an LE element. Gets element in the array 
// @return LE
    template<class LE>
    LE twoDim<LE>::getElement(int row, int col) const {   
        return array[row][col];
    }
// No return type. Mutator to change an element
// @return void
    template<class LE>
    void twoDim<LE>::setElement(int row, int col, LE element) {
       array[row][col] = element;
    }
    

#endif
    

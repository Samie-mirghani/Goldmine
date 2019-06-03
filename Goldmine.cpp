// Shamsadean Mirghani
//
// Project 1
//

#ifndef GOLDY
#define GOLDY

#include<iostream>
#include<string>
#include<cstdlib>
#include "Goldmine.h"

using namespace std;

//Default constructor 
    Goldmine::Goldmine(){
    }

// No return type. Will loop through all 2D arrays and will reset them to
// defualt values. Sets the random gold value. Calls the method
// randomRowColumn() that will randomize the row and column numbers amd sets the
// corresponding values in the array.
// @return void
    void Goldmine::resetGame() {
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                visited.setElement(i,j,false);
                boxType.setElement(i,j,'q');
                goldAmount.setElement(i,j, rand() % 90 + 10);
            }
        }
        gold = rand() % 8000 + 1000;
        
        int Rrow;
        int Rcol;

        randomRowColumn(Rrow, Rcol);
        boxType.setElement(Rrow, Rcol, 'G');
        //Cheat for gold
        cout << "location of gold: " << Rrow + 1 << " " << Rcol + 1 << endl;

        randomRowColumn(Rrow, Rcol);
        boxType.setElement(Rrow, Rcol, 'R');
        //Cheat for rainbow
        cout << "location of rainbow: " << Rrow + 1 << " " << Rcol + 1 << endl;

        randomRowColumn(Rrow, Rcol);
        boxType.setElement(Rrow, Rcol, 'C');
        //cheat for coal
        cout << "location of coal: " << Rrow + 1 << " " << Rcol + 1 << endl;
    }
// No return type. Will generate a number of 1-6
// @return void
    void Goldmine::randomRowColumn(int &row, int &column) {
        row = rand() % 5 + 1;
        column = rand() % 5 + 1;

    }
// string return type. This method will find the gold and then determine the
// general location that the user should look in (upper left, upper right, lower
// left, lower right).
// @return string
    string Goldmine::rainbowMessage() {
        for(int k = 0; k < 6; k++) {
            for(int y = 0; y < 6; y++) {
                if(boxType.getElement(k, y) == 'G' && k <= 3 && k >= 1 && y >=
                1 && y <= 3) {
                    return "Look in the upper left";
                }
                if(boxType.getElement(k, y) == 'G' && k <= 3 && k >= 1 && y <= 6
                && y >=4 ) {
                    return "look in the upper right";
                }
                
                if(boxType.getElement(k,y) == 'G' && k >= 4 && k <= 6 && y <= 3
                && y >= 1) {
                    return "look in the lower left";
                }

                if(boxType.getElement(k,y) == 'G' && k >= 4 && k <= 6 && y >= 4
                && y <= 6) {
                    return "look in the lower right";
                }
           }
        }   
    }
// No return type. This method will check the selections from the user and see
// if they found either the gold, coal, rainbow, or nothing (and lost money). It
// will then print out the results to the user
// @return void
    void Goldmine::revealSelection(int row, int column) {
            if(visited.getElement(row, column) == false &&
            boxType.getElement(row, column) == 'G') {
                char ans;
                visited.setElement(row, column, true);
                cout << "Your gold: " << gold << endl;
                cout << "You found the pot of GOLD!" << endl;
                gold = 1000000;
                cout << "Your gold: " << gold << endl;
                printGoldMine();
                cout << "YOU WIN!!!" << endl;
            }
            else if(visited.getElement(row, column) == false &&
            boxType.getElement(row, column) == 'R') {
                cout << rainbowMessage() << endl;
                visited.setElement(row, column, true);
            }

            else if(visited.getElement(row,column) == false &&
            boxType.getElement(row,column) == 'C') {

                char y;
                cout << "You found the coal. You lose the game!!" << endl;
                visited.setElement(row, column, true);
                printGoldMine();
                gold = 0;
            }

            else if(visited.getElement(row, column) == false &&
            boxType.getElement(row, column) == 'q') {
                cout << "You didn't find anything, but while you were looking,";
                cout << " you lost some gold!!" << endl;

                cout << "Gold Lost: " << goldAmount.getElement(row, column);
                cout << endl;
                int left = gold - goldAmount.getElement(row, column);
                cout << "Gold Left: " << left << endl;
                gold = left;
                visited.setElement(row, column, true);
                printGoldMine();
            }
            
    }
    
// No return type. This method will loop through the 2D arrays and will print
// out the game board. It will check and see if the user has visited the spot on
// the board.
// @return void
    void Goldmine::printGoldMine() {
        cout << "   1   2   3   4   5   6";
        cout << endl;
        for(int i = 0; i < 6; i++) {
            cout << i + 1 << "  ";
            for (int j = 0; j < 6; j++) {
        
                if(visited.getElement(i,j) == true && boxType.getElement(i,j)
                =='q') {
                    cout << '-'; 
                }
                else if(visited.getElement(i,j) ==  true &&
                boxType.getElement(i,j) == 'R') {
                    cout << "R";
                }
                else if(visited.getElement(i,j) == true &&
                boxType.getElement(i,j) == 'G') {
                cout << "G";
                }
                else if(visited.getElement(i,j) == true &&
                boxType.getElement(i,j) == 'C') {
                cout << "C";
                }
                else{
                cout << "*";
                }

                if(i != 6) {
                    cout << "   ";
                }

        }
        cout << endl;
    }
    }
// Integer return type. Accessor that allows other files to access the gold
// variable
// @return int
    int Goldmine::getGold() {

        return gold;
    }

    

#endif    

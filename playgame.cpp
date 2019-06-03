// Shamsadean Mirghani
//
// Project 1
//
//
#include<iostream>
#include<string>
#include<cstdlib>
#include "Goldmine.h"
#include "twoDim.h"
using namespace std;

    void printMenu(Goldmine &c);

// Main method that creates a new instance of goldmine and continues to run the
// game until the user loses. Returns int 0.
// @return int
    int main() {
        Goldmine gold;
        char ans = 'y';
        int count = 0;
        do {
            count++;
            gold.resetGame();
            
            if(count != 1){
                cout << "Do you want to play again(y/n)?" << endl;
                cin >> ans;
                if(ans == 'n'){
                    break;
                }
            }    

            if(ans != 'n' && ans != 'y') {
                cout << "Please enter a correct choice" << endl;
             }else{    
                do{
        
                    printMenu(gold);

                }while(gold.getGold() != 0 && gold.getGold() != 1000000);
            }
            ans= 'v';
        }while(ans != 'y');

        return 0;
}




// Prints the user selection statements. Also calls printGoldMine() to print the
// game board. It will continue to ask the user for input until they enter in
// a correct value. Once a valid input is entered then revealSelection() is
// called to reveal their selection on the board. No return type.
// @return void
    void printMenu(Goldmine &c) {
        int row;
        int col;

        do{
            cout << "Your gold: " << c.getGold() << endl;
            c.printGoldMine();
            cout << "Please enter the row you want to search (1-6) :" << endl;
            cin >> row;
         
            cout << "Please enter the column you want to search(1-6) :" << endl;
            cin >> col;
        
            if(c.getGold() <= 0) {
                break;
            }

            if(row <  6 || row > 0) {
                break;
            }

            if(col < 6 || col > 0) {
                break;
            }

       } while(true);
    
        row--;
        col--;
        c.revealSelection(row, col);
}





// Class definition for X_O_Board class
// Author:  Ebrahim Mohsen Ebrahim
// Date:    12/12/2022
// Version: 1

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

Triangle_X_O::Triangle_X_O() {
    n_rows=3;
    n_cols=5;
    board = new char*[n_rows];
    
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
        }
        board[0][0]='$';board[0][1]='$';board[0][3]='$';board[0][4]='$';board[1][0]='$';board[1][4]='$';
    }

bool Triangle_X_O::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void Triangle_X_O::display_board() {
for (int i: {0,1,2}) {
    cout << "\n| ";
    for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
        cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool Triangle_X_O::is_winner() {
    //brute force goes BRRRRR
    if((board[0][2]==board[1][2])&&(board[0][2]==board[2][2]) && board[0][2]!=0) return true;
else if((board[0][2]==board[1][1])&&(board[0][2]==board[2][0]) && board[0][2]!=0) return true;
else if((board[0][2]==board[1][3])&&(board[0][2]==board[2][4]) && board[0][2]!=0) return true;
else if((board[1][1]==board[1][2])&&(board[1][1]==board[1][3]) && board[1][1]!=0) return true;
else if((board[2][0]==board[2][1])&&(board[2][0]==board[2][2]) && board[2][2]!=0) return true;
else if((board[2][1]==board[2][2])&&(board[2][1]==board[2][3]) && board[2][2]!=0) return true;
else if((board[2][2]==board[2][3])&&(board[2][2]==board[2][4]) && board[2][2]!=0) return true;
else return false;
}


bool Triangle_X_O::is_draw() {
    return (n_moves == 9 && !is_winner());
}


bool Triangle_X_O::game_is_over () {
    return n_moves >= 9;
}

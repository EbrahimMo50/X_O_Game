// Class definition for X_O_Board class
// Author:  Mazen Mohamed Nayef
// Date:    12/12/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

int PTS_X = 0;
int PTS_O = 0;



X_O_Board_5::X_O_Board_5 () {
    n_rows = n_cols = 5;
    board5 = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board5 [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board5[i][j] = 0;
    }
}


bool X_O_Board_5::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board5[x][y] == 0)) {
        board5[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void X_O_Board_5::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board5 [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}


int X_O_Board_5::is_winner() {


//    char row_win[3], col_win[3], diag_win[2];
//    for (int i:{0,1,2}) {
//        row_win[i] = board5[i][0] & board5[i][1] & board5[i][2];
//        col_win[i] = board5[0][i] & board5[1][i] & board5[2][i];
//    }

    // FOR ROW WINS
if (n_moves == 25){

    for (int i:{0,1,2}){
        if (board5[0][i] == 'X' && board5[0][i+1] == 'X' && board5[0][i+2] == 'X'){
            PTS_X++;
        }
        else if (board5[0][i] == 'O' && board5[0][i+1] == 'O' && board5[0][i+2] == 'O'){
            PTS_O++;
        }
    }

    for (int i:{0,1,2}){
        if (board5[1][i] == 'X' && board5[1][i+1] == 'X' && board5[1][i+2] == 'X') {
            PTS_X++;
        }
        else if (board5[1][i] == 'O' && board5[1][i+1] == 'O' && board5[1][i+2] == 'O') {
            PTS_O++;
        }
    }

    for (int i:{0,1,2}){
        if (board5[2][i] == 'X' && board5[2][i+1] == 'X' && board5[2][i+2] == 'X') {
            PTS_X++;
        }
        else if (board5[2][i] == 'O' && board5[2][i+1] == 'O' && board5[2][i+2] == 'O') {
            PTS_O++;
        }
    }

    for (int i:{0,1,2}){
        if (board5[3][i] == 'X' && board5[3][i+1] == 'X' && board5[3][i+2] == 'X') {
            PTS_X++;
        }
        else if (board5[3][i] == 'O' && board5[3][i+1] == 'O' && board5[3][i+2] == 'O') {
            PTS_O++;
        }
    }

    for (int i:{0,1,2}){
        if (board5[4][i] == 'X' && board5[4][i+1] == 'X' && board5[4][i+2] == 'X') {
            PTS_X++;
        }
        else if (board5[4][i] == 'O' && board5[4][i+1] == 'O' && board5[4][i+2] == 'O') {
            PTS_O++;
        }
    }


    // FOR COL WINS
    for (int i:{0,1,2}){
        if (board5[i][0] == 'X' && board5[i+1][0] == 'X' && board5[i+2][0] == 'X'){
            PTS_X++;
        }
        else if (board5[i][0] == 'O' && board5[i+1][0] == 'O' && board5[i+2][0] == 'O'){
            PTS_O++;
        }
    }

    for (int i:{0,1,2}){
        if (board5[i][1] == 'X' && board5[i+1][1] == 'X' && board5[i+2][1] == 'X'){
            PTS_X++;
        }
        else if (board5[i][1] == 'O' && board5[i+1][1] == 'O' && board5[i+2][1] == 'O'){
            PTS_O++;
        }
    }

    for (int i:{0,1,2}){
        if (board5[i][2] == 'X' && board5[i+1][2] == 'X' && board5[i+2][2] == 'X'){
            PTS_X++;
        }
        else if (board5[i][2] == 'O' && board5[i+1][2] == 'O' && board5[i+2][2] == 'O'){
            PTS_O++;
        }
    }

    for (int i:{0,1,2}){
        if (board5[i][3] == 'X' && board5[i+1][3] == 'X' && board5[i+2][3] == 'X'){
            PTS_X++;
        }
        else if (board5[i][3] == 'O' && board5[i+1][3] == 'O' && board5[i+2][3] == 'O'){
            PTS_O++;
        }
    }

    for (int i:{0,1,2}){
        if (board5[i][4] == 'X' && board5[i+1][4] == 'X' && board5[i+2][4] == 'X'){
            PTS_X++;
        }
        else if (board5[i][4] == 'O' && board5[i+1][4] == 'O' && board5[i+2][4] == 'O'){
            PTS_O++;
        }
    }



    // DIAG FIRST 9 FROM RIGHT SIDE
    if (board5[0][2] == 'X' && board5[1][3] == 'X' && board5[2][4] == 'X'){
        PTS_X++;
    }
    else if (board5[0][2] == 'O' && board5[1][3] == 'O' && board5[2][4] == 'O') {
        PTS_O++;
    }

    if (board5[0][1] == 'X' && board5[1][2] == 'X' && board5[2][3] == 'X'){
        PTS_X++;
    }
    else if (board5[0][1] == 'O' && board5[1][2] == 'O' && board5[2][3] == 'O') {
        PTS_O++;
    }

    if (board5[1][2] == 'X' && board5[2][3] == 'X' && board5[3][4] == 'X'){
        PTS_X++;
    }
    else if (board5[1][2] == 'O' && board5[2][3] == 'O' && board5[3][4] == 'O') {
        PTS_O++;
    }

    if (board5[0][2] == 'X' && board5[1][3] == 'X' && board5[2][4] == 'X'){
        PTS_X++;
    }
    else if (board5[0][2] == 'O' && board5[1][3] == 'O' && board5[2][4] == 'O') {
        PTS_O++;
    }

    if (board5[0][0] == 'X' && board5[1][1] == 'X' && board5[2][2] == 'X'){
        PTS_X++;
    }
    else if (board5[0][0] == 'O' && board5[1][1] == 'O' && board5[2][2] == 'O') {
        PTS_O++;
    }

    if (board5[1][1] == 'X' && board5[2][2] == 'X' && board5[3][3] == 'X'){
        PTS_X++;
    }
    else if (board5[1][1] == 'O' && board5[2][2] == 'O' && board5[3][3] == 'O') {
        PTS_O++;
    }

    if (board5[2][2] == 'X' && board5[3][3] == 'X' && board5[4][4] == 'X'){
        PTS_X++;
    }
    else if (board5[2][2] == 'O' && board5[3][3] == 'O' && board5[4][4] == 'O') {
        PTS_O++;
    }

    if (board5[1][0] == 'X' && board5[2][1] == 'X' && board5[3][2] == 'X'){
        PTS_X++;
    }
    else if (board5[1][0] == 'O' && board5[2][1] == 'O' && board5[3][2] == 'O') {
        PTS_O++;
    }

    if (board5[2][1] == 'X' && board5[3][2] == 'X' && board5[4][3] == 'X'){
        PTS_X++;
    }
    else if (board5[2][1] == 'O' && board5[3][2] == 'O' && board5[4][3] == 'O') {
        PTS_O++;
    }

    if (board5[2][0] == 'X' && board5[3][1] == 'X' && board5[4][2] == 'X'){
        PTS_X++;
    }
    else if (board5[2][0] == 'O' && board5[3][1] == 'O' && board5[4][2] == 'O') {
        PTS_O++;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    // DIAG SECOND 9 FROM LEFT SIDE
    if (board5[0][2] == 'X' && board5[1][1] == 'X' && board5[2][0] == 'X'){
        PTS_X++;
    }
    else if (board5[0][2] == 'O' && board5[1][1] == 'O' && board5[2][0] == 'O') {
        PTS_O++;
    }

    if (board5[0][3] == 'X' && board5[1][2] == 'X' && board5[2][1] == 'X'){
        PTS_X++;
    }
    else if (board5[0][3] == 'O' && board5[1][2] == 'O' && board5[2][1] == 'O') {
        PTS_O++;
    }

    if (board5[1][2] == 'X' && board5[2][1] == 'X' && board5[3][0] == 'X'){
        PTS_X++;
    }
    else if (board5[1][2] == 'O' && board5[2][1] == 'O' && board5[3][0] == 'O') {
        PTS_O++;
    }

    if (board5[0][4] == 'X' && board5[1][3] == 'X' && board5[2][2] == 'X'){
        PTS_X++;
    }
    else if (board5[0][4] == 'O' && board5[1][3] == 'O' && board5[2][2] == 'O') {
        PTS_O++;
    }

    if (board5[1][3] == 'X' && board5[2][2] == 'X' && board5[3][1] == 'X'){
        PTS_X++;
    }
    else if (board5[1][3] == 'O' && board5[2][2] == 'O' && board5[3][1] == 'O') {
        PTS_O++;
    }

    if (board5[2][2] == 'X' && board5[3][1] == 'X' && board5[4][0] == 'X'){
        PTS_X++;
    }
    else if (board5[2][2] == 'O' && board5[3][1] == 'O' && board5[4][0] == 'O') {
        PTS_O++;
    }

    if (board5[1][4] == 'X' && board5[2][3] == 'X' && board5[3][2] == 'X'){
        PTS_X++;
    }
    else if (board5[1][4] == 'O' && board5[2][3] == 'O' && board5[3][2] == 'O') {
        PTS_O++;
    }

    if (board5[2][3] == 'X' && board5[3][2] == 'X' && board5[4][1] == 'X'){
        PTS_X++;
    }
    else if (board5[2][3] == 'O' && board5[3][2] == 'O' && board5[4][1] == 'O') {
        PTS_O++;
    }

    if (board5[2][4] == 'X' && board5[3][3] == 'X' && board5[4][2] == 'X'){
        PTS_X++;
    }
    else if (board5[2][4] == 'O' && board5[3][3] == 'O' && board5[4][2] == 'O') {
        PTS_O++;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////

}


    if (n_moves == 25){
        if (PTS_X > PTS_O) {
            return 1;
        }
        else if (PTS_O > PTS_X) {
            return 2;
        }
    }
    else {
        //cout << PTS_X << " " << PTS_O << endl;
        return 0;
    }
}


bool X_O_Board_5::is_draw() {
    return (n_moves == 25 && !is_winner());
}

bool X_O_Board_5::game_is_over () {
    return n_moves >= 25;
}
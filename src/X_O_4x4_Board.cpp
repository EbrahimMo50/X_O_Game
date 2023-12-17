#include"../include/BoardGame_Classes.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

X_O_4x4_Board ::X_O_4x4_Board() {
        n_rows = 7 , n_cols = 6;
        board = new char*[n_rows];
        for (int i = 0; i < n_rows; i++) {
            board [i] = new char[n_cols];
            for (int j = 0; j < n_cols; j++)
                board[i][j] = 0;
        }
    for (int i = 0; i < n_cols ; ++i) {
        possible_move[n_rows-1][i] = true;
    }
}

bool X_O_4x4_Board::update_board(int x, int y, char symbol) {
    if (!(x < 0 || x > n_rows || y < 0 || y > n_cols) && (board[x][y] == 0)) { // checks if the move is valid
        for (int i = x; i <n_rows ; ++i) {
            if (possible_move[i][y]){ // that lets the move slide to available lowest square
            board[i][y] = toupper(symbol);
            n_moves++;
            possible_move[i][y] = false; // square is not available after inputting the move
            if (i>0) {
                possible_move[i - 1][y] = true;
            }
            return true;
            }

        }
    }
    else
        return false;

}

void X_O_4x4_Board ::display_board()  {
    for (int i = 0 ; i < n_rows ; i++) {
        cout << "\n| ";
        for (int j = 0 ; j < n_cols ; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n------------------------------------------------";
    }
    cout << endl;
}

bool X_O_4x4_Board::is_winner() {
    // checking horizontally
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols - 3; ++j) {
            if (board[i][j] & board[i][j+1]&board[i][j+2]&board[i][j+3]&(board[i][j] == 'X' || board[i][j] == 'O')){
                return true;
            }
        }
    }
    // checking vertically
        for (int j = 0; j < n_cols; ++j) {
            for (int i = 0; i < n_rows - 3; ++i) {
            if (board[i][j] & board[i+1][j] & board[i+2][j] & board[i+3][j] && (board[i][j] == 'X' || board[i][j] == 'O')){
                return true;
            }
        }
    }
    // checking horizontally
        return check_diagonal() || check_other_diagonal();
    }


bool X_O_4x4_Board::is_draw() {
    return (n_moves == 42 && !is_winner());

}

bool X_O_4x4_Board::game_is_over() {
    return (n_moves >= 42);
}

bool X_O_4x4_Board::check_other_diagonal() { // checking upper edge then right side edge for the anti diagonals
    for (int i = n_cols - 1; i >= 3; --i) {
        int edge = 0;
        for (int j = i; j >= 3 ; --j , ++edge) {
            if (board[edge][j] & board[edge + 1][j - 1] & board[edge + 2][j - 2] & board[edge + 3][j - 3] && (board[edge][j] == 'X' || board[edge][j] == 'O')){
                return true;
            }
        }
    }
    for (int i = 0; i <= 3 ; ++i) {
        int edge = 5;
        for (int j = i ; j <= 3 && edge >= 3 ; ++j , --edge) {
            if (board[edge][j] & board[edge - 1][j + 1] & board[edge - 2][j + 2] & board[edge - 3][j - 3] && (board[j][edge] == 'X' || board[j][edge] == 'O')){
                return true;
            }

        }
        
    }
    return false;
}

bool X_O_4x4_Board::check_diagonal() { // checking upper edge then left side edge for the main diagonals
    for (int i = 0; i <= 3; ++i) {
        int edge = 0;
        for (int j = i; j <= 3; ++j , ++edge) {
            if (board[edge][j] & board[edge + 1][j + 1] & board[edge + 2][j + 2] & board[edge + 3][j + 3] && j < 3 && (board[edge][j] == 'X' || board[edge][j] == 'O')) {
                return true;
            }
            if (board[j][edge] & board[j + 1][edge + 1] & board[j + 2][edge + 2] & board[j + 3][edge + 3] && edge < 3 && (board[j][edge] == 'X' || board[j][edge] == 'O')) {
                return true;
            }

        }

    }
    return false;
}



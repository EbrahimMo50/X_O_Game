// Class definition for XO_GameManager class
// Author:  Mazen Mohamed Nayef
// Date:    12/13/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

GameManager_5::GameManager_5(board_5* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager_5::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                if (boardPtr->is_winner() == 1) {
                    //cout << boardPtr->is_winner() << endl;
                    cout  << players[0]->to_string() << " wins\n";
                    return;
                }
                else {
                    //cout << boardPtr->is_winner() << endl;
                    cout  << players[1]->to_string() << " wins\n";
                    return;
                }
            }
            if (boardPtr->is_draw()){
                //cout << boardPtr->is_winner() << endl;
                cout << "Draw!\n";
                return;
            }
        }
    }
}

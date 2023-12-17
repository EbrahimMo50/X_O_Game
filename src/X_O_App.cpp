#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout<<"press 1 for normal XO \npress 2 for trinagle XO\npress 3 for 4*4 X_O_\npress 4 for 5X5 X_O_   : ";
    int game_choice;
    cin>>game_choice;
    if(game_choice==1){
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
        {players[1] = new Player (2, 'o');}
        else{
            players[1] = new RandomPlayer ('o', 3);
        }
        GameManager x_o_game (new X_O_Board, players);
        x_o_game.run();
    }
    if(game_choice==2){
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else{
            players[1] = new RandomPlayer ('o', 5);
        }
        GameManager triangle(new Triangle_X_O, players);
        triangle.run();
    }
    if (game_choice==3) {
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new X_O_4x4_Player (2 , 'o');
        else{
            players[1] = new X_O_4x4_Random_Player ('o', 7 , 6);
        }
        GameManager x_o_game(new X_O_4x4_Board, players);
        x_o_game.run();
    }
    if(game_choice==4) {
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            players[1] = new RandomPlayer('o', 5);

        GameManager_5 x_o_game(new X_O_Board_5(), players);
        x_o_game.run();
    }
    system ("pause");
}

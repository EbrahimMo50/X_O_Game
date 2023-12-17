#include"../include/BoardGame_Classes.hpp"
#include <iostream>

void X_O_4x4_Player::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x and y (0 to (6 for X , 5 for Y) separated by spaces: ";
    cin >> x >> y;
}

X_O_4x4_Player::X_O_4x4_Player(int order, char symbol) : Player(order, symbol) {}

X_O_4x4_Random_Player::X_O_4x4_Random_Player(char symbol , int dimensionX , int dimensionY) : Player(symbol) {
    this->dimensionX = dimensionX;
    this->dimensionY = dimensionY;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}
void X_O_4x4_Random_Player::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimensionX);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimensionY);
}


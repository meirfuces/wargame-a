//
// Created by meir fuchs on 23/05/2020.
//
#include "Sniper.hpp"
void WarGame::Sniper::attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)

{
Soldier *enemy_to_attack = find_soldier_attack(board, source);
cout << "The life of enemy is " <<enemy_to_attack->hp<< endl;
if (enemy_to_attack != nullptr) {
enemy_to_attack->hp -= 50;

if (enemy_to_attack->hp <= 0) {
//delete enemy_to_attack;
//need to Add destractor
delete enemy_to_attack;
cout << "Sniper Attack and kill" << endl;// dead
}
else {
    cout << "Sniper Attack The life of enemy is " << enemy_to_attack->hp << endl; // alive
}
}
else {
    cout << "No Attack" << endl; // alive
}
}


//
WarGame::Soldier* WarGame::Sniper:: find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){

Soldier *ans;
int index_i, index_j;
std::pair<int, int> myLocation = {source.first, source.second};
double maxnHealth = 0;
int HelthTemp;
for (int i = 0; i < board.size(); ++i) {
for (int j = 0; j < board.size(); ++j) {
if (board[i][j] != nullptr && board[i][j]->player != this->player) {
HelthTemp = board[i][j]->hp;
if (maxnHealth < HelthTemp) {
ans = board[i][j];
maxnHealth = HelthTemp;
index_i = i;
index_j = j;
}
}
}
}
if (ans != nullptr){
cout << "Location enemy sniper is " <<index_i<<" "<<index_i<< endl;
return ans;
}
return nullptr;
}
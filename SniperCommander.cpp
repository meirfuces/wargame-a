
#include "SniperCommander.hpp"
#include "Sniper.hpp"

void WarGame::SniperCommander::attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) {

for (int i = 0; i < board.size(); ++i)
{
for (int j = 0; j < board.size(); ++j)
{
if (board[i][j] != nullptr && board[i][j]->player == this->player)
{
if (typeid(board[i][j]) == typeid(Sniper))
{

Soldier* temp= board[i][j];
temp->attack(board,{i,j});
}
}
}
}


Soldier *enemy_to_attack = find_soldier_attack(board, source);
cout << "The life of enemy is " <<enemy_to_attack->hp<< endl;
if (enemy_to_attack != nullptr) {
enemy_to_attack->hp -= 100;

if (enemy_to_attack->hp <= 0) {
//delete enemy_to_attack;
//need to Add destractor
cout << "Delete Enemy " <<enemy_to_attack->hp<< endl;
//delete enemy_to_attack;


cout << "FootCommander Attack and kill" << endl;// dead
}
else
cout << "FootCommander Attack The life of enemy is "<<enemy_to_attack->hp<< endl; // alive
}


cout << "No Attack" << endl; // alive
}


WarGame::Soldier* WarGame::SniperCommander:: find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){
    Soldier* ans;
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
                }
            }
        }
    }
    if (ans!=nullptr)
        return ans;
    return nullptr;
}
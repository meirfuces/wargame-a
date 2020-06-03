//
// Created by meir on 6/2/20.
//

#include "FootCommander.hpp"
#include "FootSoldier.hpp"


double dist(std::pair<int, int> from, std::pair<int, int> to);
void WarGame::FootCommander::attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] != nullptr && board[i][j]->player == this->player) {
               //type id check if the same object https://www.geeksforgeeks.org/typeid-operator-in-c-with-examples/
                if (typeid(board[i][j]) == typeid(FootSoldier)) {
                    Soldier *temp = board[i][j];
                    temp->attack(board, {i, j});
                }
            }
        }
    }
    Soldier *enemy_to_attack = find_soldier_attack(board, source);
    cout << "The life of enemy is " <<enemy_to_attack->hp<< endl;
    if (enemy_to_attack != nullptr) {
        enemy_to_attack->hp -= 20; //damage is 20 FootCommander

        if (enemy_to_attack->hp <= 0) {
            //delete enemy_to_attack;

            delete enemy_to_attack;
            if (enemy_to_attack!=nullptr)
                enemy_to_attack=nullptr;
            cout << "FootCommander Attack and kill" << endl;// dead
        }
        else
            cout << "FootCommander Attack The life of enemy is " <<enemy_to_attack->hp<< endl; // alive
    }
    else
    cout << "No Attack" << endl;
}

    WarGame::Soldier* WarGame::FootCommander:: find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){
        Soldier* ans;
        int index_i, index_j;
        std::pair<int, int> myLocation = {source.first, source.second};
        double min_dis = std::numeric_limits<double>::max();
        double _distance;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->player != this->player) {
                    _distance = dist(myLocation, {i,j});
                    if (_distance < min_dis) {
                        ans = board[i][j];
                        index_i = i;
                         index_j = j;
                        min_dis = _distance;
                    }
                }
            }
        }
        if (ans!=nullptr) {
            cout<<"location Enemy"<<index_i<<" "<<index_j<<endl;
            return ans;
        }
        return nullptr;
    }
//dist d=(x2−x1)2+(y2−y1)2
    double dist(std::pair<int, int> from, std::pair<int, int> to)
    {
        double calc =pow(from.first-to.first,2) + pow(from.second - to.second,2);
        return sqrt(calc);

    }
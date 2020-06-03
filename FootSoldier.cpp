#include "FootSoldier.hpp"
#include "Board.hpp"

void WarGame::FootSoldier::attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) {


    std::pair<int, int> LocationEnemy = find_soldier_attack(board, source);

    Soldier *enemy_to_attack = board [LocationEnemy.first][LocationEnemy.second];
    if (enemy_to_attack == nullptr)
        return;
    cout << "pos is " <<LocationEnemy.first<<","<<LocationEnemy.second<< endl;
    cout << "The life of enemy is " <<enemy_to_attack->hp<< endl;
    if (enemy_to_attack != nullptr) {
        enemy_to_attack->hp -= DAMAGE;

        if (enemy_to_attack->hp <= 0) {
            //delete enemy_to_attack;
            cout<<"try delete meir"<<endl;
            board [LocationEnemy.first][LocationEnemy.second]=nullptr;
            enemy_to_attack=nullptr;
            delete enemy_to_attack;
            if (enemy_to_attack!=nullptr)
               cout<<"try delete"<<endl;
            cout << "FootSoldier Attack and kill" << endl;// dead
        }
        else
            cout << "FootSoldier Attack The life of enemy is " <<enemy_to_attack->hp<< endl; // alive
    }
    else
    cout << "No Attack" << endl; // alive
}
std::pair<int, int>  WarGame::FootSoldier:: find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){
    Soldier* ans;
    std::pair<int, int> myLocation = {source.first, source.second};
    std::pair<int, int> LocationEnemy = {-1,0};
    double min_dis = std::numeric_limits<double>::max();
    double _distance;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] != nullptr && board[i][j]->player != this->player) {
                _distance = dist(myLocation, {i,j});
                if (_distance < min_dis) {
                    ans = board[i][j];
                    min_dis = _distance;
                    LocationEnemy = {i,j};
                }
            }
        }
    }
    if (ans!=nullptr)
        return LocationEnemy;
    return LocationEnemy;
}


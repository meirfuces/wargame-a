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
                if (typeid(board[i][j]) == typeid(FootSoldier)) {
                    Soldier *temp = board[i][j];
                    temp->attack(board, {i, j});
                }
            }
        }
    }
}
    WarGame::Soldier* WarGame::FootCommander:: find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){
        Soldier* ans;
        std::pair<int, int> myLocation = {source.first, source.second};
        double min_dis = std::numeric_limits<double>::max();
        double _distance;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->player != this->player) {
                    _distance = dist(myLocation, {i,j});
                    if (_distance < min_dis) {
                        ans = board[i][j];
                        min_dis = _distance;
                    }
                }
            }
        }
        if (ans!=nullptr)
            return ans;
        return nullptr;
    }
//dist
    double dist(std::pair<int, int> from, std::pair<int, int> to)
    {
        return sqrt(pow(from.first-to.first,2) + pow(from.second - to.second,2));
    }
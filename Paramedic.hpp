#pragma once
#include "Soldier.hpp"
# define HEALTH 50
namespace WarGame {

    class Paramedic : public Soldier {
    public:
        Paramedic(int pn) : Soldier(100, pn, 50) {}
        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override {


            for (int i = source.first - 1; i <= source.second + 1; i++) {
                for (int j = source.second - 1; j <= source.second + 1; j++) {
                    if (i!=source.first || j!=source.first){
                    Soldier *soldier_to_health = find_soldier_attack(board, {i, j});
                    if (soldier_to_health != nullptr) {
                       // soldier_to_health->hp += HEALTH;
                        soldier_to_health->fillLife();
                       cout << "The life of Soldier after helth is " << soldier_to_health->hp << endl;
                    }
                        }
                }
            }
        }
            Soldier* find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){
                Soldier* ans;
                if (source.first>=0 && source.first < board.size() && source.second >= 0 && source.second < board[0].size())
                {
                    ans = board[source.first][source.second];
                    if (ans!=nullptr && ans->player==this->player)
                        return ans;
                }
                return nullptr;
            }
        void fillLife() override{
            this->hp = 100;
        }
    };
}
#pragma once
#include "Soldier.hpp"

#define DAMAGE 10
namespace WarGame{
    class FootSoldier : public Soldier
            {
    public:
        FootSoldier(int pn):Soldier(100,pn){}

        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override;
        //{
//            Soldier *enemy_to_attack = find_soldier_attack(board, source);
//            cout << "The life of enemy is " <<enemy_to_attack->hp<< endl;
//            if (enemy_to_attack != nullptr) {
//                enemy_to_attack->hp -= DAMAGE;
//
//                if (enemy_to_attack->hp <= 0) {
//                    //delete enemy_to_attack;
//                    //need to Add destractor
//                    delete enemy_to_attack;
//                    cout << "FootSoldier Attack and kill" << endl;// dead
//                }
//                else
//                cout << "FootSoldier Attack The life of enemy is " <<enemy_to_attack->hp<< endl; // alive
//            }
//            cout << "No Attack" << endl; // alive
//        }

        pair<int, int> find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
//            Soldier* ans;
//            std::pair<int, int> myLocation = {source.first, source.second};
//            double min_dis = std::numeric_limits<double>::max();
//            double _distance;
//            for (int i = 0; i < board.size(); ++i) {
//                for (int j = 0; j < board.size(); ++j) {
//                    if (board[i][j] != nullptr && board[i][j]->player != this->player) {
//                        _distance = dist(myLocation, {i,j});
//                        if (_distance < min_dis) {
//                            ans = board[i][j];
//                            min_dis = _distance;
//                        }
//                    }
//                }
//            }
//            if (ans!=nullptr)
//                return ans;
//            return nullptr;
//        }

        double dist(std::pair<int, int> from, std::pair<int, int> to)
        {
            double calc =pow(from.first-to.first,2) + pow(from.second - to.second,2);
            return sqrt(calc);

        }
        void fillLife() override{
            this->hp = 100;
        }
        ~FootSoldier(){
            cout <<"remove FootSoldier"<<endl;
        }
//        ~FootSoldier()
//        {
//            delete this;
//        }
    };

}
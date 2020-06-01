#pragma once
#include "Soldier.hpp"

namespace WarGame
{

    class FootCommander : public Soldier
            {
    public:
        FootCommander(int pn):Soldier(150,pn,20){}

        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override {
            for (int i = 0; i < board.size(); ++i)
            {
                for (int j = 0; j < board.at(0).size(); ++j)
                {
                    if (board[i][j] != nullptr && board[i][j]->player == this->player)
                    {
                        if (typeid(board[i][j]) == typeid(FootSoldier))
                        {
                            Soldier* temp= board[i][j];
                            temp->attack(board,{i,j});
                        }
                    }
                }
            }


            Soldier *enemy_to_attack = find_soldier_attack(board, source);
            if (enemy_to_attack != nullptr) {
                enemy_to_attack->hp -= 20;

                if (enemy_to_attack->hp <= 0) {
                    //delete enemy_to_attack;
                    //need to Add destractor
                    delete enemy_to_attack;

                            cout << "FootCommander Attack and kill" << endl;// dead
                }
                cout << "FootCommander Attack The life of enemy is "<<enemy_to_attack->hp<< endl; // alive
            }


            cout << "No Attack" << endl; // alive
        }

        Soldier* find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){
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

        double dist(std::pair<int, int> from, std::pair<int, int> to)
        {
            return sqrt(pow(from.first-to.first,2) + pow(from.second - to.second,2));
        }
        void fillLife() override{
            this->hp = 150;
        }
        ~FootCommander()
        {
            delete this;
        }
    };





}
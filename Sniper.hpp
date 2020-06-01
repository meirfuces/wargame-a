

#include "Soldier.hpp"
namespace WarGame {
    class Sniper : public WarGame::Soldier {

    public:
        Sniper(int pn) : Soldier(120, pn, 100) {
        }

        //fuction Here
        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override {
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
                cout << "Sniper Attack The life of enemy is " <<enemy_to_attack->hp<< endl; // alive
            }
            cout << "No Attack" << endl; // alive
        }

        Soldier* find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){
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

        void fillLife() override{
            this->hp = 100;
        }
//        ~Sniper()
//        {
//            delete this;
//        }
    };
}
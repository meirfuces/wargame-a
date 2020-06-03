

#include "Soldier.hpp"

namespace WarGame {
    class Sniper : public WarGame::Soldier {

    public:
        Sniper(int pn) : Soldier(120, pn) {
        }

        //fuction Here
        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override;
        Soldier* find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
        void fillLife() override{
            this->hp = 100;
        }
        ~Sniper(){
            cout <<"remove Sniper"<<endl;
        }
//        ~Sniper()
//        {
//            delete this;
//        }
    };
}
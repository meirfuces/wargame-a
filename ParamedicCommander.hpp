#pragma once
#include "Soldier.hpp"
# define HEALTH 50
namespace WarGame {

    class ParamedicCommander : public Soldier {
    class WarGame;
    public:
        ParamedicCommander(int pn) : Soldier(200, pn) {}
        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override;/* {
        */

        Soldier* find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
//  r;
//        }
        void fillLife() override{
            this->hp = 200;
        }
//        ~ParamedicCommander()
//        {
//            delete this;
//        }
    };
}
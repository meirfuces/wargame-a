#pragma once
#include "Soldier.hpp"


namespace WarGame
{

    class FootCommander : public Soldier
            {
    public:
        FootCommander(int pn):Soldier(150,pn){}

        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override;
        Soldier* find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
        void fillLife() override{
            this->hp = 150;
        }
        ~FootCommander(){
        }
//        ~FootCommander()
//        {
//            delete this;
//        }
    };





}
#pragma once
#include "Soldier.hpp"
namespace WarGame{
    class FootSoldier : public Soldier
            {
    public:
        FootSoldier(int pn):Soldier(100,pn,10){}

        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override {
            cout<<"FootCommander"<<endl;
      }

    };

}
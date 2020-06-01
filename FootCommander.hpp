#pragma once
#include "Soldier.hpp"

namespace WarGame
{

    class FootCommander : public Soldier
            {
    public:
        FootCommander(int pn):Soldier(150,pn,20){}

        virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override {

            cout<<"FootCommander Attack"<<endl;
        }

    };





}
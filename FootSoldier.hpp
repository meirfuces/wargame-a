#pragma once
#include "Soldier.hpp"
namespace WarGame{
    class FootSoldier : public Soldier
            {
    public:
        FootSoldier(int pn):Soldier(100,pn,10){}

    };

}
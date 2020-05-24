#pragma once

namespace WarGame
{
    class Soldier
{
    public:
        int player;
        int hp;
        int dmg;

        Soldier(int hp, int p,int dmg): hp(hp), player(p) , dmg(dmg) {}

};

}
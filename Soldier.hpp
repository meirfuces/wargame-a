#pragma once
#include <vector>
#include <iostream>
using namespace std;
namespace WarGame
{
    class Soldier
{
    public:
        int player;
        int hp;
        int dmg;

        Soldier(int hp, int p,int dmg): hp(hp), player(p) , dmg(dmg) {}
        virtual void attack(vector<vector<Soldier*>> &board, pair<int,int> source)=0; //abstract function cant init

};

}
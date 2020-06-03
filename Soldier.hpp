#pragma once
#include <vector>
#include "cmath"
#include <iostream>
#include <typeinfo>
using namespace std;
namespace WarGame
{
    class Soldier
{
    public:
        int player;
        int hp;

        Soldier(int hp, int p): hp(hp), player(p)  {}
        virtual void attack(vector<vector<Soldier*>> &board, pair<int,int> source) = 0; //abstract function cant init
        virtual void fillLife() = 0;
        virtual ~Soldier(){
            cout <<"remove"<<endl;
        }
        };

}
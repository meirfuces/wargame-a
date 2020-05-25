

#include "Soldier.hpp"
namespace WarGame {
    class Sniper : public WarGame::Soldier {

    public:
        Sniper(int pn) : Soldier(120, pn, 100) {
        }

        //fuction Here
         void shoot1(); //need to change virtoul
    };
}
#include "Soldier.hpp"
namespace WarGame {
class SniperCommander : public WarGame::Soldier {

    public:
        SniperCommander(int pn) : Soldier(120, pn, 100) {
        }

        //fuction Here
         void shoot();
    };
}
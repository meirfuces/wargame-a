#include "Soldier.hpp"
namespace WarGame {
class SniperCommander : public WarGame::Soldier {

    public:
        SniperCommander(int pn) : Soldier(120, pn) {
        }

        //fuction Here
        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override;
    Soldier* find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
        void fillLife() override{
    this->hp = 120;
}
    ~SniperCommander(){
        cout <<"remove SniperCommander"<<endl;
    }
//    ~SniperCommander()
//    {
//        delete this;
//    }
    };

}
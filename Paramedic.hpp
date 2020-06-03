#pragma once
#include "Soldier.hpp"
# define HEALTH 50
namespace WarGame {

    class Paramedic : public Soldier {
    public:
        Paramedic(int pn) : Soldier(100, pn) {}
        void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override;

            Soldier* find_soldier_attack (std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);

        void fillLife() override{
            this->hp = 100;
        }
        ~Paramedic(){
            cout <<"remove Paramedic"<<endl;
        }
//        ~Paramedic()
//        {
//            delete this;
//        }
    };
}
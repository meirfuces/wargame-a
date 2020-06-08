//
// Created by Ginton Durlacher on 24/05/2020.
//
//#include <iostream>
//using namespace std;
#include "Board.hpp"

namespace WarGame
{
    bool Board::has_soldiers(uint pn) const
    {
        cout<<"check has soldier"<<endl;
//        std::pair<int,int> p;
        for(int i = 0; i < board.size() ; i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
//
//                p.first = i;
//                p.second = j;
                if(board[i][j]!=nullptr && board[i][j]->player==pn) return true;
            }
        }
        cout<<"has not soldeirs for player: "<<pn<<endl;
        return false;
    }

    Soldier*& Board::operator[](std::pair<int,int> location)
    {
        return this->board[location.first][location.second];

    }

    Soldier* Board::operator[](std::pair<int,int> location) const
    {
        return this->board[location.first][location.second];

    }
    void Board::win (){
     if (this->has_soldiers(1)==true&& this->has_soldiers(2)==false )
         cout<<"Team 1 win"<<endl;
        if (this->has_soldiers(2)==true&& this->has_soldiers(1)==false )
            cout<<"Team 2 win"<<endl;
else
            cout<<"tie"<<endl;

    }

    //The Soldier is moves to direction and attacks
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
    {

        if (this->board[source.first][source.second]==nullptr)
        {
            cout<<"check place empty test"<<endl;
            throw std::invalid_argument("place is empty meir test throw");

        }
        if(source.first<0 || source.second<0)
            throw std::invalid_argument("0 invalid argument for the board");
        if(source.first>=this->board.size() || source.second>=this->board.size())
            throw std::invalid_argument("out of bound");
        Soldier* temp = this->board[source.first][source.second];

       cout <<" team: "<< temp->player<<endl;
        if(temp->player != player_number)
            throw std::invalid_argument("the Soldier not belong to player number");

        switch (direction)
        {
            case Up:
                if(source.first+1>=this->board.size())
                    throw std::invalid_argument("The move Up is out of bound");
                temp->attack(board,source);
                cout<<"Move Up "<<endl;
                board[source.first][source.second] = nullptr;
                board[source.first+1][source.second] = temp;
                break;
            case Down:
             if(   source.first-1<=0)
                 throw std::invalid_argument("The move Down is out of bound");
                temp->attack(board,source);
                cout<<"Move Down "<<endl;
             board[source.first][source.second] = nullptr;
                board[source.first-1][source.second] = temp;
                break;
            case Right:
                if(source.second+1>=this->board.size())
                    throw std::invalid_argument("The move Right is out of bound");
                temp->attack(board,source);
                cout<<"Move Right "<<endl;
                board[source.first][source.second] = nullptr;

                board[source.first][source.second+1] = temp;
                break;
            case Left:
                if(   source.second-1=<0)
                    throw std::invalid_argument("The move Left is out of bound");
                temp->attack(board,source);
                cout<<"Move Left "<<endl;
                board[source.first][source.second] = nullptr;

                board[source.first][source.second-1] = temp;
                break;

            default:
                break;
        }
    }






}
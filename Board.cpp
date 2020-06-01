//
// Created by Ginton Durlacher on 24/05/2020.
//

#include "Board.hpp"

namespace WarGame
{
    bool Board::has_soldiers(uint pn) const
    {
        for(int i = 0; i < board.size() ; i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                std::pair<int,int> p;
                p.first = i;
                p.second = j;
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
    //The Soldier is moves to direction and attacks
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
    {

        if(source.first<0 || source.second<0)
            throw std::invalid_argument("0 invalid argument for the board");
        if(source.first>this->board.size() || source.second>this->board.size())
            throw std::invalid_argument("out of bound");
        Soldier* temp = this->board[source.first][source.second];
        if (temp==nullptr)
        {
            throw std::invalid_argument("place is empty");
        }
       cout <<" team: "<< temp->player<<endl;
        if(temp->player != player_number)
            throw std::invalid_argument("the Soldier not belong to player number");

        switch (direction)
        {
            case Up:
                if(source.first+1>this->board.size())
                    throw std::invalid_argument("The move Up is out of bound");
                //soldier->attack(board,source);
                board[source.first][source.second] = nullptr;
                board[source.first+1][source.second] = temp;
                break;
            case Down:
             if(   source.first-1<0)
                 throw std::invalid_argument("The move Down is out of bound");
             //soldier->attack(board,source);
             board[source.first][source.second] = nullptr;
                board[source.first-1][source.second] = temp;
                break;
            case Right:
                if(source.second+1>this->board.size())
                    throw std::invalid_argument("The move Right is out of bound");
                //soldier->attack(board,source);
                board[source.first][source.second] = nullptr;

                board[source.first][source.second+1] = temp;
                break;
            case Left:
                if(   source.second-1<0)
                    throw std::invalid_argument("The move Left is out of bound");
                //soldier->attack(board,source);
                board[source.first][source.second] = nullptr;

                board[source.first][source.second-1] = temp;
                break;

            default:
                break;
        }
    }






}
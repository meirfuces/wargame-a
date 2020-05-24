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

    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
    {
        if(source.first<0 || source.second<0) throw;
        if(source.first>this->board.size() || source.second>this->board.size()) throw;
        return;
    }






}
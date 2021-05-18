//#pragma once
#include "Player.hpp"
namespace pandemic {
    class Virologist:public Player{
    public:
        Virologist(Board& board,City city);
         std::string role ();
        Player& treat (City city);
        




    };
};
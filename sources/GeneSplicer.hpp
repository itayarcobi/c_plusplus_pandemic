//#pragma once
#include "Player.hpp"
namespace pandemic {
    class GeneSplicer:public Player{
    public:
        GeneSplicer(Board& board,City city);
        std::string role ();
        Player& discover_cure (Color color);




    };
};
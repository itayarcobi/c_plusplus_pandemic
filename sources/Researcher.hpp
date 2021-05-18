//#pragma once
#include "Player.hpp"
namespace pandemic {
    class Researcher:public Player{
    public:
        Researcher(Board& board,City city);
        std::string role ();
        Player& discover_cure (Color color);




    };
};
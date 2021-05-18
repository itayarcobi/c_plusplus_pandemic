//#pragma once
#include "Player.hpp"
namespace pandemic {
    class Scientist:public Player{
        int ncards;
        public:
        Scientist(Board& board,City city,int n);
        std::string role ();
        Player& discover_cure (Color color);




    };
};
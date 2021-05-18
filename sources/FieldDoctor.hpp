//#pragma once
#include "Player.hpp"
namespace pandemic {
    class FieldDoctor:public Player{

    public:
        FieldDoctor(Board& board,City city);
        std::string role ();
        Player& treat (City city);
        




    };
};
//#pragma once
#include "Player.hpp"
namespace pandemic {
    class OperationsExpert:public Player{
    public:
        
        OperationsExpert(Board& board,City city);
         std::string role ();         
       void build();



    };
};
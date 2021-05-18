#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "Board.hpp"
namespace pandemic {
        OperationsExpert::OperationsExpert(Board& board,City city):Player{board,city}{};
        void OperationsExpert::build(){
                myboard.station[myplace]=1;
            }
        std::string OperationsExpert::role (){            
            return "OperationsExpert";
        };



    };
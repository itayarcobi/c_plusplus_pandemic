#include "Player.hpp"
#include "FieldDoctor.hpp"
namespace pandemic {
        FieldDoctor::FieldDoctor(Board& board,City city):Player{board,city}{
        };
        Player& FieldDoctor::treat (City city){
            if(!(myboard.cities_map[myplace][city])&&myplace!=city){
                throw "you cant treat a city you are not conncted to her";
            }
            if(myboard.disease[city]==0){
                throw "the disease level is already zero";
            }
            if(myboard.cures[myboard.cities_colors[city]]){
                myboard.disease[city]=0;
            }
            else if(myboard.disease[city]>0){
                myboard.disease[city]-=1;
            }
            return *this;
        };
        std::string FieldDoctor::role (){            
            return "FieldDoctor";
        };




};
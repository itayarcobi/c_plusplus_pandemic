#include "Player.hpp"
#include "Virologist.hpp"
namespace pandemic {
        Virologist::Virologist(Board& board,City city):Player{board,city}{};
        std::string Virologist::role (){            
            return "Virologist";
        };
        Player& Virologist::treat (City city){
            if(myboard.disease[city]==0){
                throw "the disease level is already zero";
            }
            if(myplace!=city && cards[city]==0){
                throw "not enough cards";
            }
            if(myplace!=city && cards[city]>0){
            if(myboard.cures[myboard.cities_colors[city]]){
                myboard.disease[city]=0;
                this->cards[city]-=1; 
            }
            if(myboard.disease[city]>0){
                myboard.disease[city]-=1;
                this->cards[city]-=1; 

            }
            }
            else if(myplace==city){
                if(myboard.cures[myboard.cities_colors[city]]){
                myboard.disease[city]=0;
            }
            if(myboard.disease[city]>0){
                myboard.disease[city]-=1;
            }
            }




            return *this;
        };




    };
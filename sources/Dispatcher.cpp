#include "Player.hpp"
#include "Dispatcher.hpp"
namespace pandemic {
        Dispatcher::Dispatcher(Board& board,City city):Player{board,city}{};
        Player& Dispatcher::fly_direct(City city){
            if (city==myplace){
                throw "you are already here";
            }
            if(myboard.station[myplace]==1){
                myplace=city;
            }
            else{
            if( this->cards[city]>0){
                myplace=city;
                 this->cards[city]=this->cards[city]-1;
                 this->colors_points[myboard.cities_colors[city]]-=1;  

            }
            else{
                throw "no correct card";
            }
            }
        return *this;
        };
        std::string Dispatcher::role (){            
            return "Dispatcher";
        };


};
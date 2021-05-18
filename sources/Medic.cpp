#include "Player.hpp"
#include "Medic.hpp"
namespace pandemic {
        Medic::Medic(Board& board,City city):Player{board,city}{};
        std::string Medic::role (){            
            return "Medic";
        };
        Player& Medic::treat (City city){
            if(myplace!=city){
                throw "you cant treat a city you are not in";
            }
            if(myboard.disease[city]==0){
                throw "the disease level is already zero";
            }
            // if(myboard.cures[myboard.cities_colors[city]]){
            //     myboard.disease[city]=0;
            // }
            if(myboard.disease[city]>0){
                myboard.disease[city]=0;
            }
            return *this;
        };
        Player& Medic::drive(City city){
             if (city==myplace){
                throw "you are already here";
            }
            if(myboard.cities_map[myplace][city]){
                myplace=city;
            }
            else{
                throw "you cannot drive to a unconnected city";
            }
            if(myboard.cures[myboard.cities_colors[city]]){
                myboard.disease[city]=0;
            }
         
            return *this;
        };
        Player& Medic::fly_direct(City city){
            if (city==myplace){
                throw "you are already here";
            }
            if( this->cards[city]>0){
                myplace=city;
                 this->cards[city]=cards[city]-1;
                 this->colors_points[myboard.cities_colors[city]]-=1;  

            }
            else{
                throw "no correct card";
            }
             if(myboard.cures[myboard.cities_colors[city]]){
                myboard.disease[city]=0;
            }
           
        return *this;
        };
        Player& Medic::fly_charter (City city){
             if (city==myplace){
                throw "you are already here";
            }
               if(this->cards[myplace]<1){
                throw "no correct card";
            }
             if( this->cards[myplace]>0){
                 this->cards[myplace]=cards[myplace]-1;
                 this->colors_points[myboard.cities_colors[myplace]]-=1;  
                myplace=city;
            }
            if(myboard.cures[myboard.cities_colors[city]]){
                myboard.disease[city]=0;
            }
         
           
        return *this;

        };
        Player& Medic::fly_shuttle(City city){
             if (city==myplace){
                throw "you are already here";
            }
            if (myboard.station[myplace]==1 && myboard.station[city]==1){
                // std::cout<<"enter"<<std::endl;
                myplace=city;
            }
            else{
               // std::cout<<"myplace: "<<this->myplace<<std::endl;
                //  std::cout<<"station myplace: "<<myboard.station[myplace]<<std::endl;
                // std::cout<<"station city: "<<myboard.station[city]<<std::endl;

                throw "does not have staion in one of this cities";
            }
            if(myboard.cures[myboard.cities_colors[city]]){
                myboard.disease[city]=0;
            }
          
        return *this;
        };


    };
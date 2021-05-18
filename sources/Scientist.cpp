#include "Player.hpp"
#include "Scientist.hpp"
#include <vector>

namespace pandemic {
 
        Scientist::Scientist(Board& board,City city,int n):Player{board,city}{
            this->ncards=n;
        };
        std::string Scientist::role (){            
            return "Scientist";
        };
        Player& Scientist::discover_cure (Color color){
            if (!myboard.cures[color]){
            if(myboard.station[myplace]==0){
                throw "no station in this city";
            }
            if(colors_points[color]<this->ncards){
                    throw "not enough cards";
                }
          if(colors_points[color]>=this->ncards){
                std::unordered_map<int ,City> discard_cities;
                //City discard_cities [this->ncards];
                //City discard_cities [this->ncards];
                int i=0;
                std::unordered_map<City ,Color>::iterator it ;
                for (it=myboard.cities_colors.begin();it!=myboard.cities_colors.end();it++){
                        if (it->second==color && this->cards[it->first]>0 && i<this->ncards){
                           // cards[it->first]-=1;
                          //  colors_points[color]-=5;
                            discard_cities [i]=it->first;
                            i++;
                        }
                   if(i==this->ncards){
                       for (int j = 0; j <i; j++)
                {
                    cards[discard_cities[j]]-=1;
                }
                colors_points[color]-=this->ncards;
                myboard.cures[color]=true;
                   }

                }


                }
                


            }



            return *this;

        }




    };
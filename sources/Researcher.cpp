#include "Player.hpp"
#include "Researcher.hpp"
#include <list>

namespace pandemic {
        Researcher::Researcher(Board& board,City city):Player{board,city}{};
        std::string Researcher::role (){            
            return "Researcher";
        };
        Player& Researcher::discover_cure (Color color){
            if (!myboard.cures[color]){
               const int CARDS_FOR_CURE =5;
               if(colors_points[color]<CARDS_FOR_CURE){
                    throw "not enough cards";
                }
            if(colors_points[color]>=CARDS_FOR_CURE){
                std::unordered_map<int ,City> discard_cities;
                //City discard_cities [5];
                int i=0;
                std::unordered_map<City ,Color>::iterator it ;
                for (it=myboard.cities_colors.begin();it!=myboard.cities_colors.end();it++){
                        if (it->second==color && this->cards[it->first]>0 && i<CARDS_FOR_CURE){
                           // cards[it->first]-=1;
                          //  colors_points[color]-=5;
                            discard_cities[i]=it->first;
                            i++;
                        }
                   if(i==CARDS_FOR_CURE){
                       for (int j = 0; j <i; j++)
                {
                    cards[discard_cities[j]]-=1;
                }
                colors_points[color]-=CARDS_FOR_CURE;
                myboard.cures[color]=true;
                   }

                }


                }
                


            }



            return *this;

        }
        
    };
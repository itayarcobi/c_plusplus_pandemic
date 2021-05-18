#include "Player.hpp"
#include "GeneSplicer.hpp"
namespace pandemic {
        GeneSplicer::GeneSplicer(Board& board,City city):Player{board,city}{};
        std::string GeneSplicer::role (){            
            return "GeneSplicer";
        };
         Player& GeneSplicer::discover_cure (Color color){
            if (!myboard.cures[color]){
            if(myboard.station[myplace]==0){
                throw "no station in this city";
            }
        int count=0;
        const int CARDS_FOR_CURE =5;
         std::unordered_map<City ,int>::iterator it ;
        for (it=cards.begin();it!=cards.end()&&count<CARDS_FOR_CURE;it++){
            if(it->second!=0){
                count++;
            }
        }


                if(count<CARDS_FOR_CURE){
                    throw "not enough cards";
                }
                   if(count>=CARDS_FOR_CURE){
                 std::unordered_map<int ,City> discard_cities;
               // City discard_cities [CARDS_FOR_CURE];
                int i=0;
                std::unordered_map<City ,Color>::iterator it ;
                for (it=myboard.cities_colors.begin();it!=myboard.cities_colors.end();it++){
                        if (this->cards[it->first]>0 && i<CARDS_FOR_CURE){
                           // cards[it->first]-=1;
                          //  colors_points[color]-=5;
                            discard_cities[i]=it->first;
                            i++;
                        }
                   if(i==CARDS_FOR_CURE){
                       for (int j = 0; j <i; j++)
                {
                    cards[discard_cities[j]]=0;
                    colors_points[myboard.cities_colors[discard_cities[j]]]-=1;
                }
                myboard.cures[color]=true;
                   }

                }

                }


            }



            return *this;

        }




    };
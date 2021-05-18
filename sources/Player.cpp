#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include <algorithm>    // std::for_each
#include <iostream>
namespace pandemic {
        Player::Player(Board& board,City city):myplace{city},myboard{board}{
            init_cards();
        };
        
        Player::~Player(){}
        Player& Player::drive(City city){
             if (city==myplace){
                throw "you are already here";
            }
            if(myboard.cities_map[myplace][city]){
                myplace=city;
            }
            else{
                throw "you cannot drive to a unconnected city";
            }
            return *this;
        };
        Player& Player::fly_direct(City city){
            if (city==myplace){
                throw "you are already here";
            }
          //  std::cout<<this->cards[city]<<std::endl;
            if( this->cards[city]>0){
                myplace=city;
                 this->cards[city]=this->cards[city]-1;
                 this->colors_points[myboard.cities_colors[city]]-=1;  

            }
            else{
                throw "no correct card";
            }
        return *this;
        };
        Player& Player::fly_charter (City city){
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

        return *this;

        };
        Player& Player::fly_shuttle(City city){
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
        return *this;
        };
        void Player::build(){
              if(this->cards[myplace]<1){
                throw "no correct card";
            }
             if(this->cards[myplace]>0){
              //  std::cout<<"enter"<<std::endl;
                this->cards[myplace]-=1;
                this->colors_points[myboard.cities_colors[myplace]]-=1;  
                myboard.station[myplace]=1;
            }
          
      //    std::cout<<"station myplace: "<<myboard.station[myplace]<<std::endl;
        };
        Player& Player::discover_cure (Color color){
            if (!myboard.cures[color]){
                       
            if(myboard.station[myplace]==0){
                throw "no station in this city";
            }
            //using Lambda Expression;
            // if(colors_points[color]>=5){
            //    City discard_cities [5];
            //     std::for_each(myboard.cities_colors.begin(),myboard.cities_colors.end(),
            //     [&](City c,City *discard_cities){
            //         int i=0;
            //         while(i<5){
            //         if (this->cards[c]>0){
            //             discard_cities[i]=c;
            //         }
            //         }
            //     });
            //     for (int i = 0; i <5; i++)
            //     {
            //         cards[discard_cities[i]]-=1;
            //         colors_points[color]-=5;
            //         myboard.cures[color]=true;
            //     }
                
            //  }
            const int CARDS_FOR_CURE =5;
            if(this->colors_points[color]<CARDS_FOR_CURE){
                    throw "not enough color cards";
                }

               if(this->colors_points[color]>=CARDS_FOR_CURE){
                std::unordered_map<int ,City> discard_cities;
               //City discard_cities[CARDS_FOR_CURE];
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
        Player& Player::treat (City city){
            if(myplace!=city){
                throw "you cant treat a city you are not in";
            }
            if(myboard.disease[city]==0){
                throw "the disease level is already zero";
            }
            if(myboard.cures[myboard.cities_colors[city]]){
                myboard.disease[city]=0;
            }
            if(myboard.disease[city]>0){
                myboard.disease[city]-=1;
            }
            return *this;
        };
         std::string Player::role (){            
            return "Player";
        };
        Player& Player::take_card (City city){ 
            if(this->cards[city]<=0){         
             this->cards[city]=1;
             this->colors_points[myboard.cities_colors[city]]+=1;
            }
            return *this;
        };
        void Player::remove_cards(){
             this->cards.clear();
        };
        void Player::init_cards(){
            this->colors_points[Color::Red]=0;
            this->colors_points[Color::Black]=0;
            this->colors_points[Color::Blue]=0;
            this->colors_points[Color::Yellow]=0;
                this->cards[City::Algiers]=0;
                this->cards[City::Atlanta]=0;
                this->cards[City::Baghdad]=0;
                this->cards[City::Bangkok]=0;
                this->cards[City::Beijing]=0;
                this->cards[City::Bogota]=0;
                this->cards[City::BuenosAires]=0;
                this->cards[City::Cairo]=0;
                this->cards[City::Chennai]=0;
                this->cards[City::Chicago]=0;
                this->cards[City::Delhi]=0;
                this->cards[City::Essen]=0;
                this->cards[City::HoChiMinhCity]=0;
                this->cards[City::HongKong]=0;
                this->cards[City::Istanbul]=0;
                this->cards[City::Jakarta]=0;
                this->cards[City::Johannesburg]=0;
                this->cards[City::Karachi]=0;
                this->cards[City::Khartoum]=0;
                this->cards[City::Kinshasa]=0;
                this->cards[City::Kolkata]=0;
                this->cards[City::Lagos]=0;
                this->cards[City::Lima]=0;
                this->cards[City::London]=0;
                this->cards[City::LosAngeles]=0;
                this->cards[City::Madrid]=0;
                this->cards[City::Manila]=0;
                this->cards[City::MexicoCity]=0;
                this->cards[City::Miami]=0;
                this->cards[City::Milan]=0;
                this->cards[City::Montreal]=0;
                this->cards[City::Moscow]=0;
                this->cards[City::Mumbai]=0;
                this->cards[City::NewYork]=0;
                this->cards[City::Osaka]=0;
                this->cards[City::Paris]=0;
                this->cards[City::Riyadh]=0;
                this->cards[City::SanFrancisco]=0;
                this->cards[City::Santiago]=0;
                this->cards[City::SaoPaulo]=0;
                this->cards[City::Seoul]=0;
                this->cards[City::Shanghai]=0;
                this->cards[City::StPetersburg]=0;
                this->cards[City::Sydney]=0;
                this->cards[City::Taipei]=0;
                this->cards[City::Tehran]=0;
                this->cards[City::Tokyo]=0;
                this->cards[City::Washington]=0;

        }





    };

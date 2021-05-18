#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <unordered_map>
namespace pandemic {
    class Player{
        protected:
         std::unordered_map<City ,int> cards;
         std::unordered_map<Color ,int> colors_points;
        City myplace;
        Board& myboard;

        public:
        Player(Board& board,City city);
        ~Player();
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter (City city);
        virtual Player& fly_shuttle(City city);
        virtual void build();
        virtual Player& discover_cure (Color color);
        virtual Player& treat (City city);
        virtual  std::string role ();
        virtual Player& take_card (City city);
        virtual  void remove_cards();
        void init_cards();




    };
};
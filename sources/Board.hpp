#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <unordered_map>
namespace pandemic {
    class Board{
    public:
     std::unordered_map<City ,int> disease;
     std::unordered_map<City ,int> station;
     std::unordered_map<City,std::unordered_map<City,bool>> cities_map;
     std::unordered_map<City ,Color> cities_colors;
     std::unordered_map<Color,bool> cures;

    Board();
    ~Board();
  
    int& operator[]( City c);
  
    friend std::ostream& operator << (std::ostream& output, const Board& board);
     bool is_clean();
    void remove_cures();
    void remove_stations();
   
     void init_board();

    };
};

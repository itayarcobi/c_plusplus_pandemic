#include "City.hpp"
#include <iostream>
#include "Board.hpp"
namespace pandemic {
    Board::Board(){
        Board::init_board();
    }
    Board::~Board(){}
    
    int& Board::operator[]( City city){
        return  disease[city];
    }
     std::ostream& operator << (std::ostream& output, const Board& board){
        return output;
    }
    bool Board::is_clean(){
        // City c;
        // if(this->disease.size()==0)
        //     return true;
        // return false;
        bool ans=true;
         std::unordered_map<City ,int>::iterator it ;
        for (it=disease.begin();it!=disease.end();it++){
            if(it->second>0){
               ans=false;
               break;
            }
        }
        return ans;
    }
    void Board::remove_cures(){
         this->cures.clear();
    }
    void Board::remove_stations(){
         this->station.clear();
    }
    void Board::init_board(){
        this->cures[Color::Red]=false;
        this->cures[Color::Yellow]=false;
        this->cures[Color::Black]=false;
        this->cures[Color::Blue]=false;
        this->disease[City::Algiers]=0;
        this->cities_colors[City::Algiers]=Color::Black;
        this->station[City::Algiers]=0;
        this->cities_map[City::Algiers][City::Madrid]=true;
        this->cities_map[City::Algiers][City::Paris]=true;
        this->cities_map[City::Algiers][City::Istanbul]=true;
        this->cities_map[City::Algiers][City::Cairo]=true;
        this->disease[City::Atlanta]=0;
        this->cities_colors[City::Atlanta]=Color::Blue;
        this->station[City::Atlanta]=0;
        this->cities_map[City::Atlanta][City::Chicago]=true;
        this->cities_map[City::Atlanta][City::Miami]=true;
        this->cities_map[City::Atlanta][City::Washington]=true;
        this->disease[City::Baghdad]=0;
        this->cities_colors[City::Baghdad]=Color::Black;
        this->station[City::Baghdad]=0;
        this->cities_map[City::Baghdad][City::Tehran]=true;
        this->cities_map[City::Baghdad][City::Istanbul]=true;
        this->cities_map[City::Baghdad][City::Cairo]=true;
        this->cities_map[City::Baghdad][City::Riyadh]=true;
        this->cities_map[City::Baghdad][City::Karachi]=true;
        this->disease[City::Bangkok]=0;
        this->cities_colors[City::Bangkok]=Color::Red;
        this->station[City::Bangkok]=0;
        this->cities_map[City::Bangkok][City::Kolkata]=true;
        this->cities_map[City::Bangkok][City::Chennai]=true;
        this->cities_map[City::Bangkok][City::Jakarta]=true;
        this->cities_map[City::Bangkok][City::HoChiMinhCity]=true;
        this->cities_map[City::Bangkok][City::HongKong]=true;
        this->disease[City::Beijing]=0;
        this->cities_colors[City::Beijing]=Color::Red;
        this->station[City::Beijing]=0;
        this->cities_map[City::Beijing][City::Shanghai]=true;
        this->cities_map[City::Beijing][City::Seoul]=true;
        this->disease[City::Bogota]=0;
        this->cities_colors[City::Bogota]=Color::Yellow;
        this->station[City::Bogota]=0;
        this->cities_map[City::Bogota][City::MexicoCity]=true;
        this->cities_map[City::Bogota][City::Lima]=true;
        this->cities_map[City::Bogota][City::Miami]=true;
        this->cities_map[City::Bogota][City::SaoPaulo]=true;
        this->cities_map[City::Bogota][City::BuenosAires]=true;
        this->disease[City::BuenosAires]=0;
        this->cities_colors[City::BuenosAires]=Color::Yellow;
        this->station[City::BuenosAires]=0;
        this->cities_map[City::BuenosAires][City::Bogota]=true;
        this->cities_map[City::BuenosAires][City::SaoPaulo]=true;
        this->disease[City::Cairo]=0;
        this->cities_colors[City::Cairo]=Color::Black;
        this->station[City::Cairo]=0;
        this->cities_map[City::Cairo][City::Algiers]=true;
        this->cities_map[City::Cairo][City::Istanbul]=true;
        this->cities_map[City::Cairo][City::Baghdad]=true;
        this->cities_map[City::Cairo][City::Khartoum]=true;
        this->cities_map[City::Cairo][City::Riyadh]=true;
        this->cities_map[City::Cairo][City::Istanbul]=true;
        this->disease[City::Chennai]=0;
        this->cities_colors[City::Chennai]=Color::Black;
        this->station[City::Chennai]=0;
        this->cities_map[City::Chennai][City::Mumbai]=true;
        this->cities_map[City::Chennai][City::Delhi]=true;
        this->cities_map[City::Chennai][City::Kolkata]=true;
        this->cities_map[City::Chennai][City::Bangkok]=true;
        this->cities_map[City::Chennai][City::Jakarta]=true;
        this->disease[City::Chicago]=0;
        this->cities_colors[City::Chicago]=Color::Blue;
        this->station[City::Chicago]=0;
        this->cities_map[City::Chicago][City::SanFrancisco]=true;
        this->cities_map[City::Chicago][City::LosAngeles]=true;
        this->cities_map[City::Chicago][City::MexicoCity]=true;
        this->cities_map[City::Chicago][City::Atlanta]=true;
        this->cities_map[City::Chicago][City::Montreal]=true;
        this->disease[City::Delhi]=0;
        this->cities_colors[City::Delhi]=Color::Black;
        this->station[City::Delhi]=0;
        this->cities_map[City::Delhi][City::Tehran]=true;
        this->cities_map[City::Delhi][City::Karachi]=true;
        this->cities_map[City::Delhi][City::Mumbai]=true;
        this->cities_map[City::Delhi][City::Chennai]=true;
        this->cities_map[City::Delhi][City::Kolkata]=true;
        this->disease[City::Essen]=0;
        this->cities_colors[City::Essen]=Color::Blue;
        this->station[City::Essen]=0;
        this->cities_map[City::Essen][City::London]=true;
        this->cities_map[City::Essen][City::Paris]=true;
        this->cities_map[City::Essen][City::Milan]=true;
        this->cities_map[City::Essen][City::StPetersburg]=true;
        this->disease[City::HoChiMinhCity]=0;
        this->cities_colors[City::HoChiMinhCity]=Color::Red;
        this->station[City::HoChiMinhCity]=0;
        this->cities_map[City::HoChiMinhCity][City::Jakarta]=true;
        this->cities_map[City::HoChiMinhCity][City::Bangkok]=true;
        this->cities_map[City::HoChiMinhCity][City::HongKong]=true;
        this->cities_map[City::HoChiMinhCity][City::Manila]=true;
        this->disease[City::HongKong]=0;
        this->cities_colors[City::HongKong]=Color::Red;
        this->station[City::HongKong]=0;
        this->cities_map[City::HongKong][City::Bangkok]=true;
        this->cities_map[City::HongKong][City::Kolkata]=true;
        this->cities_map[City::HongKong][City::HoChiMinhCity]=true;
        this->cities_map[City::HongKong][City::Shanghai]=true;
        this->cities_map[City::HongKong][City::Manila]=true;
        this->cities_map[City::HongKong][City::Taipei]=true;
        this->disease[City::Istanbul]=0;
        this->cities_colors[City::Istanbul]=Color::Black;
        this->station[City::Istanbul]=0;
        this->cities_map[City::Istanbul][City::Milan]=true;
        this->cities_map[City::Istanbul][City::Algiers]=true;
        this->cities_map[City::Istanbul][City::StPetersburg]=true;
        this->cities_map[City::Istanbul][City::Cairo]=true;
        this->cities_map[City::Istanbul][City::Baghdad]=true;
        this->cities_map[City::Istanbul][City::Moscow]=true;
        this->disease[City::Jakarta]=0;
        this->cities_colors[City::Jakarta]=Color::Red;
        this->station[City::Jakarta]=0;
        this->cities_map[City::Jakarta][City::Chennai]=true;
        this->cities_map[City::Jakarta][City::Bangkok]=true;
        this->cities_map[City::Jakarta][City::HoChiMinhCity]=true;
        this->cities_map[City::Jakarta][City::Sydney]=true;
        this->disease[City::Johannesburg]=0;
        this->cities_colors[City::Johannesburg]=Color::Yellow;
        this->station[City::Johannesburg]=0;
        this->cities_map[City::Johannesburg][City::Kinshasa]=true;
        this->cities_map[City::Johannesburg][City::Khartoum]=true;
        this->disease[City::Karachi]=0;
        this->cities_colors[City::Karachi]=Color::Black;
        this->station[City::Karachi]=0;
        this->cities_map[City::Karachi][City::Tehran]=true;
        this->cities_map[City::Karachi][City::Baghdad]=true;
        this->cities_map[City::Karachi][City::Riyadh]=true;
        this->cities_map[City::Karachi][City::Mumbai]=true;
        this->cities_map[City::Karachi][City::Delhi]=true;
        this->disease[City::Khartoum]=0;
        this->cities_colors[City::Khartoum]=Color::Yellow;
        this->station[City::Khartoum]=0;
        this->cities_map[City::Khartoum][City::Cairo]=true;
        this->cities_map[City::Khartoum][City::Lagos]=true;
        this->cities_map[City::Khartoum][City::Kinshasa]=true;
        this->cities_map[City::Khartoum][City::Johannesburg]=true;
        this->disease[City::Kinshasa]=0;
        this->cities_colors[City::Kinshasa]=Color::Yellow;
        this->station[City::Kinshasa]=0;
        this->cities_map[City::Kinshasa][City::Lagos]=true;
        this->cities_map[City::Kinshasa][City::Khartoum]=true;
        this->cities_map[City::Kinshasa][City::Johannesburg]=true;
        this->disease[City::Kolkata]=0;
        this->cities_colors[City::Kolkata]=Color::Black;
        this->station[City::Kolkata]=0;
        this->cities_map[City::Kolkata][City::Delhi]=true;
        this->cities_map[City::Kolkata][City::Chennai]=true;
        this->cities_map[City::Kolkata][City::Bangkok]=true;
        this->cities_map[City::Kolkata][City::HongKong]=true;
        this->disease[City::Lagos]=0;
        this->cities_colors[City::Lagos]=Color::Yellow;
        this->station[City::Lagos]=0;
        this->cities_map[City::Lagos][City::SaoPaulo]=true;
        this->cities_map[City::Lagos][City::Khartoum]=true;
        this->cities_map[City::Lagos][City::Kinshasa]=true;
        this->disease[City::Lima]=0;
        this->cities_colors[City::Lima]=Color::Yellow;
        this->station[City::Lima]=0;
        this->cities_map[City::Lima][City::MexicoCity]=true;
        this->cities_map[City::Lima][City::Bogota]=true;
        this->cities_map[City::Lima][City::Santiago]=true;
        this->disease[City::London]=0;
        this->cities_colors[City::London]=Color::Blue;
        this->station[City::London]=0;
        this->cities_map[City::London][City::NewYork]=true;
        this->cities_map[City::London][City::Madrid]=true;
        this->cities_map[City::London][City::Essen]=true;
        this->cities_map[City::London][City::Paris]=true;
        this->disease[City::LosAngeles]=0;
        this->cities_colors[City::LosAngeles]=Color::Yellow;
        this->station[City::LosAngeles]=0;
        this->cities_map[City::LosAngeles][City::SanFrancisco]=true;
        this->cities_map[City::LosAngeles][City::Chicago]=true;
        this->cities_map[City::LosAngeles][City::MexicoCity]=true;
        this->cities_map[City::LosAngeles][City::Sydney]=true;
        this->disease[City::Madrid]=0;
        this->cities_colors[City::Madrid]=Color::Blue;
        this->station[City::Madrid]=0;
        this->cities_map[City::Madrid][City::London]=true;
        this->cities_map[City::Madrid][City::NewYork]=true;
        this->cities_map[City::Madrid][City::Paris]=true;
        this->cities_map[City::Madrid][City::SaoPaulo]=true;
        this->cities_map[City::Madrid][City::Algiers]=true;
        this->disease[City::Manila]=0;
        this->cities_colors[City::Manila]=Color::Red;
        this->station[City::Manila]=0;
        this->cities_map[City::Manila][City::Taipei]=true;
        this->cities_map[City::Manila][City::SanFrancisco]=true;
        this->cities_map[City::Manila][City::HoChiMinhCity]=true;
        this->cities_map[City::Manila][City::Sydney]=true;
        this->cities_map[City::Manila][City::HongKong]=true;
        this->disease[City::MexicoCity]=0;
        this->cities_colors[City::MexicoCity]=Color::Yellow;
        this->station[City::MexicoCity]=0;
        this->cities_map[City::MexicoCity][City::LosAngeles]=true;
        this->cities_map[City::MexicoCity][City::Chicago]=true;
        this->cities_map[City::MexicoCity][City::Miami]=true;
        this->cities_map[City::MexicoCity][City::Lima]=true;
        this->cities_map[City::MexicoCity][City::Bogota]=true;
        this->disease[City::Miami]=0;
        this->cities_colors[City::Miami]=Color::Yellow;
        this->station[City::Miami]=0;
        this->cities_map[City::Miami][City::Atlanta]=true;
        this->cities_map[City::Miami][City::MexicoCity]=true;
        this->cities_map[City::Miami][City::Washington]=true;
        this->cities_map[City::Miami][City::Bogota]=true;
        this->disease[City::Milan]=0;
        this->cities_colors[City::Milan]=Color::Blue;
        this->station[City::Milan]=0;
        this->cities_map[City::Milan][City::Essen]=true;
        this->cities_map[City::Milan][City::Paris]=true;
        this->cities_map[City::Milan][City::Istanbul]=true;
        this->disease[City::Montreal]=0;
        this->cities_colors[City::Montreal]=Color::Blue;
        this->station[City::Montreal]=0;
        this->cities_map[City::Montreal][City::Chicago]=true;
        this->cities_map[City::Montreal][City::Washington]=true;
        this->cities_map[City::Montreal][City::NewYork]=true;
        this->disease[City::Moscow]=0;
        this->cities_colors[City::Moscow]=Color::Black;
        this->station[City::Moscow]=0;
        this->cities_map[City::Moscow][City::StPetersburg]=true;
        this->cities_map[City::Moscow][City::Istanbul]=true;
        this->cities_map[City::Moscow][City::Tehran]=true;
        this->disease[City::Mumbai]=0;
        this->cities_colors[City::Mumbai]=Color::Black;
        this->station[City::Mumbai]=0;
        this->cities_map[City::Mumbai][City::Karachi]=true;
        this->cities_map[City::Mumbai][City::Delhi]=true;
        this->cities_map[City::Mumbai][City::Chennai]=true;
        this->disease[City::NewYork]=0;
        this->cities_colors[City::NewYork]=Color::Blue;
        this->station[City::NewYork]=0;
        this->cities_map[City::NewYork][City::Montreal]=true;
        this->cities_map[City::NewYork][City::Washington]=true;
        this->cities_map[City::NewYork][City::London]=true;
        this->cities_map[City::NewYork][City::Madrid]=true;  
        this->disease[City::Osaka]=0;
        this->cities_colors[City::Osaka]=Color::Red;
        this->station[City::Osaka]=0;
        this->cities_map[City::Osaka][City::Taipei]=true;
        this->cities_map[City::Osaka][City::Tokyo]=true;
        this->disease[City::Paris]=0;
        this->cities_colors[City::Paris]=Color::Blue;
        this->station[City::Paris]=0;
        this->cities_map[City::Paris][City::Algiers]=true;
        this->cities_map[City::Paris][City::Essen]=true;
        this->cities_map[City::Paris][City::Madrid]=true;
        this->cities_map[City::Paris][City::Milan]=true;
        this->cities_map[City::Paris][City::London]=true;
        this->disease[City::Riyadh]=0;
        this->cities_colors[City::Riyadh]=Color::Black;
        this->station[City::Riyadh]=0;
        this->cities_map[City::Riyadh][City::Baghdad]=true;
        this->cities_map[City::Riyadh][City::Cairo]=true;
        this->cities_map[City::Riyadh][City::Karachi]=true;
        this->disease[City::SanFrancisco]=0;
        this->cities_colors[City::SanFrancisco]=Color::Blue;
        this->station[City::SanFrancisco]=0;
        this->cities_map[City::SanFrancisco][City::LosAngeles]=true;
        this->cities_map[City::SanFrancisco][City::Chicago]=true;
        this->cities_map[City::SanFrancisco][City::Tokyo]=true;
        this->cities_map[City::SanFrancisco][City::Manila]=true;
        this->disease[City::Santiago]=0;
        this->cities_colors[City::Santiago]=Color::Yellow;
        this->station[City::Santiago]=0;
        this->cities_map[City::Santiago][City::Lima]=true;
        this->disease[City::SaoPaulo]=0;
        this->cities_colors[City::SaoPaulo]=Color::Yellow;
        this->station[City::SaoPaulo]=0;
        this->cities_map[City::SaoPaulo][City::Bogota]=true;
        this->cities_map[City::SaoPaulo][City::BuenosAires]=true;
        this->cities_map[City::SaoPaulo][City::Lagos]=true;
        this->cities_map[City::SaoPaulo][City::Madrid]=true;
        this->disease[City::Seoul]=0;
        this->cities_colors[City::Seoul]=Color::Red;
        this->station[City::Seoul]=0;
        this->cities_map[City::Seoul][City::Beijing]=true;
        this->cities_map[City::Seoul][City::Shanghai]=true;
        this->cities_map[City::Seoul][City::Tokyo]=true;
        this->disease[City::Shanghai]=0;
        this->cities_colors[City::Shanghai]=Color::Red;
        this->station[City::Shanghai]=0;
        this->cities_map[City::Shanghai][City::Beijing]=true;
        this->cities_map[City::Shanghai][City::HongKong]=true;
        this->cities_map[City::Shanghai][City::Taipei]=true;
        this->cities_map[City::Shanghai][City::Seoul]=true;
        this->cities_map[City::Shanghai][City::Tokyo]=true;
        this->disease[City::StPetersburg]=0;
        this->cities_colors[City::StPetersburg]=Color::Blue;
        this->station[City::StPetersburg]=0;
        this->cities_map[City::StPetersburg][City::Essen]=true;
        this->cities_map[City::StPetersburg][City::Istanbul]=true;
        this->cities_map[City::StPetersburg][City::Moscow]=true;
        this->disease[City::Sydney]=0;
        this->cities_colors[City::Sydney]=Color::Red;
        this->station[City::Sydney]=0;
        this->cities_map[City::Sydney][City::Jakarta]=true;
        this->cities_map[City::Sydney][City::Manila]=true;
        this->cities_map[City::Sydney][City::LosAngeles]=true;
        this->disease[City::Taipei]=0;
        this->cities_colors[City::Taipei]=Color::Red;
        this->station[City::Taipei]=0;
        this->cities_map[City::Taipei][City::Shanghai]=true;
        this->cities_map[City::Taipei][City::HongKong]=true;
        this->cities_map[City::Taipei][City::Osaka]=true;
        this->cities_map[City::Taipei][City::Manila]=true;
        this->disease[City::Tehran]=0;
        this->cities_colors[City::Tehran]=Color::Black;
        this->station[City::Tehran]=0;
        this->cities_map[City::Tehran][City::Baghdad]=true;
        this->cities_map[City::Tehran][City::Moscow]=true;
        this->cities_map[City::Tehran][City::Karachi]=true;
        this->cities_map[City::Tehran][City::Delhi]=true;    
        this->disease[City::Tokyo]=0;
        this->cities_colors[City::Tokyo]=Color::Red;
        this->station[City::Tokyo]=0;
        this->cities_map[City::Tokyo][City::Seoul]=true;
        this->cities_map[City::Tokyo][City::Shanghai]=true;
        this->cities_map[City::Tokyo][City::Osaka]=true;
        this->cities_map[City::Tokyo][City::SanFrancisco]=true;
        this->disease[City::Washington]=0;
        this->cities_colors[City::Washington]=Color::Blue;
        this->station[City::Washington]=0;
        this->cities_map[City::Washington][City::Atlanta]=true;
        this->cities_map[City::Washington][City::NewYork]=true;
        this->cities_map[City::Washington][City::Montreal]=true;
        this->cities_map[City::Washington][City::Miami]=true;
    }

};

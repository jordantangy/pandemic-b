#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>
#include <string>
#include <map>
using namespace std;
#define CARDS_TO_THROW 5

namespace pandemic {

    class Player {

        protected:
            Board& board;
            set<City> cards;
            City actual; 
            string Role;
            

            
        public:
            Player(Board& b, City city, string r = "Player"): board(b), actual(city), Role(r){}

            Player& take_card(City city);
            Player& drive(City city);
            virtual Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            string& retrieve_table(City city);
            virtual Player& build();
            virtual Player& discover_cure(Color city);
            virtual Player& treat(City city);
            static Color getColor(City city);
            bool is_connected(const string& city1,const string& city2);
            string role(){
                return Role;
            }
            void check_medic(City actual,const string& role);
           
    };

}

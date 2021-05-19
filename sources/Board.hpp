#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

namespace pandemic {

    class Board {
        public:
        static std::map<City, set<City>> connections;
        map<City, int> pandemic_level;
        set<Color> discovered_cures;
        vector<City> research_centers;

        public:
            Board() {}
            int& operator[](City city);
            bool is_clean();
            bool contains_researchCenter(City city);
            void add_curedCity(Color city);
            bool discovered(City city);
            void remove_cures();
            friend ostream& operator<<(ostream& os, const Board& b);
    };
}

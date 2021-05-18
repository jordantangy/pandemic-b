#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Scientist: public Player {
        int n;

        public:
            Scientist(Board& b, City city, int num): Player(b, city, "Scientist"), n(num) {}
            Player& discover_cure(Color city) override;
    };
    
}
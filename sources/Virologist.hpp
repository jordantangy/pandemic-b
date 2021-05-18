#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Virologist: public Player {

        public:
            Virologist(Board& b, City city): Player(b, city, "Virologist") {}
            Player& treat(City city) override;
    };

}
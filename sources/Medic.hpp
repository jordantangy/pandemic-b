#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {

        public:
            Medic(Board& b, City city): Player(b, city, "Medic") {}
            Player& treat(City city) override;
    };
    
}
#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class FieldDoctor: public Player {

        public:
            FieldDoctor(Board& b, City city): Player(b, city, "FieldDoctor") {}
            Player& treat(City city) override;
    };

}
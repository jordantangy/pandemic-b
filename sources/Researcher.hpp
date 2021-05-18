#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Researcher: public Player {

        public:
            Researcher(Board& b, City city): Player(b, city, "Researcher") {}
            Player& discover_cure(Color city) override;
    };

}
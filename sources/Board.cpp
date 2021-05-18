#include "Board.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

int& Board::operator[](City city) {
    return pandemic_level[city];
}

bool Board::is_clean() {
    for(auto& pair: pandemic_level) {
        if(pair.second > 0) {
            return false;
        }
    }
    return true;
}


bool Board::contains_researchCenter(City city) {
    for(auto r : research_centers){
        if(r == city){
            return true;
        }
    }
    return false;
}

void Board::add_curedCity(Color city) {
    discovered_cures.insert(city);
}

bool Board::discovered(City city) {
    return (bool)discovered_cures.count(Player::getColor(city));
}

void Board::remove_cures() {
    discovered_cures.clear();
}


std::ostream& pandemic::operator<<(std::ostream& os, const Board& b) {
    return os;
}

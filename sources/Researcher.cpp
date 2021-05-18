#include "Researcher.hpp"

using namespace std;
using namespace pandemic;


Player& Researcher::discover_cure(Color city){
    int counter = 0;
    for(auto& c: cards){
        if(Player::getColor(c) == city) {
            counter++;
        }
    }
    if(counter < CARDS_TO_THROW){
        throw std::invalid_argument{"Not enough cards"};
    }
    counter = 1;
    for(auto it = cards.begin(); it != cards.end(); counter++){
        if(counter == CARDS_TO_THROW) {
            break;
        }
        if(Player::getColor(*it) == city) {
            it = cards.erase(it);
        }
        else {
            ++it;
        }
    }
    board.add_curedCity(city);
    return *this;
}

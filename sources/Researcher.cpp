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
        throw invalid_argument{"Not enough cards"};
    }
    counter = 1;
    auto begin = cards.begin();
    auto end = cards.end();
    for(auto it = begin; it != end; counter++){
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

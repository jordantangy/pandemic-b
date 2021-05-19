#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player& Scientist::discover_cure(Color city) {
    int counter = 0;
    if(board.contains_researchCenter(actual)){
        for(auto& c : cards){
            if(Player::getColor(c) == city) {
            counter++;
            }
        }
        if(counter < n){
            throw invalid_argument{"error" };
        }
    }
    else{
        throw invalid_argument{"There is no research center in this city "};
    }
    counter = 1;
    auto begin = cards.begin();
    auto end = cards.end();
    for(auto it = begin; it != end; it++){
        if(counter == n) {
            break;
        }
        if(Player::getColor(*it) == city) {
            it = cards.erase(it);
            counter++;
        }
    }
    board.add_curedCity(city);
    return *this;
}
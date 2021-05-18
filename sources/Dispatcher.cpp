#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City city){
    if(actual == city){
        throw invalid_argument("You cannot fly from your current city to itself");
    }
    if(board.contains_researchCenter(actual)) {
        actual = city;
    }
    else {
        return Player::fly_direct(city);
    }
    return *this;
}
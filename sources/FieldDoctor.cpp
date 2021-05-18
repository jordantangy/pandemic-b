#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;


Player& FieldDoctor::treat(City city){
    if (actual != city){
        if(!Player::is_connected(Player::retrieve_table(actual),Player::retrieve_table(city))){
            throw invalid_argument{"No connection between the cities"};
        }
    }
    if (board.pandemic_level[city] == 0) {
        throw invalid_argument{"Level already at 0"};
    }
    if (board.discovered(city)) {
        board.pandemic_level[city] = 0;
    }
    else {
        board.pandemic_level[city]--;
    }
    return *this;
}
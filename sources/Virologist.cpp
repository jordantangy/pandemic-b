#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player& Virologist::treat(City city){
    if (actual != city) {
        if(cards.count(city)) {
            cards.erase(city);
        }
        else{
            throw invalid_argument{"This player doesn't have this card"};
        }
    }
    if (board.pandemic_level[city] == 0) {
        throw invalid_argument{"Level already at 0 "};
    }
    if (board.discovered(city)) {
        board.pandemic_level[city] = 0;
        return *this;
    }
    board.pandemic_level[city]--;
    return *this;
}
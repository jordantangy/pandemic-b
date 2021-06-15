#include "Medic.hpp"

using namespace std;
using namespace pandemic;

//reinitialize disease cubes to 0
Player& Medic::treat(City city) {
    if (actual != city) {
        throw invalid_argument{"This player is not in the right city"};
    }
    if (board.pandemic_level[city] == 0) {
        throw invalid_argument{"Level already at 0 "};
    }
    board.pandemic_level[city] = 0;
    return *this;
}

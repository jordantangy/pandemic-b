#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;


Player& OperationsExpert::build(){
    board.research_centers.push_back(actual);
    return *this;
}
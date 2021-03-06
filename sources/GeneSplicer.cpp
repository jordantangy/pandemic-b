#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;


Player& GeneSplicer::discover_cure(Color city){

    if(cards.size() < CARDS_TO_THROW){
        throw invalid_argument{"Not enough cards"};
    }
    int counter = 0;
    if(board.contains_researchCenter(actual)){
    counter = 1;
    auto begin = cards.begin();
    auto end = cards.end();
    for(auto it = begin; it != end ; it++){
        it = cards.erase(it);
        counter++;
        if(counter == CARDS_TO_THROW) {
            break;
        }
      }
    }
    else{
        throw invalid_argument("error");
    }
    board.add_curedCity(city);
    return *this;
}
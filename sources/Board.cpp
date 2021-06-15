#include "Board.hpp"
#include "Player.hpp"


using namespace std;
using namespace pandemic;

int& Board::operator[](City city) {
    return pandemic_level[city];
}

bool Board::is_clean() {
    for(auto& pair: pandemic_level) {
        if(pair.second != 0) {
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


ostream& pandemic::operator<<(ostream& os,const Board& b){
    os << "\n\tDisease level in each city: \n";
        for(const auto& it : b.pandemic_level){
                os << "\t\t" << strCities.at(it.first) << " --> " << it.second << endl;
        }
        os << "\n\tColor of Cures that were found 'till now: \n";
        for(const auto& it2 : b.discovered_cures){
                os << "\t\tColor of cure: " << stringOfColor.at(it2)<< endl;
        }
        os << "\n\tReaserch Stations that were built 'till now: \n";
        for(const auto& it3 : b.research_centers){
                os << "\t\tReaserch Station is in: " << strCities.at(it3) << ". " <<endl;
        }
        os << "\n---------------------------------------------------------" << "\n" <<endl;
        return os; 
}

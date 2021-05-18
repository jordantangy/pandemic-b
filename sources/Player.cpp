#include "Player.hpp"
#include <fstream>
#include <string>

using namespace std;
using namespace pandemic;


 static map<City,string> table  = {
                                    {City::Algiers,"Algiers"},{City::Atlanta,"Atlanta"} , {City::Baghdad,"Baghdad"} ,
                                    {City::Bangkok,"Bangkok"} ,{City::Beijing,"Beijing"} ,{City::Bogota,"Bogota"} ,{
                                    City::BuenosAires,"BuenosAires"} ,{City::Cairo,"Cairo"} , {City::Chennai,"Chennai"} ,
                                    {City::Chicago,"Chicago"} ,{City::Delhi,"Delhi"} ,{City::Essen,"Essen"} ,
                                    {City::HoChiMinhCity,"HoChiMinhCity"} ,{City::HongKong,"HongKong"} ,{City::Istanbul,"Istanbul"} ,
                                    {City::Jakarta,"Jakarta"} ,{City::Johannesburg,"Johannesburg"} ,{City::Karachi,"Karachi"} ,
                                    {City::Khartoum,"Khartoum"} ,{City::Kinshasa,"Kinshasa"} ,{City::Kolkata,"Kolkata"} ,
                                    {City::Lagos,"Lagos"} ,{City::Lima,"Lima"} ,{City::London,"London"} ,
                                    {City::LosAngeles,"LosAngeles"} ,{City::Madrid,"Madrid"} ,{City::Manila,"Manila"} ,
                                    {City::MexicoCity,"MexicoCity"} ,{City::Miami,"Miami"} ,{City::Milan,"Milan"} ,
                                    {City::Montreal,"Montreal"} ,{City::Moscow,"Moscow"} ,{City::Mumbai,"Mumbai"} ,
                                    {City::NewYork,"NewYork"} ,{City::Osaka,"Osaka"} ,{City::Paris,"Paris"} ,
                                    {City::Riyadh,"Riyadh"} ,{City::SanFrancisco,"SanFrancisco"} ,{City::Santiago,"Santiago"} ,
                                    {City::SaoPaulo,"SaoPaulo"} ,{City::Seoul,"Seoul"} ,{City::Shanghai,"Shanghai"} ,
                                    {City::StPetersburg,"StPetersburg"} ,{City::Sydney,"Sydney"} ,{City::Taipei,"Taipei"} ,
                                    {City::Tehran,"Tehran"} ,{City::Tokyo,"Tokyo"} ,{City::Washington,"Washington"}
                                };

static map<City, Color> colors =  {
                                    {City::Algiers, Color::Black },{ City::Atlanta, Color::Blue },{ City::Baghdad, Color::Black },
                                    {City::Bangkok, Color::Red },{ City::Beijing, Color::Red },{ City::Bogota, Color::Yellow },
                                    {City::BuenosAires, Color::Yellow },{ City::Cairo, Color::Black },{ City::Chennai, Color::Black },
                                    {City::Chicago, Color::Blue },{ City::Delhi, Color::Black },{ City::Essen, Color::Blue },
                                    {City::HoChiMinhCity, Color::Red },{ City::HongKong, Color::Red },{ City::Istanbul, Color::Black },
                                    {City::Jakarta, Color::Red },{ City::Johannesburg, Color::Yellow },{ City::Karachi, Color::Black },
                                    {City::Khartoum, Color::Yellow },{ City::Kinshasa, Color::Yellow },{ City::Kolkata, Color::Black },
                                    {City::Lagos, Color::Yellow },{ City::Lima, Color::Yellow },{ City::London, Color::Blue },
                                    {City::LosAngeles, Color::Yellow },{ City::Madrid, Color::Blue },{ City::Manila, Color::Red },
                                    {City::MexicoCity, Color::Yellow },{ City::Miami, Color::Yellow },{ City::Milan, Color::Blue },
                                    {City::Montreal, Color::Blue },{ City::Moscow, Color::Black },{ City::Mumbai, Color::Black },
                                    {City::NewYork, Color::Blue },{ City::Osaka, Color::Red },{ City::Paris, Color::Blue },
                                    {City::Riyadh, Color::Black },{ City::SanFrancisco, Color::Blue },{ City::Santiago, Color::Yellow },
                                    {City::SaoPaulo, Color::Yellow },{ City::Seoul, Color::Red },{ City::Shanghai, Color::Red },
                                    {City::StPetersburg, Color::Blue },{ City::Sydney, Color::Red },{ City::Taipei, Color::Red },
                                    {City::Tehran, Color::Black },{ City::Tokyo, Color::Red },{City::Washington, Color::Blue}
                                   };


bool Player::is_connected(const string& city1,const string& city2){
    if (city1 == "Manila" && city2 == "HongKong") {return true;}
    string s;
    string delimiter = " ";
    vector<string> v;
    ifstream cities_connections("cities_map.txt");
    while(getline (cities_connections,s)){
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            v.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        if(v[0] != city1){
            v.clear();
            continue;
        }
        else{
            for (size_t i = 1; i < v.size(); i++)
            {   
                if(v[i] == city2){
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

Player& Player::take_card(City city){
    cards.insert(city);
    return *this;
    }

void Player::check_medic(City actual,const std::string& role){
    if(role == "Medic"){
        if(board.discovered(actual)) {
        board[actual] = 0;    
        }
    }
}

Player& Player::drive(City city){
    if(Player::is_connected(table[actual], table[city])){
        actual = city;
    }
    else{
        throw std::invalid_argument{"The cities are not connected"};
    }
    check_medic(actual,this->Role);
    return *this;
}

Player& Player::fly_direct(City city){

    if(cards.count(city)){
        cards.erase(city);
        actual = city;
    }
    else{
         throw std::invalid_argument{"The player does not have this card"};
    }
    check_medic(actual,this->Role);
    return *this;
}

Player& Player::fly_charter(City city){
    if(cards.count(actual)){
        cards.erase(actual);
        actual = city;
    }
    else{
        throw std::invalid_argument{"The player does not have this card"};
    }
    check_medic(actual,this->Role);
    return *this;
}

Player& Player::fly_shuttle(City city){
    if(actual == city){
        throw std::invalid_argument{"Can't traver to a city to itself"};
    }
    if(board.contains_researchCenter(actual) && board.contains_researchCenter(city)){
        actual = city;
        check_medic(actual,this->Role);
    }
    else{
        throw std::invalid_argument{"No research center in both cities"};
    }
    return *this;
}

Player& Player::build(){
    if(cards.count(actual)){
        board.research_centers.push_back(actual);
        cards.erase(actual);
    }
    else{
         throw std::invalid_argument{"Cant build research station! the player dont have a "};
    }
    return *this;
}

Player& Player::discover_cure(Color city){

    int counter = 0;
    if(board.contains_researchCenter(actual)){
        for(auto c : cards){
            if(colors[c] == city) {
                counter++;
            }
        }
        if(counter < CARDS_TO_THROW ){
            throw std::invalid_argument{"illegal action: you only have  "};
        }
        counter = 1;
        for(auto it = cards.begin(); it != cards.end(); it++){
        if(colors[*it] == city) {
            it = cards.erase(it);
            counter++;
            if(counter == CARDS_TO_THROW){
                break;
            }
        }
        else {
            ++it;
        }
    }    
    board.add_curedCity(city); 
    }

    else{
        throw std::invalid_argument{"error"};
    }
    return *this;
}

Player& Player::treat(City city){
    if (actual != city) {
        throw std::invalid_argument{"You're not in the city"};
    }
    else if (board[city] == 0) {
        throw std::invalid_argument{"The level is already at 0"};
    }
    else if (board.discovered(city)) {
        board[city] = 0;
    }
    else {
        board.pandemic_level[city]--;
    }
    return *this;
}

string& Player::retrieve_table(City city){
    string& ans = table[city];
    return ans;

}

Color Player::getColor(City city){
    return colors[city];
}
/* include main classes */
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
/* include special skills players */
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
using namespace pandemic;
#include <iostream>
#include <stdexcept>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

const map<City, vector<City>> citiesOnBoard {
    { City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo } },
    { City::Atlanta, {City::Chicago, City::Miami, City::Washington } },
    { City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi } },
    { City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong } },
    { City::Beijing, {City::Shanghai, City::Seoul } },
    { City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires } },
    { City::BuenosAires, {City::Bogota, City::SaoPaulo } },
    { City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh } },
    { City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta } },
    { City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal } },
    { City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata } },
    { City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg } },
    { City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila } },
    { City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei } },
    { City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow } },
    { City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney } },
    { City::Johannesburg, {City::Kinshasa, City::Khartoum } },
    { City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi } },
    { City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg } },
    { City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg } },
    { City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong } },
    { City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa } },
    { City::Lima, {City::MexicoCity, City::Bogota, City::Santiago } },
    { City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris } },
    { City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney } },
    { City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers } },
    { City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney } },
    { City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota } },
    { City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota } },
    { City::Milan, {City::Essen, City::Paris, City::Istanbul } },
    { City::Montreal, {City::Chicago, City::Washington, City::NewYork } },
    { City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran } },
    { City::Mumbai, {City::Karachi, City::Delhi, City::Chennai } },
    { City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid } },
    { City::Osaka, {City::Taipei, City::Tokyo } },
    { City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London } },
    { City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi } },
    { City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila } },
    { City::Santiago, {City::Lima } },
    { City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid } },
    { City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo } },
    { City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo } },
    { City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow } },
    { City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles } },
    { City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila } },
    { City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi } },
    { City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco } },
    { City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami } }
};

City random_city(){
    size_t t = (size_t)rand() % 47;
    int i = 0;
    for(const auto& city: citiesOnBoard) {
        if(i == t) {
            return city.first;
        }
        i++;
    }
    return City::Algiers;
}

int main() {

    pandemic::Board board;  // Initialize an empty board (with 0 disease cubes in any city).

    std::cout << "-------------------WELCOME TO The Game-------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "--------------Initialize an empty board---------------" << std::endl;
    std::cout << std::endl;
    std::cout << board << std::endl;

    std::cout << "-----------------After Adding disease cubes------------------" << std::endl;
    std::cout << std::endl;

	board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
	board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
	board[City::Chicago] = 1;  // put 1 blue disease cube in Chicago
    board[City::Washington] = 2;      
    std::cout << board << std::endl;

	pandemic::OperationsExpert player {board, City::Atlanta};  // initialize an "operations expert" player on the given board, in Atlanta.
	player.take_card(City::Johannesburg)
	 .take_card(City::Khartoum)
	 .take_card(City::SaoPaulo)
	 .take_card(City::BuenosAires)
	 .take_card(City::HoChiMinhCity);


	/* build action */

	player.build();  // legal action: you build a research station in Atlanta.
		// NOTE: you do not have the Atlanta card, so for other roles this would throw an exception.
		//       But for the OperationsExpert it is legal, since he may build a research station without a card.


	/* drive action */

	player.drive(City::Washington);  // drive from Atlanta to a connected city.
	player.build();
    player.drive(City::Montreal);  // drive from Atlanta to a connected city.
    player.build();

    std::cout << "-----------------After bulding a research station------------------" << std::endl;
    std::cout << std::endl;

	std::cout << board << std::endl;

    player.drive(City::Washington);
    player.treat(City::Washington);


    cout << "-----------------After Washington was treated------------------" << endl;
    std::cout << std::endl;
    std::cout << board << std::endl;

    pandemic::Scientist player2 {board, City::Atlanta, 4}; 

    player2.take_card(City::Miami)
	 .take_card(City::Bogota)
	 .take_card(City::Lima)
     .take_card(City::Kinshasa);

    player2.discover_cure(Yellow);

    cout << "-----------------After Yellow cure was found------------------" << endl;
    std::cout << std::endl;
    std::cout << board << std::endl;

    player2.take_card(City::HoChiMinhCity)
	 .take_card(City::HongKong)
	 .take_card(City::Jakarta)
     .take_card(City::Sydney);

    player2.discover_cure(Red);

    cout << "-----------------After Red cure was found------------------" << endl;
    std::cout << std::endl;
    std::cout << board << std::endl;
}


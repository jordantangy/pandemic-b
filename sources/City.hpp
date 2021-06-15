#pragma once
#include <map>
#include <string>
using namespace std;

enum City
{
    Algiers,Atlanta,Baghdad,Bangkok,Beijing,Bogota,BuenosAires,Cairo,Chennai,Chicago,Delhi,Essen,HoChiMinhCity,HongKong,
    Istanbul,Jakarta,Johannesburg,Karachi,Khartoum,Kinshasa,Kolkata,Lagos,Lima,London,LosAngeles,Madrid,Manila,MexicoCity,Miami,
    Milan,Montreal,Moscow,Mumbai,NewYork,Osaka,Paris,Riyadh,SanFrancisco,Santiago,SaoPaulo,Seoul,Shanghai,StPetersburg,Sydney,Taipei,
    Tehran,Tokyo,Washington
};

 static map<City,string> strCities  = {
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


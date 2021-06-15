#pragma once
#include "City.hpp"
#include <map>
#include <string>
using namespace std;

enum Color{
    Yellow,
    Red,
    Blue,
    Black
};

    static map<Color, string> stringOfColor{
        {Yellow, "Yellow"},
        {Red, "Red"},
        {Blue, "Blue"}, 
        {Black, "Black"}
    };


#include "game.h"
#include <cstring>
#include <iostream>

std::string Game::to_string(/*std::string platform, char maturity_rating*/)
{
    std::string info;
    info =  "platform: " + this->platform + '\n' + "maturity_rating: " + this->maturity_rating;
    return info;
}

void Game::check_values(std::string platform, char maturity_rating)
{
    if(!platform.length()) throw "No platform\n";
    if(maturity_rating != 'E' || maturity_rating != 'M'|| maturity_rating != 'P') throw "Rating should be E, M or M\n";
}

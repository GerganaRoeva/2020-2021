#include "game.h"
#include <cstring>
#include <iostream>

std::string Game::to_string(std::string platform, char maturity_rating)
{
    std::string info;
    info =  "platform: " + platform + '\n' + "maturity_rating: " + maturity_rating + '\n';
    return info;
}

void Game::check_values(std::string platform, char maturity_rating)
{
    if(!platform.length()) throw "some string";
    if(maturity_rating != 'E' || maturity_rating != 'M'|| maturity_rating != 'P') throw "some string";
}

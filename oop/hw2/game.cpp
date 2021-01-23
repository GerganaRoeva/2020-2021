#include "game.h"
#include <cstring>
#include <iostream>

void Game::to_string(std::string platform, char maturity_rating)
{
    std::cout << "platform: " << platform << std::endl;
    std::cout << "maturity_rating: " << maturity_rating << std::endl;    
}

void Game::check_values(std::string platform, char maturity_rating)
{
    if(!platform.length()) throw "some string";
    if(maturity_rating != 'E' || maturity_rating != 'M'|| maturity_rating != 'P') throw "some string";
}
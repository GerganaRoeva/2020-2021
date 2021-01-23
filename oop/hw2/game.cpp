#include "game.h"
#include <cstring>
#include <iostream>

std::string Game::to_string()
{
    std::string info;
    info =  "name: " + name + '\n' +
            "size: " + std::to_string(size) + '\n' +
            "uploader: " + uploader + '\n' +
            "number_downloads: " + std::to_string(number_downloads) + '\n' +
            "platform: " + platform + '\n' +
            "maturity_rating: " + maturity_rating;
    return info;
}

// void Game::check_values(std::string name, int size, std::string uploader, int number_downloads, std::string platform, char maturity_rating)
// {
//     if(!platform.length()) throw "No platform\n";
//     if(maturity_rating != 'E' || maturity_rating != 'M'|| maturity_rating != 'P') throw "Rating should be E, M or M\n";
// }

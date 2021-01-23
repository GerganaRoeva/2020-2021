#include "movie.h"
#include <cstring>
#include <iostream>

std::string Movie::to_string(std::string director, int duration, std::string language)
{
    std::string info;
    info =  "director: " + director + '\n' + "duration: " + std::to_string(duration) + '\n' + "language: " + language + '\n';
    return info;     
}

void Movie::check_values(std::string director, int duration, std::string language)
{
    if(!director.length() || !language.length()) throw "some string";
    if(duration < 0) throw "some string";
}

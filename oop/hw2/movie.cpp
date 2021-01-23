#include "movie.h"
#include <cstring>
#include <iostream>

std::string Movie::to_string(std::string director, int duration, std::string language)
{
    std::string info;
    info =  "director: " + director + '\n' + "duration: " + std::to_string(duration) + '\n' + "language: " + language;
    return info;     
}

void Movie::check_values(std::string director, int duration, std::string language)
{
    if(!director.length() || !language.length()) throw "No director\n";
    if(!language.length()) throw "No lenght\n";
    if(duration < 0) throw "No duration\n";
}

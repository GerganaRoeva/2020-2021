#include "movie.h"
#include <cstring>
#include <iostream>

void Movie::to_string(std::string director, int duration, std::string language)
{
    std::cout << "director: " << director << std::endl;
    std::cout << "duration: " << duration << std::endl;
    std::cout << "language: " << language << std::endl;
    
}

void Movie::check_values(std::string director, int duration, std::string language)
{
    if(!director.length() || !language.length()) throw "some string";
    if(duration < 0) throw "some string";
}
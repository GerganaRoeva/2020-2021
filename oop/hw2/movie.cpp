#include "movie.h"
#include <cstring>
#include <iostream>

std::string Movie::to_string()
{
    std::string info;
    info =  "name: " + name + '\n' +
            "size: " + std::to_string(size) + '\n' +
            "uploader: " + uploader + '\n' +
            "number_downloads: " + std::to_string(number_downloads) + '\n' +
            "director: " + director + '\n' +
            "duration: " + std::to_string(duration) + '\n' + 
            "language: " + language;
    return info;     
}

// void Movie::check_values(std::string name, int size, std::string uploader, int number_downloads, std::string director, int duration, std::string language)
// {
//     if(!director.length() || !language.length()) throw "No director\n";
//     if(!language.length()) throw "No lenght\n";
//     if(duration < 0) throw "No duration\n";
// }

#ifndef MOVIE_H
#define MOVIE_H
#include "torent.h"
#include <string>

class Movie : public Torent
{
private:
    std::string director;
    int duration;
    std::string language;
public:
    Movie(std::string name, int size, std::string uploader, int number_downloads, std::string director, int duration, std::string language):
        Torent(name, size, uploader, number_downloads), director(director), duration(duration), language(language)
    {
        if(!name.length()) throw "No name";
        if(size < 0) throw "Invalid size";
        if(!uploader.length()) throw "No uploader";
        if(number_downloads < 0) throw "Invalid number_downloads";
        if(!director.length()) throw "No director";
        if(!language.length()) throw "No lenght";
        if(duration < 0) throw "No duration";
    }
    Movie(const Movie& other): director(other.director), duration(other.duration), language(other.language){}

    std::string to_string();
    // void check_values(std::string name, int size, std::string uploader, int number_downloads, std::string director, int duration, std::string language);

    // std::string get_name() return name;
    std::string get_director()
    {
        return director;
    }

    ~Movie(){}
};

#endif

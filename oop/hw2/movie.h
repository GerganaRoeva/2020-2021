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
    Movie(std::string director, int duration, std::string language): director(director), duration(duration), language(language){}
    Movie(const Movie& other): director(other.director), duration(other.duration), language(other.language){}

    void to_string(std::string director, int duration, std::string language);
    void check_values(std::string director, int duration, std::string language);

    ~Movie();
};

#endif

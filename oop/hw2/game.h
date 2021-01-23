#ifndef GAME_H
#define GAME_H
#include "torent.h"
#include <string>

class Game : public Torent
{
private:
    std::string platform;
    //rating maturity_rating;
    char maturity_rating;
public:
    Game(std::string name, int size, std::string uploader, int number_downloads, std::string platform, char maturity_rating):
        Torent(name, size, uploader, number_downloads), platform(platform), maturity_rating(maturity_rating)
    {
        if(!name.length()) throw "No name";
        if(size < 0) throw "Invalid size";
        if(!uploader.length()) throw "No uploader";
        if(number_downloads < 0) throw "Invalid number_downloads";
        if(!platform.length()) throw "No platform";
        if(maturity_rating != 'E' && maturity_rating != 'M' && maturity_rating != 'P') throw "Rating should be E, M or P";
    }

    Game(const Game& other): platform(other.platform), maturity_rating(other.maturity_rating) {}

    std::string to_string();
   // void check_values(std::string name, int size, std::string uploader, int number_downloads, std::string platform, char maturity_rating);

    char get_rating()
    {
        return maturity_rating;
    }

    ~Game(){}
};

#endif

#ifndef GAME_H
#define GAME_H
#include "torent.h"
#include <string>

//enum rating{E, M, P};

class Game : public Torent
{
private:
    std::string platform;
    //rating maturity_rating;
    char maturity_rating;
public:
    Game(std::string platform, char maturity_rating): platform(platform), maturity_rating(maturity_rating) {}
    Game(const Game& other): platform(other.platform), maturity_rating(other.maturity_rating) {}

    std::string to_string(std::string platform, char maturity_rating);
    void check_values(std::string platform, char maturity_rating);

    // std::string get_name()
    // { return name; }
    char get_rating()
    {
        return maturity_rating;
    }

    ~Game(){}
};

#endif

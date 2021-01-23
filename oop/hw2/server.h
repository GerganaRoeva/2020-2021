#ifndef SERVER_H
#define SERVER_H
#include <list>
#include <string>
#include "game.h"
#include "movie.h"
#include "software.h"

class Server
{
private:
    std::list<std::string> users;
    std::list<Game*> games;
    std::list<Movie*> movies;
    std::list<Software*> softwares;

public:
    Server(){}
    Server(std::list<Game*> games, std::list<Movie*> movies, std::list<Software*> softwares) :
        games(games), movies(movies), softwares(softwares) {}
    std::list<Torent*> search_all_by_name(std::list<Game*> games, std::list<Movie*> movies, std::list<Software*> softwares);
    std::list<Game*> search_game_rating(std::list<Game*> games);
    std::list<Movie*> search_movie_director(std::list<Movie*> movies);
    std::list<Software*> search_software_version(std::list<Software*> softwares);
    ~Server(){}
};

#endif

#include "server.h"
#include <iostream>

std::list<Torent*> Server::search_all_by_name(std::list<Game*> games, std::list<Movie*> movies, std::list<Software*> softwares)
{
    std::list<Torent*> results;
    std::string name;
    std::cout << "search: ";    
    std::cin >> name;
    for(auto it = games.begin(); it != games.end(); it++)
    {
        if ((**it).get_name() == name)
        {
            results.push_back(*it);
        }           
    }

    for(auto it = movies.begin(); it != movies.end(); it++)
    {
        if ((**it).get_name() == name)
        {
            results.push_back(*it);
        }           
    }

    for(auto it = softwares.begin(); it != softwares.end(); it++)
    {
        if ((*it)->get_name() == name)
        {
            results.push_back(*it);
        }           
    }

    if(results.size() == 0) throw "No match found\n";

    return results;
}

std::list<Game*> Server::search_game_rating(std::list<Game*> games)
{
    std::list<Game*> results;
    char rating;
    std::cout << "search raiting: ";
    std::cin >> rating;
    for(auto it = games.begin(); it != games.end(); it++)
    {
        if ((**it).get_rating() == rating)
        {
            results.push_back(*it);
        }           
    }

    if(results.size() == 0) throw "No match found\n";

    return results;
}

std::list<Movie*> Server::search_movie_director(std::list<Movie*> movies)
{
    std::list<Movie*> results;
    std::string director;
    std::cout << "search director: ";
    std::cin >> director;
    for(auto it = movies.begin(); it != movies.end(); it++)
    {
        if ((**it).get_director() == director)
        {
            results.push_back(*it);
        }           
    }

    if(results.size() == 0) throw "No match found\n";

    return results;
}

std::list<Software*> Server::search_software_version(std::list<Software*> softwares)
{
    std::list<Software*> results;
    std::string version;
    std::cout << "search version: ";
    std::cin >> version;

    std::string major;
    major.append(1,version[0]);
    for(int i = 1; version[i] != '.'; i++)
    {
        major += version[i];
    }

    for(auto it = softwares.begin(); it != softwares.end(); it++)
    {
        if (major == version)
        {
            results.push_back(*it);
        }           
    }

    if(results.size() == 0) throw "No match found\n";

    return results;
}
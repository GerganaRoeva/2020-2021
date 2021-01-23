#include <cstring>
#include <iostream>
#include <list>
#include <string>

//using namespace std;

class Torent
{
private:
    std::string name;
    int size;
    std::string uploader;
    int number_downloads;

public:
    Torent(){}
    // Torent(const Torent& other): name(other.name), size(other.size), uploader(other.uploader)/*, number_downloads(number_downloads)*/ {}
    Torent(std::string name, int size, std::string uploader, int number_downloads): name(name), size(size), uploader(uploader)/*, number_downloads(number_downloads)*/ {}
    std::string get_name()
    {
        return this->name;
    }
    ~Torent(){}
};

class Game : public Torent
{
private:
    std::string platform;
    //rating maturity_rating;
    char maturity_rating;
public:
    Game(std::string platform, char maturity_rating): platform(platform), maturity_rating(maturity_rating) {}
    Game(const Game& other): platform(other.platform), maturity_rating(other.maturity_rating) {}

    void to_string(std::string platform, char maturity_rating);
    void check_values(std::string platform, char maturity_rating);

    // std::string get_name()
    // { return name; }
    char get_rating()
    {
        return maturity_rating;
    }

    ~Game(){}
};

class Software : public Torent
{
private:
    std::string maker;
    std::string os;
    std::string version;
public:
    Software(std::string maker, std::string os, std::string version): maker(maker), os(os), version(version){}
    Software(const Software& other): maker(other.maker), os(other.os), version(other.version){}

    void to_string(std::string maker, std::string os, std::string version);
    void check_values(std::string maker, std::string os, std::string version);

    // std::string get_name() return name;
    std::string get_version()
    {
        return version;
    }

    std::string get_major_version(std::string version);

    ~Software(){}
};

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

    // std::string get_name() return name;
    std::string get_director()
    {
        return director;
    }

    ~Movie(){}
};

class Server
{
private:
    std::list<std::string> users;
    std::list<Game> games;
    std::list<Movie> movies;
    std::list<Software> softwares;

public:
    Server();
    Server(std::list<Game> games, std::list<Movie> movies, std::list<Software> softwares) :
        games(games), movies(movies), softwares(softwares) {}
    std::list<Torent> search_all_by_name(std::list<Game> games, std::list<Movie> movies, std::list<Software> softwares);
    std::list<Game> search_game_rating(std::list<Game> games);
    std::list<Movie> search_movie_director(std::list<Movie> movies);
    std::list<Software> search_software_version(std::list<Software> softwares);
    // std::string get_major_version(std::string version);
    ~Server(){}
};

void Game::to_string(std::string platform, char maturity_rating)
{
    std::cout << "platform: " << platform << std::endl;
    std::cout << "maturity_rating: " << maturity_rating << std::endl;    
}

void Game::check_values(std::string platform, char maturity_rating)
{
    if(!platform.length()) throw "some string";
    if(maturity_rating != 'E' || maturity_rating != 'M'|| maturity_rating != 'P') throw "some string";
}

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

void Software::to_string(std::string maker, std::string os, std::string version)
{
    std::cout << "maker: " << maker << std::endl;
    std::cout << "os: " << os << std::endl; 
    std::cout << "version: " << version << std::endl;    
}

void Software::check_values(std::string maker, std::string os, std::string version)
{
    if(!maker.length() || !os.length() || !version.length()) throw "some string";
    int len_of_ver = version.length() + 1;
    int count_dots = 0;
    for(int i = 0; i < len_of_ver; i++)
    {
        if(version[i] == '.') count_dots++;
        else if(version[i] < '0' && version[i] > '9')
            throw "some string";
    }
    if(count_dots != 2) throw "some string";
}

std::list<Torent> Server::search_all_by_name(std::list<Game> games, std::list<Movie> movies, std::list<Software> softwares)
{
    std::list<Torent> results;
    std::string name;
    std::cout << "search: ";    
    std::cin >> name;
    for(auto it = games.begin(); it != games.end(); it++)
    {
        if ((*it).get_name() == name)
        {
            results.push_back(*it);
        }           
    }

    for(auto it = movies.begin(); it != movies.end(); it++)
    {
        if ((*it).get_name() == name)
        {
            results.push_back(*it);
        }           
    }

    for(auto it = softwares.begin(); it != softwares.end(); it++)
    {
        if ((*it).get_name() == name)
        {
            results.push_back(*it);
        }           
    }

    return results;
}

std::list<Game> Server::search_game_rating(std::list<Game> games)
{
    std::list<Game> results;
    char rating;
    std::cout << "search raiting: ";
    std::cin >> rating;
    for(auto it = games.begin(); it != games.end(); it++)
    {
        if ((*it).get_rating() == rating)
        {
            results.push_back(*it);
        }           
    }

    return results;
}

std::list<Movie> Server::search_movie_director(std::list<Movie> movies)
{
    std::list<Movie> results;
    std::string director;
    std::cout << "search director: ";
    std::cin >> director;
    for(auto it = movies.begin(); it != movies.end(); it++)
    {
        if ((*it).get_director() == director)
        {
            results.push_back(*it);
        }           
    }
    return results;
}

// std::string get_major_version(std::string version)
// {
//     std::string major;
//     // major = version[0];
//     major.append(1,version[0]);
//     for(int i = 1; version[i] != '.'; i++)
//     {
//         major += version[i];
//     }
//     return major;
// }

std::list<Software> Server::search_software_version(std::list<Software> softwares)
{
    std::list<Software> results;
    std::string version;
    std::cout << "search version: ";
    std::cin >> version;

    std::string major;
    // major = version[0];
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
    return results;
}

int main()
{
    
    return 0;
}

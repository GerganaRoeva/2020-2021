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
    static int number_downloads;

public:
    Torent();
    Torent(std::string name, int size, std::string uploader): name(name), size(size), uploader(uploader) {}
    ~Torent();
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

    ~Game();
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


    ~Software();
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

    ~Movie();
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
    std::list<Torent> search_all(std::list<Game> games, std::list<Movie> movies, std::list<Software> softwares);
    std::list<Torent> search_game_rating(std::list<Game> games);
    std::list<Torent> search_movie_director(std::list<Movie> movies);
    std::list<Torent> search_software_version(std::list<Software> softwares);

    ~Server();
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

int main()
{
    
    return 0;
}

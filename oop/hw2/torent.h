#ifndef TORENT_H
#define TORENT_H
#include string

//using std::string;

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

#endif

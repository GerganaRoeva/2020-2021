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
    static int number_downloads;

public:
    Torent();
    Torent(std::string name, int size, std::string uploader): name(name), size(size), uploader(uploader) {}
    ~Torent();
};

#endif

#ifndef SOFTWARE_H
#define SOGTWARE_H
#include "torent.h"
#include <string>

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

#endif

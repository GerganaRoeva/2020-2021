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
    Software(std::string name, int size, std::string uploader, int number_downloads, std::string maker, std::string os, std::string version):
        Torent(name, size, uploader, number_downloads), maker(maker), os(os), version(version)
    {
        if(!name.length()) throw "No name";
        if(size < 0) throw "Invalid size";
        if(!uploader.length()) throw "No uploader";
        if(number_downloads < 0) throw "Invalid number_downloads";
        if(!maker.length()) throw "No maker";
        if(!os.length()) throw "No os";
        if(!version.length()) throw "No version";

        int len_of_ver = version.length() + 1;
        int count_dots = 0;
        for(int i = 0; i < len_of_ver; i++)
        {
            if(version[i] == '.') count_dots++;
            else if(version[i] < '0' && version[i] > '9')
                throw "Version should contain numbers";
        }
        if(count_dots != 2) throw "Version not valid";
    }
    Software(const Software& other): maker(other.maker), os(other.os), version(other.version){}

    std::string to_string();
    //void check_values(std::string name, int size, std::string uploader, int number_downloads, std::string maker, std::string os, std::string version);

    // std::string get_name() return name;
    std::string get_version()
    {
        return version;
    }

    std::string get_major_version(std::string version);

    ~Software(){}
};

#endif

#include "software.h"
#include <cstring>
#include <iostream>

std::string Software::to_string(std::string maker, std::string os, std::string version)
{
    std::string info;
    info =  "maker: " + maker + '\n' + "os: " + os + '\n' + "version: " + version + '\n';
    return info;   
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

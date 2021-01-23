#include "software.h"
#include <cstring>
#include <iostream>

void Software::to_string(std::string maker, std::string os, std::string version)
{
    std::cout << "maker: " << maker << std::endl;
    std::cout << "os: " << os << std::endl; 
    std::cout << "version: " << version << std::endl;    
}

void Software::check_values(std::string maker, std::string os, std::string version);
{
    if(!strlen(maker) || !strlen(os) || !strlen(version)) trow "some string";
    int len_of_ver = strlen(version) + 1;
    int count_dots = 0;
    for(int i = 0; i < len_of_ver; i++)
    {
        if(version[i] == '.') count_dots++;
        else if(version[i] < '0' && version[i] > '9')
            trow "some string";
    }
    if(count_dots != 2) trow "some string";
}
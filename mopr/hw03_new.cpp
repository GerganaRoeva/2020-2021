#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>

using namespace std;

// struct Point
// {
//     double x;
//     double y;
// };

void read(double arr[], const char * filename)
{
    ifstream info;
    info.open (filename);
    string num_string;
    double num;

    for(int i = 0; info.eof() == 0; i++)
    {
        getline(info, num_string, ' ');
        num = stod(num_string);
        arr[i] = num;
        // cout << arr[i] << endl;
    }
}

int board_coordinates_count(const char * filename)
{
    ifstream info;
    info.open (filename);
    string coordinates;

    getline(info, coordinates);
    int count = 0;
    int i = 0;
    while(coordinates[i] != '\0')
    {
        if(coordinates[i] == ' ') count++;
        i++;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    int num_coordinates = board_coordinates_count(argv[1]);
    // cout << num_coordinates;
    double arr[num_coordinates + 3];


    read(arr, argv[1]);
}
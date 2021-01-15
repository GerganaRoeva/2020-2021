#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point
{
    double x;
    double y;
};

void read(double arr[], const char * filename)
{
    ifstream info;
    info.open (filename);
    string num_string;
    double num;

    for (int i = 0; i < 3; i++)
    {
        getline(info, num_string, ' ');
        num = stod(num_string);

        int indx = 0;

        // while(num_string[indx] != '\0')
        // {
        //     if(num_string[indx] == ' ')



        // }

        arr[i] = num;
        cout << arr[i]<< endl;
    }

}

int main(int argc, char const *argv[])
{
    double arr[11]; 

    read(arr, argv[1]);
}
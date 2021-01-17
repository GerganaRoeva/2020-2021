#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>
#include <iomanip>

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

    for(int i = 0; info.eof() == 0; i++)
    {
        getline(info, num_string, ' ');
        num = stod(num_string);
        arr[i] = num;
        // cout << arr[i] << endl;
    }
}

void find_ab(double *arr, double x1, double y1, double x2, double y2)
{
    double A = (y1 - y2) / (x1 - x2);
    double B = y1 - A*x1;
    arr[0] = A;
    arr[1] = B;
    
    // return arr;                                                                                                                               
}

double find_len(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int check_file(double* arr_inf, int count_coordinates)
{
    double X_p = arr_inf[1];
    double Y_p = arr_inf[2];

    double AB[] = {0, 0};
    double BC[] = {0, 0};
    double CD[] = {0, 0};
    // double DA[] = {0, 0};

    if(count_coordinates == 4)
    {

    }
    if(count_coordinates == 8 && arr_inf[3] !=0 && arr_inf[4] != 0)
    {
        find_ab(AB, arr_inf[3], arr_inf[4], arr_inf[5], arr_inf[6]);
        find_ab(BC, arr_inf[5], arr_inf[6], arr_inf[7], arr_inf[8]);
        // cout << AB[0] << endl;
        if(AB[0]*BC[0] != -1) return 0;
        find_ab(CD, arr_inf[7], arr_inf[8], arr_inf[9], arr_inf[10]);
        if(BC[0]*CD[0] != -1) return 0;

        double AB_len = find_len(arr_inf[3], arr_inf[4], arr_inf[5], arr_inf[6]);
        double BC_len = find_len(arr_inf[5], arr_inf[6], arr_inf[7], arr_inf[8]);
        // cout << AB_len << endl;
        // cout << BC_len << endl;

        if(AB_len*2 != BC_len && BC_len*2 != AB_len) return 0;
        
        if(AB_len > BC_len) return AB_len;
        else return AB_len*2;
    }
}

int board_coordinates_count(const char * filename)
{
    ifstream info;
    info.open (filename);
    string coordinates;

    getline(info, coordinates);
    getline(info, coordinates);
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

int check_power(double pow)
{
    if(pow > 5 || pow < 2) return 0;
    return 1;
}

void input(double arr[])
{
    int i = 0;
    do{
        if(i > 0) cout << "Power must be between 2 and 5!\n";
        cout << "Power: ";
        cin >> arr[0];
        i++;
    }while(!check_power(arr[0]));

    cout << "X of direction: ";
    cin >> arr[1];
    cout << "Y of direction: ";
    cin >> arr[2];
}

Point next_pos(double* input, double crr_x, double crr_y)
{
    int nextx = (input[1]-crr_x)*input[0] + crr_x;
    int nexty = (input[2]-crr_y)*input[0] + crr_y;

    Point p;
    p.x = nextx;
    p.y = nexty; 

    return p;
}



int main(int argc, char const *argv[])
{
    int num_coordinates = board_coordinates_count(argv[1]) + 1;
    // cout << num_coordinates;
    double from_file[num_coordinates + 3];
    double from_input[3];
    double big_side;
    read(from_file, argv[1]);
    while(1)
    {
        big_side = check_file(from_file, num_coordinates);
        if(big_side == 0)
        {
            cout << "Starting point or board coordinates are not valid!\nChange from file.\n";
            return 0;
        }
        Point curr;
        curr.x = from_file[1];
        curr.y = from_file[2];
        input(from_input);

        Point dir;
        dir.x = from_input[1];
        dir.y = from_input[2];

        int i = 0;
        double len;
        
        do{
            len = find_len(curr.x, curr.y, dir.x, dir.y);
            if(i > 0){
                cout << endl;
                cout << "Vect lenght not correct!" << endl;
                cout << "Correct strat point or direction" << endl;
                cout << "New dir_x = ";
                cin >> dir.x;
                cout << "New dir_y = ";
                cin >> dir.y;
            }
            i++;
        }
        while(len < big_side/10 || len > (big_side*3)/10);

        Point new_point = next_pos(from_input, curr.x, curr.y);







    }
    
}
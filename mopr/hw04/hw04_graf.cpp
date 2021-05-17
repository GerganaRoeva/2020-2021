#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int count_points(const char * filename)
{
    ifstream info;
    info.open (filename);

    string num_string;
    int count_points = 0;

    while (info.eof() == 0)
    {
        getline(info, num_string);
        count_points++;
    }

    return count_points;
}

// void print(double A[][N])
// {
// 	for(int i = 0; i < N + 1; ++i)
// 	{
// 		for(int j = 0; j < N; ++j)
// 		{
// 			cout << A[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// }

// int shortest_start_fin()
// {
//     int st_point;
//     cout << "Starting point: ";
//     cin >> st_point;
//     return 0;
// }

void read_file(vector<vector<int> > matrix, const char * filename)
{
    ifstream info;
    info.open (filename);

    string num_string;
    int num;

    while (info.eof() == 0)
    {
        
        for (size_t i = 0; i < matrix.size(); i++)
        {
            getline(info, num_string, ' ');
            num = stoi(num_string);
            matrix[i].push_back(num);
            printf("%d ", num);
        }
        
        
    }
}

int main(int argc, char const *argv[])
{
    
    vector<vector<int> > matrix(count_points(argv[1]));



    // double matrix[][N] = {
    //                     {0, 20, 15, 30, 55},
    //                     {20, 0, 35, 25, 12},
    //                     {15, 35, 0, 30, 55},
    //                     {30, 25, 30, 0, 23},
    //                     {55, 12, 55, 23, 0}
    //                     };


    read_file(matrix, argv[1]);
    

    // printf("%d N", N);
    return 0;
}

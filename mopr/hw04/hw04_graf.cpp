#include <iostream>
#include <fstream>

using namespace std;

int N = 0;

void count_points(const char * filename)
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

    N = count_points;
}

void print(double A[][N])
{
	for(int i = 0; i < N + 1; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

}

int shortest_start_fin()
{
    int st_point;
    cout << "Starting point: ";
    cin >> st_point;
}

void read_file(double A[][N], const char * filename)
{
}

int main(int argc, char const *argv[])
{
    // count_points(argv[1]);

    double matrix[][N] = {
                        {0, 20, 15, 30, 55},
                        {20, 0, 35, 25, 12},
                        {15, 35, 0, 30, 55},
                        {30, 25, 30, 0, 23},
                        {55, 12, 55, 23, 0}
                        };


    // read_file(matrix, argv[1]);
    

    // printf("%d N", N);
    return 0;
}

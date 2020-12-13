#include <iostream>
#include <fstream>

using namespace std;

const int N = 4;

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

void read_and_add(double A[][N], const char * filename)
{
    ifstream info;
    info.open (filename);

    string num_string;
    double num;
    int k = 0;

    while (info.eof() == 0)
    {
        for(int i = 0; i < N + 1; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(k != 21)
                {
                    if(k % 4 == 0)
                    {
                        getline(info, num_string);
                        if(k == 0)
                        {
                            info.seekg(0, info.beg);
                        }
                    }
                    else
                    getline(info, num_string, ' ');
                    k++;
                }
                if(k == 2)
                {
                    j --;
                    continue;
                }
                num = stod(num_string);
                A[i][j] = num;
            }
            if(i == 4) return;
        }
    }

}

void first_row(double A[][N], double res[][N])
{
    for(int j = 0; j < N; ++j)
    {
        res[0][j] = A[4][j] - (A[j][0]*0.129 + A[j][1]*1.461
                               + A[j][2]*85.07 + A[j][3]*0.132);
    }
}

void swap_colons(double A[N][N+1], int c, int c2)
{
    double zap;
    for(int i = 0; i < N; ++i)
    {
        zap = A[i][c];
        A[i][c] = A[i][c2];
        A[i][c2] = zap;
    }

}

void gaus(double A[][N + 1], double X[])
{

    for(int j = 0; j < N - 1; j++)
	{
		for(int i = j + 1; i < N; i++)
		{
            if(A[j][j] == 0 && A[j][j + 1] != 0)
            {
                swap_colons(A, j, j + 1);
            }
            else
            {
                if(A[j][j] == 0 && A[j][j - 1] != 0)
                {
                swap_colons(A, j, j - 1);
                }
            }
			double del = -(A[i][j] / A[j][j]);

			for(int k = 0; k < N + 1; k++)
            {
				A[i][k] += A[j][k] * del;
            }
		}
	}

    for(int i = N - 1; i >= 0; i--)
	{
		double s = 0;
        X[i] = A[i][N] / A[i][i];
		for(int j = i + 1; j < N; j++)
        {
		    X[i] -= (X[j]* A [i][j])/ A[i][i];
        }

	}

    // for(int i = 0; i < N; ++i)
	// {
    //     cout<< "x" << i + 1 << " = "<<  X[i] << " ";
    // }

}

void finish(double A[][N], double B[][N], double X[N], double real[N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            B[i + 1][j] =  A[i][j] - (A[i][j]* real[j])/ X[j];
        }
    }
}

void matrix_for_gaus(double A[][N], double X[])
{
    double B[N][N + 1] = { {0.0, 0.0, 0.0, 0.0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0} };
    for (int i = 0; i < N + 1; i++)
    {
        B[i][N] = A[N][i];
    }

    for(int i = 0; i < N ; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            B[i][j] = A[i][j];
        }

    }

    gaus(B, X);
}

int main(int argc, char const *argv[])
{
    double matrix[][N] = { {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} };

    double new_matrix[][N] = { {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}};
    
    double X[N] = {0};
    double real[N] = {0.129, 1.461, 85.07, 0.132};

    read_and_add(matrix, argv[1]);
    first_row(matrix, new_matrix);
    // print(matrix);
    // print(new_matrix);

    matrix_for_gaus(matrix, X);
    
    finish(matrix, new_matrix, X, real);
    print(new_matrix);

    return 0;
}
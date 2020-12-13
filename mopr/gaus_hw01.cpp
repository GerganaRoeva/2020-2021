#include <iostream>
using namespace std;

const int N = 3;

void print_d(double A[N][N + 1], int n, int m)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

}

void print_i(int A[N][N + 1], int n, int m)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
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

void swap_colons_i(int A[N][N+1], int c, int c2)
{
    int zap;
    for(int i = 0; i < N; ++i)
    {
        zap = A[i][c];
        A[i][c] = A[i][c2];
        A[i][c2] = zap;
    }

}

void gaus_i(int A[][N + 1], int r, int c)
{      
    for(int j = 0; j < r - 1; j++)
	{
		for(int i = j + 1; i < r; i++)
		{
            if(A[j][j] == 0 && A[j][j + 1] != 0)
            {
                swap_colons_i(A, j, j + 1);
                
            }
            else if(A[j][j] == 0 && A[j][j - 1] != 0)
            {
                swap_colons_i(A, j, j - 1);               
            }
            
			double del = A[i][j] / A[j][j];

			for(int k = 0; k < c; k++)
            {
				A[i][k] -= A[j][k] * del;
            }
		}
	}


    for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
            A[i][j] /= A[i][i];
		}
	}

    int X[N] = {0};

    for(int i = N - 1; i >= 0; i--)
	{
		double num = 0;
		for(int j = i + 1; j < N; j++)
        {
		    num += A[i][j] * X[j];
        }

		X[i] = (A[i][N] - num);
	}

    print_i(A, r, c);

    for(int i = 0; i < N; ++i)
	{
        cout<< "x" << i + 1 << " = "<<  X[i] << " ";
    }
}

void gaus(double A[][N + 1], int r, int c)
{

    for(int j = 0; j < r - 1; j++)
	{
		for(int i = j + 1; i < r; i++)
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
			double del = A[i][j] / A[j][j];

			for(int k = 0; k < c; k++)
            {
				A[i][k] -= A[j][k] * del;
            }
		}
	}

    /*for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
            A[i][j] /= A[i][i];
		}
	}*/

    double X[N] = {0};

    for(int i = N - 1; i >= 0; i--)
	{
		double num = 0;
		for(int j = i + 1; j < N; j++)
        {
		    num += A[i][j] * X[j];
        }

		X[i] = (A[i][N] - num) / A[i][i];
	}

    print_d(A, r, c);

    for(int i = 0; i < N; ++i)
	{
        cout<< "x" << i + 1 << " = "<<  X[i] << " ";
    }

}

int main(int argc, char const *argv[])
{
    
    double A[][N+1] = {{1.2, 4.135, 2.613, 31.18027},
                      {-3.851, -2.719, 16.712, -51.40619},
                      {2.314, 23.187, 5.617, -15.98744}};

    double B[][N + 1] = {{2,2,1,14},
                        {1,1,-1,-11},
                        {4,2,3,44}};

    print_d(B, N, N+1);
    cout << endl;
    gaus(B, N, N+1);
    
   
    cout << endl;
    cout << endl;
    cout << endl;


    print_d(A, N, N+1);
    cout << endl;
    gaus(A, N, N+1);


    return 0;
}
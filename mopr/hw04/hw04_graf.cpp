#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <bits/stdc++.h>

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

void read_file(vector<vector<int> > *matrix, const char * filename)
{
    ifstream info;
    info.open (filename);

    string num_string;
    int num;

    while (info.eof() == 0)
        for (size_t i = 0; i < matrix->size(); i++)
        {
            getline(info, num_string, ' ');
            num = stoi(num_string);
            matrix->at(i).push_back(num);
            printf("%d ", num);
            if((i+1) % matrix->size() == 0) printf("\n");
        }
}

int minDistance(int *dist, bool spt_set[], int V)
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (spt_set[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

void shortestWay(vector<vector<int>> matrix)
{
    int start, end;

    cout << "\nStarting point: ";
    cin >> start;
    cout << "End point: ";
    cin >> end;

    int size = matrix.size();

    int to_eny_point[size];
    bool is_shortest[size];

    for (int i = 0; i < size; i++)
    {
        to_eny_point[i] = INT_MAX;
        is_shortest[i] = false;
    }
    
    to_eny_point[start] = 0;

    for (int count = 0; count < size - 1; count++)
    {
        int u = minDistance( to_eny_point, is_shortest, size);
        is_shortest[u] = true;

        for (int v = 0; v < size; v++)
            if (!is_shortest[v] && matrix[u][v] &&  to_eny_point[u] != INT_MAX && ( to_eny_point[u] + matrix[u][v]) <  to_eny_point[v])
                 to_eny_point[v] =  to_eny_point[u] + matrix[u][v];
    }
    
    cout << "min disance = "<<  to_eny_point[end] << endl;

}

void traverse(int u, bool visited[], vector<vector<int>> matrix)
{
    int size = matrix.size();
    visited[u] = true;

    for(int v = 0; v < size; v++) 
        if(matrix[u][v]) 
            if(!visited[v])
                traverse(v, visited, matrix);
      
}

int travlling_salesman_problem(vector<vector<int>> matrix)
{   
    int start;
    cout << "\nStarting point: ";
    cin >> start;

    vector<int> vect;
    // vector<int> vectOfPath;

    // vectOfPath.push_back(start);

    for (int i = 0; i < matrix.size(); i++)
        if (i != start)
            vect.push_back(i);
 
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = start;
        for (int i = 0; i < vect.size(); i++) {
            current_pathweight += matrix[k][vect[i]];
            k = vect[i];
        }
        current_pathweight += matrix[k][start];

        if (min_path > current_pathweight)
            min_path = current_pathweight;
        
        // vectOfPath.push_back(k);

 
    } while (next_permutation(vect.begin(), vect.end()));

    // vectOfPath.insert(vectOfPath.begin(), sizeof(min_path), min_path);
    // return vectOfPath;
    return min_path;
}

bool is_connected(vector<vector<int>> matrix) {
    int size = matrix.size();

    bool *visited = new bool[size];
    
    for(int u; u < size; u++) {
        for(int i = 0; i < size; i++)
            visited[i] = false;         
        traverse(u, visited, matrix);

        for(int i = 0; i < size; i++) 
            if(!visited[i])     
                return false;
        
    }
    return true;
}

bool is_euler_circuit(vector<vector<int>> matrix) {
    int size = matrix.size();

    if(is_connected(matrix) == false)
        return false;
    
    vector<int> inward(size, 0), outward(size, 0);

    for(int i = 0; i < size; i++)
    {
        int sum = 0;
        for(int j = 0; j < size; j++)
        {
            if(matrix[i][j])
            {
                inward[j]++;
                sum++;
            }
        }
        outward[i] = sum;
    }
    if(inward == outward)
        return true;
    return false;
}


int main(int argc, char const *argv[])
{    
    vector<vector<int> > matrix(count_points(argv[1]));

    read_file(&matrix, argv[1]);

    int size = matrix.size();

    shortestWay(matrix);

    if(is_euler_circuit)
    cout << "There is Euler Circuit \n";
    else cout << "There is NOT Euler Circuit \n";

    // vector<int> res = travlling_salesman_problem(matrix);

    // cout << "Time: " <<res[0] << endl;
    // for(auto i = res.begin() + 1; i < res.end(); i++)
    // {
    //     cout << *i << "->";
    // }

    int time = travlling_salesman_problem(matrix);
    cout << "Time: " <<time << endl;

    cout << endl;
    return 0;
}

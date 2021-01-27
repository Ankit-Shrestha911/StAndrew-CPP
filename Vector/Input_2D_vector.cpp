#include <bits/stdc++.h>
using namespace std;

// Passing 2D vector in function //
void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        // vector<int>temp; // create 1D vector inside first loop //
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    /*Directly assign the value 
    vector<vector<int> >input{
        {1,2,3},
        {1,2,3},
        {1,2,3}
    }
    */
    // Method 1 (User input)
    vector<vector<int>> input;
    int row = 3;
    int col = 3;
    int data;
    for (int i = 0; i < row; i++)
    {
        vector<int> temp; // create 1D vector inside first loop //
        for (int j = 0; j < col; j++)
        {
            cin >> data;
            temp.push_back(data);
        }
        input.push_back(temp);
    }

    print(input);

    // Method 2 //
    int row1 = 3;
    int col1 = 3;
    vector<vector<int>> v(row1, vector<int>(col1));

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> v[i][j];
        }
    }
    print(v);
    // Method 3 //

    int row2 = 3;
    int col2 = 3;
    vector<vector<int>> m(row2);

    for (int i = 0; i < row2; i++)
    {
        m[i].resize(col2);
        for (int j = 0; j < col2; j++)
        {
            cin >> m[i][j];
        }
    }

    print(m);

    return 0;
}
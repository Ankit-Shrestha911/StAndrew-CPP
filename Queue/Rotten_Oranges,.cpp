#include <bits/stdc++.h>
// #include<iostream>
using namespace std;

        // rotten oranges //

        /*
        adjacent(up(i-1,j) right(i,j+1), down(i+1,j), left(i,j-1))
        --> fetch all the rotten oranges index and time
        while(queue is not empty) doing the below task 
        --> extract the fetch index value in a integer (means (1,2,3) x = 1, y= 2, z=3)
        --> taking the max between ans = max(ans,time)
        --> Then check for all adjacents (creating for x[-1,0,1,0] = {},y[0,1,0,-1] array ) 
        --> take indexs int i_index = i+x[k], j_indenx = j+y[k] also check the is index valid or not;
        --> if(a[i_index][j_index]==1){
            a[i_index][j_index] = 2;
            push this index in a queue like( fruit f(in,jn,time+1))
        }
        -->if(queue is empty)  we check there is all oranges are rotten or not if(All are not rotten) return -1 

        return the ans //

        */

    int row, col;
    int a[100][100];
    int x[] = {-1, 0, 1, 0};
    int y[] = {0, 1, 0, -1};

    class fruit
    {
    public:
        int i;
        int j;
        int t;
        fruit(int a, int b, int c)
        {
            i = a;
            j = b;
            t = c;
        }
    };


    bool isValidIndex(int in, int jn)
    {
        if (in >= 0 and in < row and jn >= 0 and jn < col)
        {
            return true;
        }
        return false;
    }

    int rottenOranges()
    {
        /*
            --> initailize the ans variable in the top of the function 
            --> if in the function have 2D vecotr passed as argument //
            --> if(vector.size==1) ans=0;
        
        */
        // queue<pair<pair<int,int>,int>>q1; // also we can use this if we don't want to create class //
        queue<fruit> q;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (a[i][j] == 2)
                {
                    // q.push({{i,j},0}); // if we use q1 queue //
                    fruit f(i, j, 0);
                    q.push(f);
                }
            }
        }

        int ans = -1;

        while (!q.empty())
        {
            // auto f = q.front(); if we use q1 queue //
            fruit f = q.front();
            q.pop();

            /*
                if we use q1 queue
                int i = f.first.first;
                int j = f.first.second;
                int time = f.second;
            */
            int i = f.i;
            int j = f.j;
            int time = f.t;

            ans = max(ans, time);

            for (int k = 0; k < 4; k++)
            {
                int i_index = i + x[k];
                int j_index = j + y[k];

                /*
                    --> In a online platform like leetcode etc.. so we can't compare the index with row and col
                        because it's not global that's why below first if check the condtion index is in the range of row and col
                        or not. if not then we dont want to do anything.
                */
                if(i_index >= 0 and i_index < row and j_index >= 0 and j_index < col) 

                if (isValidIndex(i_index, j_index) and a[i_index][j_index] == 1)
                {
                    a[i_index][j_index] = 2;
                    // q.push({{i_index,j_index},time+1})  // if we use q1 function
                    fruit f(i_index, j_index, time + 1);
                    q.push(f);
                }
            }

            // q.pop() // if we use q1 queue // 
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (a[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }

    int main()
    {
        cout<<"Enter row and column ";
        cin>>row>>col;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin>>a[i][j];
            }
        }

        cout<<rottenOranges();

        return 0;
    }
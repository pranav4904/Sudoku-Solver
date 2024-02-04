#include<bits/stdc++.h>
using namespace std;

#define N 9

void print(int sudoku[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    } 
}

bool safe(int sudoku[N][N], int i, int j, int x)
{
    for(int k=0;k<N;k++)
    {
        if(sudoku[i][k]==x || sudoku[k][j]==x)
        {
            return false;
        }
    }

    int s=sqrt(N);
    int rs=i-i%s;
    int cs=j-j%s;
    
    for(int a=0;a<s;a++)
    {
        for(int b=0;b<s;b++)
        {
            if(sudoku[rs+a][cs+b]==x)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int sudoku[N][N], int i, int j)
{
    if(i == N)
    {
        i = 0;
        if(++j == N)
        {
            return true;
        }
    }
    
    if (sudoku[i][j] != 0)
    {
        return solve_sudoku(sudoku, i + 1, j);
    }
    
    for(int x=1;x<=N;x++)
    {
        if(safe(sudoku,i,j,x))
        {
            sudoku[i][j] = x;
            if(solve_sudoku(sudoku,i+1,j))
            {
                return true;
            }
        }
        sudoku[i][j] = 0; 
    }
    return false;
}

int main()
{
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if(solve_sudoku(grid,0,0))
    {
        print(grid);
    }
    else
    {
        cout << "No solution exists" << endl;
    }               

}

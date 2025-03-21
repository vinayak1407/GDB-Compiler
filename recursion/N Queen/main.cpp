#include <iostream>
using namespace std; 

bool canPlace(int board[][20],int n,int x,int y)
{
    // column 
    for(int k = 0; k<=x; k++)
    {
        if(board[k][y]==1)
        {
            return false; 
        }
    }
    // left diag
    int i =x; 
    int j =y; 
    while(i>=0 and j>=0)
    {
        if(board[i][j]==1)
        {
            return false; 
        }
        i--; 
        j--; 
    }
    
    //Right Diag 
    i=x; 
    j=y; 
    while(i>=0 and j<n)
    {
        if(board[i][j]==1)
        {
            return false; 
        }
        i--; j++; 
    }
    return true;   // and if none of these conditions are false then we should return true
}


void printBoard(int n,int board[][20])
{
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<< board[i][j]<<" "; 
        }
        cout<<endl; 
    }
    cout<<endl; 
}



bool solveNQueen(int n,int board[][20],int i)
{
    // base case 
    if(i==n)       //this means that we are done 
    {
        // Print the board
        printBoard(n,board);     
        return true; 
    }    
    
    
    // rec case 
    // try to place a queen in every row 
    // for every row we are trying to place the queen in every column. 
    for(int j=0;j<n;j++)   // you can come out of this for loop if and only if that could satisfy the constraints, it means there is something wrong with the parent   
    {
        // whether the current i,j is safe or not
        if(canPlace(board,n,i,j))
        {
          board[i][j] = 1;   // we first place the queen, then we check can we solve the remaining subproblem.                                         
          // Putting the queen 
          bool success = solveNQueen(n,board,i+1);              // whether the remaining board can be successfully solved or not. 
          if(success)
          {
              return true; 
          }
          else
          {
             return false;    
          }
          //backtrack 
            board[i][j] = 0;  // we are removing this queen from here   
            // Removing the queen
        }
    }
    return false;  // after finishing entire row, if the queen cannot be placed, this is signal to the previous row 
    // After all columns have been checked in the current row 
    
}

int main()
{
    int board[20][20] = {0}; 
    int n; 
    cin >> n; 
    
    solveNQueen(n,board,0); 
    return 0; 
}
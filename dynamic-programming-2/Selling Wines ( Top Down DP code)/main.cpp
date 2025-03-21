#include<iostream>
#include<vector>
using namespace std;

//top down dp code 
int wines (int dp[][10], int prices[], int L, int R, int y) 
{
  //base case 
  if(L>R)
  {
      return 0; 
  }
  //need if a state is already
  if(dp[L][R]!=0)
  {
      return dp[L][R]; 
  }
  
  //rec case 
   int pick_left = y*prices[L] + wines(dp,prices,L+1,R,y+1); 
   int pick_right = y*prices[R] + wines(dp,prices,L,R-1,y+1);     
    
   return dp[L][R] = max(pick_right,pick_left);    
}
 
 int wines_bottom_up(int prices[],int n)
 {
    vector<vector<int> > dp(n, vector<int>(n+1,0));  //this 2D matrix is zero  
    
    for(int i = n-1;i>=0;i--)
    {
        //bottom row to top row 
        for(int j =0;j<n;j++)
        {
            if(i==j)
            {
                dp[i][i] = n*prices[i]; 
            }
            else if(i<j)
            {
                //dp(i...j)
                int y = n - (j-i);
                int pick_left = prices[i]*y + dp[i+1][j]; 
                int pick_right = prices[j]*y + dp[i][j-1]; 
                  
                dp[i][j] = max(pick_left,pick_right);  
            
                cout<<dp[i][j]<<","; 
            }
            cout<<endl; 
        }
    }
    return dp[0][n-1]; 
 }


int main() {
	
	int a[] = {2,35,1,4};
	int n = 5;
	int dp[10] [10] = {0};
	cout<<wines(dp,a,0,n-1,1)<<endl;
	
	for(int i=0; i<n; i++){
	    for(int j=0;j<n; j++) {
	       cout<<dp[i][j]<<" ";
      	}
	     cout<<endl;
	}; 
	cout<<wines_bottom_up(a,n)<<endl; 
	return 0; 
}
#include<iostream>
#include<vector>
using namespace std; 

/*Approaches 
1- Recursive 
2- Top Down 
3- Bottom Up 
4- Bottom Up Optimised Recurrence 
*/

/*O(k^n), the complexity of this approach can be exponential. We are making calls that are n levels steep and at 
every level we have a tree that is having a breadth.... We are making k calls at every level, so it would be k^n  */

int countWays(int n,int k)      // this function being the slowest one 
{
    if(n==0)
    {
        return 1; 
    }
    if(n<0)
    {
        return 0; 
    }
    
    //recursive case 
    int ans = 0; 
    for(int jump=1;jump<=k;jump++)                       //jump<=k, that is the maximum jump that you can take 
    {
        ans += countWays(n-jump,k);     // the value of n-jump can be negative 
    }
    return ans; 
}

//Top Down Code 
int countWaysTD(int n,int k)
{
    if(n==0)
    {
        return 1; 
    }
    if(n<0)
    {
        return 0; 
    }
    //check if state is already computed 
    if(dp[n]!=0)
    {
        return dp[n]; 
    }
    
    //recursive case 
    int ans = 0; 
    for(int jump=1;jump<=k;jump++)                       //jump<=k, that is the maximum jump that you can take 
    {
        ans += countWaysTD(n-jump,k,dp);     // the value of n-jump can be negative 
    }
    return dp[n]=ans; 
}

//Bottom Up Approach(O(n+k))

int countWaysBU(int n,int k)
{
    //Iterative Approach
    
    vector<int> dp(n+1,0)     //vector of size n and initialising it with 0. 
    dp[0]=1; 
    
    for(int i=1;i<=n;i++)         // this loop runs in O(n) time e
    {
       for(int jump = 1; jump<=k;jump++){   // this loop runs in O(k) time 
       if(i-jump>=0)
        {
           dp[i]+= dp[i-jump];     //then we add the answer of previous state into the current state 
        }
      }
    }
    return dp[n]; 
}

//Bottom Up - Optimised((O(n+k)))
int countWaysOpt(int n,int k)    // this function being the fastest one 
{
    vector<int>dp(n+1,0); 
    
    dp[0]=dp[1]=1; 
    
    for(int i=2;i<=k;i++)
    {
      dp[i] = 2*dp[i-1];    
    }
    
    for(int i=k+1;i<=n;i++)
    {
      dp[i] = 2*dp[i-1] - dp[i-k-1];     
    }
    
    return dp[n]; 
}



int main()
{
   int n,k; 
   cin>>n>>k; 
   int dp[1000] = {0}; 
   cout<<countWaysTD(n,k)<<endl; 
   cout<<countWaysBU(n,k)<<endl; 
   cout<<countWaysOpt(n,k)<<endl; 
   return 0; 
} 
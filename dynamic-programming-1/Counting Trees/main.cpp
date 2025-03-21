#include<iostream>
using namespace std;

//exponential time
int countBST(int n)
{
	if(n==0 or n==1)
	{
		return 1;
	}

	int ans = 0;
	for(int i=1; i<=n; i++)
	{
		int x = countBST(i-1);
		int y = countBST(n-i);
		ans+= x*y;
	}

	return ans;
}


// O(n*2) is better
int countBSTTopDown(int n,int dp[])
{
	if(n==0 or n==1)
	{
		return 1;
	}

	if(dp[n]!=0)
	{
		return dp[n];
	}
	int ans = 0;
	for(int i=1; i<=n; i++)
	{
		int x = countBSTTopDown(i-1,dp);
		int y = countBSTTopDown(n-i,dp);
		ans+= x*y;
	}

	return dp[n] = ans;
}

int coutBSTBottomUp(int N)
{
	vector<int> dp(N+1,0);
    
    dp[0] = dp[1] = 1; 

    for(int n=2;i<=N;n++)
    {
        for(int i=1;i<=n;i++)
        {
            dp[n]+=(dp[i-1])*dp[n-i]);        
        }
    }
    return dp[N];  
}


int main()
{
	int n = 5;
	cout <<countBST(n) <<endl;

	int dp[100] = {0};
	cout <<coutBSTTopDown(n,dp) <<endl;

	cout << coutBSTBottomUp(n) << endl;
	return 0;
}
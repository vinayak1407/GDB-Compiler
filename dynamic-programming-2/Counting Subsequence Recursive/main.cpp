#include<iostream>
using namespace std;

//Top Down 
int countSub(string a, string b,int m,int n) {
     
    //base case  
    if((m==-1 and n==-1) or n==-1) // this is the condition in which we are going to return -1. In this either both of them is null or s2 is null 
    { 
        return 1; 
    }  
    if(m==-1)
    {
        return 0;     // in such a case there is no way for second string to lie in the first string 
    }
    
    
    //rec case  
    
    if(a[m]==b[n])   // if the last characters match, then we have to two options either to take the last letter from a or not.  
    {
        return countSub(a,b,m-1,n-1) + countSub(a,b,m-1,n); 
    }
    
    return countSub(a,b,m-1,n); 
      
}

// Count Subsequences Bottom Up 
int countBU(string a, string b)
{
    
    int m = a.length(); 
    int n = b.length(); 
    
    vector<vector<int> > dp(m+1, vector<int>(n+1,0));        //m+1 rows and each row will be a vector of n+1 columns, each element being initialised with the value 0 
    
    // Fill the table in bottom up manner. 
    // Make the first column as 1. 
    
    for(int i=0; i<=m;i++)     // this is for the base case and part of the base case is already covered in the default initialisation  
    {
        dp[i][0] = 1; 
    }
    
    //1,1 ....... m,n 
    for(int i=1;i<=m;i++)     // For the DP table, the indexing is 1 based 
    {
        for(int j=1;j<=n;j++)  
        {
            if(a[i-1] = b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
            }
            else {
                dp[i][j]=dp[i-1][j]; 
            }
            cout<<dp[i][j]<<" "; 
        }
        cout<<endl; 
    }
    return dp[m][n];   
}



int main() {
	string a = "ABCDCE";
	string b = "ABC";
	
	cout <<< count(a,b,a.size()-1,b.size()-1)<<endl;
}
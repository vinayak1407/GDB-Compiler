#include<iostream>
#include<vector>
using namespace std;


//Bottom Up Solution
int lis(vector<int> arr) {
         
        int n = arr.size(); 
        vector<int> dp(n,1); 
        
        int len = 1;       // this variable will actually store the maximum of all the values 
        
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    dp[i] = max(dp[i],1 + dp[j]);  //dp[j] denotes the length of the sequence where the last element is arr[j] 
                    len=max(len,dp[i]); 
                }
            }
        }
      return len; 
    
}

int main() {

	vector<int> arr{50,4,10,8,30,100};

	cout <<lis(arr)<<endl;

	return 0;

}
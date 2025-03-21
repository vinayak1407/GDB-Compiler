#include <iostream>
using namespace std; 


bool divideAmongK(int arr[],int n, int k, int min_coins)
{ 
    int partitions = 0; 
    int current_friend = 0; 
    
    for(int i =0; i<n;i++)
    {
        if(current_friend + arr[i] >=min_coins)
        {
            partitions += 1; 
            current_friend = 0; 
        }
        else 
         {
              current_friend += arr[i]; 
         }
    }
    
    return partitions >=k
    
}




int k_partition(int *arr,int n,int k) {
    
    int s = 0;  // start is 0
    int e = 0;                          // largest is sum of all the elements in the array 
    for(int i = 0; i<n;i++)
    {
        e+= arr[i]; 
    }
    
    while(s<=e)
    {
        int mid = (s + e)/2; 
        bool isPossible = divideAmongK(arr,n,k,mid); // dividing the array into k parts such that everyone gets atleast mid number of coins 
    
        if(isPossible)   // Everytime we get something as true, that can be our potential answer 
        {
            s = mid + 1; 
            ans = mid; 
        }
        else 
        {
            e = mid - 1; 
        }
    }
    return ans; 
}


int main()
{
    int a[] = {10,20,40,30}; 
    int n = sizeof(a)/sizeof(int); 
    int k = 3; 
    
    cout << k_partition(a,n,k) << endl;   // what is the maximum amount i can get from the minimum partition

    return 0; 
    
}
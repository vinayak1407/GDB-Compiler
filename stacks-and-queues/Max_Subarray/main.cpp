#include <iostream> 
#include<vector> 
#include<deque> 
using namespace std; 

void maxSubArrayK (vector<int> a, int k) 
{ 
    //Algorithm 
    
    deque<int> Q(k);  // doubly ended queue of integers, calling it as Q whose size is k.  
    //1. Process only the first K elements 
    for(i=0;i<k;i++)
    {
       //Logic here........
       while(!Q.empty() && a[i] >=a[Q.back()])
       {
           Q.pop_back(); 
       }
       
    //always    
       Q.push_back(i); // a operation in which every element that comes, we try to push it inside the queue, because we never know whether that element will be a useful one or not a useful one.   
    }
    
    //2. Remaining elements of the array, it's going to be a linear algorithm that will run in O(N) time 
    for( ;i<n;i++)     
    {
        cout << a[Q.front()]<< " ";         // whatever is at the front of the queue, we are going to print it 
        //Remove element from the left (contraction) when an index lies outside the current window 
        while(!Q.empty() and Q.front() <=i-k)
        {
            Q.pop_front(); 
        }
        
        
        
        //always 
        Q.push_back(i); 
    }
}


int main() {
     vector<int> arr{1,2,3,1,4,5,2,3,5); 
     int k = 3; 
     maxSubArrayK(arr,k); 


     return 0; 
}
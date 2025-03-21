#include<iostream>
#include<queue> 
using namespace std; 

class Compare
{
    public:            //this function is public because it would be called from outside the compare class 
        bool operator()(int a,int b){
            return a < b; 
        }
        
}; 



int main()
{
    int arr[] = {10,15,20,13,6,90}; 
    int n = sizeof(arr)/sizeof(int); 
    
    priority_queue<int,vector<int>, Compare > heap;           // element with a higher value has a higher priority, by default it maeks a max heap   
 // variable            data structure 
    
    for(int x : arr)
    {
          heap.push(x);        // all the elements are added inside the heap 
    }
    
    while(!heap.empty())
    {
        cout<< heap.top() <<endl;     // top function displays what is at the top 
        heap.pop();         //pop function removes that topmost element 
    }
    return 0; 
}
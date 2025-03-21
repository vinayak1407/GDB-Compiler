#include <stdio.h>
using namespace std; 

//helper method
void merge(vector<int> &array,int s,int e){   // writing this function that merges two arrays into a single array 
    int i = s; 
    int m =(s+e)/2; 
    int j= m + 1; 
    
    vector<int> temp; 
    
    while(i<=m and j<=e){
        if(array[i]<array[j]){
            temp.push_back(array[i]);
            i++; 
        }
        else{
            temp.push_back(array[j]); 
            j++; 
        }
    }
    
    // this loop will break when one of these arrays is exhausted. 
    // copy remaining elements from 1st array.
    while(i<=m){
        temp.push_back(array[i++]); 
    }
    // or copy remaining elements from second array 
    while(j<=e){
        temp.push_back(array[j++]); 
    }
    // copy back the elements from temp to original array so that mergesort function can see the actual changes 
    int k = 0; 
    for(int idx = s; idx<=e;idx++){
        array[idx]=temp[k++]; 
    }
    
    return; 
    
    
}

//sorting method 
void mergesort(vector<int> &array,int s,int e){
    //base case    
    if(s>=e){    // array containing one element we can assume this is a sorted array 
        return; 
    }
    //rec case 
    int mid = (s+e)/2; 
    mergesort(arr,s,mid);                  // mergesort on the left part of the array 
    mergesort(arr,mid+1,e); 
    return merge(arr,s,e); 
}

int main()
{
    vector<int> arr{10,5,2,0,7,6,4}; 
    
    int s=0; 
    int e=arr.size()-1; 
    mergesort(arr,s,e); 
    for(int x: arr){
        cout<<x<<" , ";
    }
}
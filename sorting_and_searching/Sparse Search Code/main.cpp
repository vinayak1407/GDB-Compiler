#include <iostream>
#include <cstring>
using namespace std; 

int sparse_search(string a[],int n,string key)
{
    int s = 0; 
    int e = n-1; 
    
    while(s<=e){
        
        int mid = (s + e)/2; 
        
        int mid_left = mid - 1;   // using these two variables to traverse through the left part and the right part of the array.
        int mid_right = mid + 1; 
        if(a[mid]==" "){
            //update our mid to point to a nearest non empty string 
            // i will stop updating them as soon as i find one of them to point to a non empty string
            while(1){
                if(mid_left < s and mid_right > e){
                    return -1; 
                }
                else if(a[mid_right]<=e and a[mid_right]!=""){
                    mid=mid_right; 
                    break; 
                }
                else if(mid_left>=s and a[mid_left]!=""){
                    mid=mid_left; 
                    break; 
                }
                mid_left--; 
                mid_right++; 
            }
            
        }
          if(a[mid]==key){
            return mid; 
        }
        else if(a[mid]>key){
            end = mid - 1; 
        }
        else {
            s= mid + 1; 
        }
        
    }
    return -1;  
    
}


int main()
{
    string arr[] = {"ai","","","bat","","","car","cat","","","dog","e"}; 
    int n=12; 
    
    
    string f; 
    cin>>f; 
    cout<<sparse_search(arr,n,f)<<endl; 
    return 0;
}
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKArrays (vector<vector<int> > arrays) 
{
    //logic 
   
    int k = arrays.size(); 
    //triplet,     heap node will contain three elements,one is the element itself, one is the element index, one is the array index 
    priority_queue< vector<int>, vector<vector<int> >, greater<vector<int> > > q;                                 // each element of the priority queue will be of the type triplet 
    
    vector<int>output; 
    
    
    //init the heap 
    for (int i=0;i<k;i++)
    {
        int element = arrays[i][0]; 
        q.push({element,i,0}); 
    }
    
    //start popping 
    while(!q.empty())
    {
        auto top = q.top();  // we can just print it or push it inside the vector 
        q.pop(); // removing the topmost element from the queue 
        
        int element = top[0]; 
        int a_idx = top[1]; 
        int e_edx = top[2]; 
    
        output.push_back(element); 
        
        if(e_idx + 1 < arrays[a_idx].size())
        {
            int next_element = arrays[a_idx][e_idx + 1]; 
           q.push({arrays[a_idx][e_idx + 1],a_idx,e_idx + 1});    
        }

    }
    
    return output; 
    
}    
    
int main() {
		vector<vector<int> > arr = {{10,15,20,30},
				                   {2,5,8,14,24},
				                   {0,11,60,90}};
//various approaches
			vector<int> result = mergeKArrays(arr);
//output
			for(auto x: result) {
				cout<<x <<" ";
			}
			return 0;
		}

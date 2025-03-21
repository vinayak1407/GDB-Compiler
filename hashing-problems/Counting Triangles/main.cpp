#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int count_triangles (vector<pair<int,int> > &points) 
{
    unordered_map<int,int> freq_x;      //first parameter represents the key and second parameter represents the frequency, how many times this x coordinate has occurred in the all the points.  
    unordered_map<int,int> freq_y;     
    
    //Count the freq by iterating over all the points 
    for(auto p:points)
    {
        int x = p.first;               // This loop runs in O(N) time 
        int y = p.second; 
        
        freq_x[x]++; 
        freq_y[y]++; 
    }
    
    //count 
    int count = 0; 
    for(auto p: points)
    {
        int x = p.first;             // This loop runs in O(N) time 
        int y = p.second;     
        int fx = freq_x[x]; 
        int fy = freq_y[y]; 
        
        count += (fx-1)*(fy-1); 
    }
    return count;  
}


int main() {
	int N;
	cin>>N;
	
	vector<pair<int, int> > points;   // each point here is represented as a pair of two integers   a
	
	for(int i=0; i<N; i++) {
		int x,y;
		cin>>x>>y;
		points.push_back({x,y});
	}
	cout<<count_triangles (points);
	
	return 0;
}
#include<bits/stdc++.h>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

class Graph {
	list<pair<int, int>> *l;
	int V;

public:
	Graph(int V) {
		this->V = V;
		l = new list<pair<int, int>>[V];
	}

	void addEdge(int u, int v,int wt, bool undir = true) {
		l[u].push_back({wt,v});
		if(undir)
		{
		    l[v].push_back({wt,u}); 
		}
	}
	
	int dijkstra(int src, int dest)
	{
	    //Data Structures
	    vector<int> dist(V,INT_MAX);  // vector of bool which is visited for V vertices and everything is set to false in the beginning.  
	                                  //dist array will serve two purpose, one whether a node have been visited or not and if it is visited, then what is the distance. 
	    set<pair<int,int> >s;  // set will store pairs, each pair will store the current node and it's distance 
	    
	    //1. Init 
	    dist[src] = 0; 
	    s.insert({0,src});    // distance is zero and the node is source 
	    
	    while(!s.empty())  // while s is not empty 
	    {
	        auto it = s.begin(); 
	        int node = it->second; 
	        int distTillNow = it->first;    // the first thing which i am putting in the set is the distance 
	        s.erase(it); //Pop 
	        
	        
	        //Iterate over the nbrs of node 
	        for(auto nbrPair: l[node])    //for every neighbour pair that is there in adjacency list of node 
	        {
	            //.............
	            
	            int nbr = nbrPair.second; 
	            int currentEdge = nbrPair.first; 
	            
	            if(distTillNow + currentEdge < dist[nbr])
	            {
	                //remove if such a pair already exists in the set with the old value of distance, then we should also remove it   
	                //remove if neighbour already exist in the set 
	                  
	                auto f = s.find({dist[nbr],nbr}); // to check if that node exist in the set or not 
	                if(f!=s.end())
	                {
	                    s.erase(f); 
	                }
	                
	                //insert the updated value with the new dist 
	                dist[nbr] = distTillNow + currentEdge; 
	                s.insert({dist[nbr],nbr}); 
	           
	            }
	            
	        }
	    }
	    // Single Source Shortest Dist to all other nodes 
	    
	    for(int i=0;i<V;i++)
	    {
	        cout<<"Node i"<<i<< " Dist " << dist[i] <<endl; 
	    }
	    
	    return dist[dest]; 
	    
	}
}; 

int main()
{
    Graph g(5); 
    g.addEdge(0,1,1); 
    g.addEdge(1,2,2); 
    g.addEdge(0,2,4); 
    g.addEdge(0,3,7); 
    g.addEdge(3,2,2); 
    g.addEdge(3,4,3); 

    cout << g.dijkstra(0,4)<<endl; 
}
#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph {
	int V;
	list<int> *l;

public:
	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=true) {
		l[i].push_back(j);
		if(undir) {
			l[j].push_back(i);
		}
	}
	
	void bfs(int source)
	{
	    
	    queue<int> q; 
	 //   bool *visited = new bool[V]{0};  // we can initialise this array with all zeroes. 
	   bool *visited = new bool[V];
       for (int i = 0; i < V; i++) visited[i] = false;

	    
	    q.push(source); 
	    visited[source]=true; 
	    
	    int f; 
	    
	    while(!q.empty())  // while q is empty, it means that your nodes are to be processed. Once all the nodes have been printed or traversed, your queue will become empty  
 	    {
	        //do some work for every node that is there inside the queue 
	        f = q.front(); 
	        cout<<f <<endl; 
	        q.pop(); 
	   
	    //Push the neighbours of current node inside q if they are not already visited 
	    for(auto nbr : l[f])      //l[f] is a list that gives the neighbours of current node that is 1. 
	    {
	        if(!visited[nbr])
	        {
	            q.push(nbr); 
	            visited[nbr] = true; 
	        }
	    }
	}
	} // The nodes at a lower level will be printed first than the nodes which are at a higher level.  
	
};

    int main(){
       
        Graph g(7); 
        g.addEdge(0,1); 
        g.addEdge(1,2); 
        g.addEdge(2,3); 
        g.addEdge(3,5); 
        g.addEdge(5,6); 
        g.addEdge(4,5); 
        g.addEdge(0,4); 
        g.addEdge(3,4); 
        g.bfs(1); 
        return 0;
    }
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
	list<int> *l;
	int V;

public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}

//undirected-graph
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
    
    bool dfs(int node, vector<bool> &visited, int parent)
    {
        // mark that node visited 
        visited[node] = true; 
        
           for(auto nbr: l[node])
           {
               if(!visited[nbr])
               {
                   bool nbrFoundACycle =  dfs(nbr,visited,node)  // it is possible that neighbour may found a cycle, now the parent will be the current node.  
                   if(nbrFoundACycle)
                   {
                       return true; 
                   }
               }
               //nbr is visited and its not the parent of current node in the current dfs call.( If you get a neighbour that is visited, then you should return true)
               else if(nbr!=parent)
               {
                   return true; 
               }
              
           }
           return false; 
        
    }

   bool contains_cycle()
   {
     //Graph is a single component, there are no multiple components in the graph 
       vector<bool> visited(V,false); 
        return dfs(0,visited,-1);    
   }

}; 

bool contains_cycle(int V, vector<pair<int,int> > edges)
{
    Graph g(V); 
    for(auto edge: edges)
    {
        g.addEdge(edge.first,edge.second);; 
    }
    
    return g.contains_cycle();
    
}
	
	int main() {
	
		Graph g(3);
		g.addEdge(0,1);
		g.addEdge(1,2);
	  //	g.addEdge(2,0);
	
		cout << g.contains_cycle() <<endl;
		return 0; 
	}
	
#include<iostream>
#include<list>
using namespace std; 


class Graph{
    
    int v;   // It represents the number of vertices (nodes) in the graph. It determines the size of the adjacency list.
    list<int> *l;       // this is actually a pointer to an array of list<int>
     
public: 
    Graph(int v)
    {
        V=v; 
        l= new list<int>[V]; 
    }
     
    void addEdge(int i,int j,bool undir=true)
    {
        l[i].push_back(j); 
        if(undir)
        {
            l[j].push_back(i); 
        }
    }
    
    void printAdjList()
    { 
        //Iterate over all the rows
        for(int i=0;i<V;i++)
        {
            cout<<i<<"-->"; 
            //every element of ith linked list 
            for(auto node:l[i])   //auto automatically determines the datatype that is based upon the data that is on the right hand side  
            {
                cout<<node<<","; 
            }
            cout<<endl; 
        }
    }
    
   
}; 

int main()
{
    Graph g(6); 
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.printAdjList(); 
 
    return 0;    
}

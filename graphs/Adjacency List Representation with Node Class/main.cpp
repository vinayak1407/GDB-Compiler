#include <list>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std; 

class Node{
public: 
    string name; 
    list<string> nbrs; 
     
    Node(string name)
    {
        this->name = name; 
    }
}; 

class Graph{
    //What all nodes are there 
    //Hashmap (String,Node*), this hash map will store the relationship between the keys that are the city names to the node objects  
public:
    unordered_map<string,Node*> m; 
    Graph(vector<string> cities){
        for(auto city : cities)
        {
            m[city] = new Node(city); 
        }
    }
    
    void addEdge(string x,string y,bool undir=false)
    {
        m[x]->nbrs.push_back(y);         //m[x] is a pointer
    
        if(undir)
        {
            m[y]->nbrs.push_back(x); 
        }
    }
    void printAdjList()
    {
        for(auto cityPair : m)    //(cityPair: name,address)
        {
            auto city = cityPair.first; 
            Node *node = cityPair.second; 
            cout<<city<<"-->"; 
            
            for(auto nbr : node->nbrs)
            {
                cout << nbr << ",";  
            }
            cout<<endl; 
        }
    }
}; 

int main(){
    vector<string> cities = {"Delhi","London","Paris","New York"}; 
    
    Graph g(cities); 

    g.addEdge("Delhi","London"); 
    g.addEdge("New York","London"); 
    g.addEdge("Delhi","Paris"); 
    g.addEdge("Paris","New York"); 
    
    g.printAdjList(); 
    
    return 0; 
    
}
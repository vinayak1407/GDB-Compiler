#include<iostream> 
#include<list>
#include<unordered_map>
using namespace std; 

//Node to store the data( Linked List )
class Node{
public: 
   
      string key; 
      int value; 
      Node(string key, int value)
      {
          this->key = key; 
          this->value = value; 
      }
}; 

// LRU Cache Data Structure 
class LRUCache{
public: 
    int maxSize;   
    list<Node> l; 
    unordered_map<string,list<Node>::iterator > m; 
    
    LRUCache(int maxSize)
    {
        this->maxSize = maxSize > 1 ? maxSize: 1; 
    }
    
    void insertKeyValue(string key,int value)
    {
        //2 cases 
        if(m.count(key)!=0)        /* if it is present in the cache, then it must be present in the hasmap also 
                                       then this means this key value pair must exist in the cache*/ 
        //replace the old value and update 
        {
        auto it = m[key];  
        it-> value = value; 
        }
         else{
            // check if cache is full or not, if it is full then we will remove the last item from the cache or the least recently used item from the cache  
            // remove the least recently used item from cache 
            if(l.size()==maxSize)  // meaning that cache is full 
               Node last = l.back(); 
               m.erase(last.key); // remove from hasmap 
               l.pop_back(); // remove from Linked List. 
         }
         
            Node n(key,value); 
            l.push_front(n); // push that node to the front of the linked list 
            m[key] = l.begin(); 
            
            
        }
      
    
    int* getValue(string key)   // we need to get a key and we will return a particular value. 
    {
        if(m.count(key)!=0)
        {
             auto it = m[key];    
            
             int value = it->value;    // we are actually returning the address of the local variable that is being destroyed. 
             l.push_front(*it);    // copy all the key value pairs that is in *it and this is now pushed to the front of the linked list 
             l.erase(it); 
             m[key] = l.begin(); 
             return &l.begin()->value;  
        }
        return NULL; 
    }
    
    string mostRecentKey()
    {
        return l.front().key;    // simply need to return what is there at the head of the linked list 
 
    }
};


int main()
{
    LRUCache lru(3); 
    lru.insertKeyValue("mango", 10); 
    lru.insertKeyValue("apple",20); 
    lru.insertKeyValue ("guava", 30); 
    cout << lru.mostRecentKey() <<endl; 
    
    lru.insertKeyValue("mango", 40); 
    cout << lru.mostRecentKey() <<endl; 

    int *orders = lru.getValue("mango");   // get value brings that node to the head of the linked list  
    if(orders!=NULL)
    {
        cout<<"Order of Mango"<<*orders <<endl; 
    }
 
    
    
    lru.insertKeyValue("banana", 20); 

    if(lru.getValue("apple")==NULL) { 
       cout<<"apple doesn't exist"; 
    } 

    if(lru.getValue("guava")==NULL) { 
        cout<<"guava doesn't exist"; 
    } 
    
    if(lru.getValue("banana")==NULL) { 
        cout<<"mango doesn't exist"; 
    }
    
    if(lru.getValue("mango")==NULL) { 
        cout<<"mangoa doesn't exist";  
    }
}

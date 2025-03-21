#include <iostream>
using namespace std; 

class Node 
{
    public: 
      int key; 
      Node*left; 
      Node*right; 
      
      Node(int key)
      {
          this->key = key; 
          left = right = NULL; 
      }
}; 

node*insert (Node*root,int x)
{
    if(root==NULL)
    {
        return new Node(key); 
    }
    
    //rec case 
    if(key< root->key)
    {
        root->left = insert(root->left,key);    // root->left point to a new subtree that is returned by the insert function    
    }                  // everytime we are making a call, we are changing the root node 
    
    else{
        root->right = insert(root->right,key); 
    } 
    return root; 
}

bool search(Node*root,int key)
{
    //Homework
    
    
}

void printInOrder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    //left,root,right
    printInOrder(root->left); 
    cout<< root->key << " "; 
    printInOrder(root->right); 
}


int main()
{
    Node*root = NULL; 
    int a[] = {8,3,10,1,6,14,4,7,13};  
    
    for(int x: arr)
    {
        root = insert(root,x); 
    }
    
    
}



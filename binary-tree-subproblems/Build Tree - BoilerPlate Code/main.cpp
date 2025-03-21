#include<iostream>
#include<queue>
using namespace std;

class node {
 
public: 
  int data;
  node * left;
  node * right;
  
  node(int d) {         // Constructor which initialises the data with the value d 
    data = d;           // Everytime creating a new node simply calling the Constructor and i can pass in the data 
    left = NULL;
    right = NULL;   
      }
  };
 //Input: 124-1-157-1-1-13-16-1-1 
  node * buildTree() {
    
    int d;
    cin >> d;
    
    if (d == -1) {
      return NULL;
    }
    
    node * n = new node(d);
    n -> left = buildTree();
    n -> right = buildTree():
    
    return n; 
  
      
  }
 
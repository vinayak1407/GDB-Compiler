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
    left = NULL;       // Whenever a new node is constructed simply put the left and the right pointer as null by default
    right = NULL;   
      }
  };
 //Input: 124-1-157-1-1-13-16-1-1 
  node * buildTree() {
    
    int d;
    cin >> d;
    
    if (d == -1) 
    {
      return NULL;
    }
    
    node * n = new node(d);
    n -> left = buildTree();
    n -> right = buildTree(); 
    return n; 
  }
 
 void levelOrderPrint(node*root)
 {
     queue<node*> q; 
     q.push(root); 
     q.push(NULL); 
     
     while(!q.empty())
     {
        node*temp = q.front();   // this can be either null or it can be a pointer to the node 
        if(temp == NULL)
        {
            cout<<endl; 
            q.pop(); 
            //insert a new null for the next level. 
            if(!q.empty())  //  it's not the case we have finished with all elements 
            {
               q.push(NULL);  
            }
        }
        else{
            q.pop(); 
            cout<<temp->data<<" "; 
            if(temp->left){
                q.push(temp->left);  
            }
            if(temp->right)
            {
                q.push(temp->right); 
            }
        }
     }
     return; 
 }
 
 //Helper Function : Height of the Tree 
 int height(node*root)
 {
    if(root == NULL )
    {
        return 0; 
    }
    int h1= height(root->left); 
    int h2 = height(root->right);    // this is an example of the post order traversal where we first go left and then we go right. 
    return 1 + max(h1,h2);           // Total time complexity is going to be O(N) because we are traversing the entire tree 
 }
 
 int height(node*root)
 {
    if(root==NULL)
    {
        return 0; 
    }
     
    int h1 = height(root->left); 
    int h2 = height(root->right); 
    return 1 + max(h1,h2); 
 }
 
 //Diameter 
 //Time Complexity ? 
 int diameter(node*root)
 {
     //base case 
     if(root==NULL)
     {
         return 0; 
     }
     
     //rec case 
     int D1 = height(root->left) + height(root->right);   //-> O(N)
     int D2 = diameter(root->left);    // these calls are taking us to every node, so the overall complexity of this approach is O(N^2) 
     int D3 = diameter(root->right); 
     
     return max(D1,max(D2,D3)); 
 }
 
 //-------------------------Diameter Optimised 
class HDPair{
public: 
      int height; 
      int diameter;
 };
 
HDPair optDiameter(node*root)
{
    HDPair P; 
    if(root==NULL)
    {
        p.height = p.diameter = 0; 
        return p; 
    }
    
    //otherwise 
    HDPair Left = optDiameter(root->left); 
    HDPair Rigt = optDiameter(root->rigt); 
    
    p.height = max(Left.height,Right.height) + 1; 
    
    int D1 = Left.height + Right.height; 
    int D2 = Left.diameter; 
    int D3 = Right.diameter; 
    
    p.diameter = max(D1,max(D2,D3)); 
    return p;  // from every node we are returning a pair that contains both the height and the diameter
}
 
 
 
 
 node* levelOrderBuild()   // levelOrderBuild that returns a pointer that is a root pointer 
 {
    int d;  
    cin>>d; 
    
    node*root = new node(d); 
    
    queue<node*> q; 
    q.push(root); 
     
     
    while(!q.empty())
    {
        node*current  = q.front(); 
        q.pop(); 
        
        int c1,c2; 
        cin>>c1>>c2; 
        
        if(c1!=-1)
        {
          current->left = new node(c1); 
          q.push(current->left); 
        }
        if(c2!=-1)
        {
            current->right = new node(c2); 
            q.push(current->right); 
        }
    }
     return root; 
 }
 
 // Todo: Replace with Descendant Sum leaving leaf nodes intact 
 void replaceWithSum(Node*root)
 {
     
    // base case  
    if(root==NULL)
    {
        return 0; 
    }
    
    if(root->left==NULL and root->right==NULL)
    {
        return root->data; 
    }
    // recursive case  
    int LS = replaceWithSum(root->left); 
    int RS = replaceWithSum(root->right); 
    
    int temp= root->data;  
    root->data = LS + RS; 
    return root->data + temp; 

 }
 
 int main()

{
    // //node* root = buildTree(); 
    // node*root = buildTree(); 
    // levelOrderPrint(root); 
    // cout << "Diameter is " <<diameter(root) <<endl;  
    // cout << "Opt Diameter is" <<optdiameter(root).diameter<<endl;  
      
       node*root = levelOrderBuild(); 
       levelOrderPrint(root); 
       cout<<endl; 
       replaceWithSum(root); 
       levelOrderPrint(root); 
     
    return 0;     
}
 
 
 
 
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree(){

	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void levelOrderPrint(node*root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			//insert a new null for the next level
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";

			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}

	}
	return;
}
// ToDo : Complete the MaxSubset Function 

class Pair {
    public:
        int inc;         //.include, .exclude that will improve the readability of code for you 
        int exc;         
}; 
// O(N)
Pair maxSubsetSum(node* root)
{
    Pair p; 
    if(root==NULL)
    {
        p.inc = p.exc=0; 
        return p; 
    }
    
    // In the recursive case, we need to make a call on the left part and the right part that will give us the include and exclude pairs for both left and right  
    
    Pair Left = maxSubsetSum(root->left); 
    Pair Right = maxSubsetSum(root->right); 
    
    p.inc = root->data + Left.exc + Right.exc; 
    p.exc = max(Left.inc,Left.exc) + max(Right.inc,Right.exc); 
    
    return p; 
}

int main()
{
    node*root = buildTree(); 
    levelOrderPrint(root); 

    Pair p = maxSubsetSum(root); 
    cout<<"Max Sum :"<< max(p.inc, p.exc)<<endl; 
    
}






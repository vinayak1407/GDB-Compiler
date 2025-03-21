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

void printAtLevelK(node*root,int k)
{
    if(root==NULL)
    {
        return;          //simply returning and not doing anything. 
    }
      
    if(k==0)
    {
        cout<<root->data<<" "; 
        return; 
    }
    
    printAtLevelK(root->left,k-1); 
    printAtLevelK(root->right,k-1); 
    return; 
}

int printNodesAtDistanceK(node*root, node*target, int k)
{
    //base case 
    if(root==NULL)  // if you reach a Null node that means you cannot find the target node, simply return -1 
    {
        return -1; 
    }
    //reach the target node 
    if(root==target)    // if we reach the target node, we do not do the traversals. 
    {
        printAtLevelK(target,k); 
        return 0;        // distance will be zero if you are standing at the target node 
    }
    
    
    //other case 
    // We are not at the target node but that target node is either present in the left or present in the right  
    int DL = printNodesAtDistanceK(root->left,target,k); 
    if(DL!=-1)
    {
        // 2 cases 
        // Print the current node 
        if(DL + 1 == k)
        {
            cout<< root->data; 
        }
        // or print some nodes in the rightsubtree 
        else
        {
            printAtLevelK(root->right,k-2-DL); 
        }
        
        return 1 + DL; 
    }
    
    int DR = printNodesAtDistanceK(root->right,target,k); 
    if(DR!=-1)
    {
        //2 cases 
        //print current node 
        if(DR + 1 == k)
        {
            cout << root -> data <<" "; 
        }
        else
        {
            printAtLevelK(root->left,k-2-DR); 
        }
        return 1 + DR;
    }
    return -1; 
}

 int main()
{
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->left = new node(7);
	root->left->right->right = new node(8);
	root->left->right->right->left = new node(9); 
    
    // Target Node 5
    node * target = root->left->right;
    
    int k = 2; 
}





int findClosestInBST(Node* root,int target)
{
   //todo 
    
   int closest;     
   int diff = INT_MAX; 
   
   Node*temp=root; 

   while(temp!=NULL)
   {
       if current_diff = abs(temp->key - target); 
       
       if(current_diff==0)
       {
           return temp->key; 
       }
       
     if(current_diff < diff)
     {
         diff = current_diff; 
         closest = temp->key; // this closest stores the right answer 
     }
       
       
       //right or left 
       if(temp->key < target)
       {
           temp = temp->right; 
       }
       else
       {
           temp = temp->left; 
       }
   }
   return closest; 
    
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



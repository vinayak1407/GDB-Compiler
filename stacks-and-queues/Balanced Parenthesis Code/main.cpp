#include<iostream>
#include<stack> 
#include<string> 
using namespace std; 

bool isBalanced(string input){ 
    //Todo: Complete this method
    stack<char> s; 
    for(auto ch: input)   
    {
        switch(ch)
        {
            case '(':
            case '[':
            case '{': s.push(ch); 
                        break; 
            
            case ')': if(!s.empty() and s.top()=='(')
                      {
                      s.pop(); 
                      }
                      else 
                      {
                          return false; 
                      }
                        break; 
                      
            
            case ']': if(!s.empty() and s.top()=='[')
                      {
                      s.pop(); 
                      }
                      else 
                      {
                          return false; 
                      }
                      break; 
            
            case '}': if(!s.empty() and s.top()=='{')
                      {
                      s.pop(); 
                      }
                      else 
                      {
                          return false; 
                      }
                      break; 
        
            default: continue; 
        }
    }
    
    if(s.empty()==true)
    {
        return true; 
    }
    cout << "here"; 
    return false; 
}     


int main(){ 
      string s = "((a+b+c)+[d])"; //{a + (b+c) + ([d+e]*f)) } + k "; 
   
   if(isBalanced(s)){ 
        cout<<"Balanced!"<<endl; //https:www.onlinegdb.com/?dest_fid=60002014#tab-stdin
    } 
   else 
   {
        cout<<"Not Balancedss   "<<endl; 
   }    
        return 0; 
}

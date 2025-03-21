#include<iostream> 
#include<string> 
#include<sstream> 
#include<vector> 
using namespace std;

string simplifyPath(string path) {     // if the path has forward slash at the 0th index, it's an absolute path and it should be handled in a different manner from the relative path 
      // 1. Step - Tokenisation and Filtering 
      
      istringstream iss(path); 
      vector<string> tokens; 
      
      string token; 
      while(getline(iss,token,'/'))
      {
          if(token == " . " or token == " ")
          {                                       // Filtered out the dot tokens and filtered out the redundant forward slashes because they are also not useful 
              continue; 
          }
          tokens.push_back(token); 
      }
       
        for(string t:tokens)
        {
            cout<<t << " ,"; 
        }
      
      // 2. Handle ... 
      vector<string> stack;  // we will need to access some elements by the index also, which is not available inside a stack object   
                            // Using vector as a stack because it has push back and pop_back operations 
      if(path[0]=='/')
      {   
          // special case that denotes that our path is an absolute path (defined with respect to root directory) 
          stack.push_back(" ");  // in case of an absolute path, you inserted a null inside the stack 
      } 
      
      for(string token : tokens)
      {
        if(token=="..")
        {
            // 2 cases -> Abs path or relative path 
            if(stack.size()==0 or stack[stack.size()-1]=="..")
            {
                stack.push_back("..")
            }
            
            else if(stack[stack.size()-1]!="")  //for absolute path 
            {
                stack.pop_back();   
            }
            
        }
         else
         {
             //x,y,z.......
             stack.push_back(token); 
         }
          
      }
      // Single element 
      if(stack.size()==1 and stack[0]==" ")
      {
          return "/"; 
      }
      
      // Combine all elements in stack to get the answer. 
      ostringstream oss;
      int i = 0; 
      for(auto token: stack)
      {
          if(i!=0){
              oss<<"/"; 
          }
          i++; 
          oss << token << "/"; 
      }
        return oss.str(); 
} 

// We don't have two particular types of cases- one case where we have a single dot and another case where we have a forward slash which is not useful 




int main()
{ 
   string path = "/../x/y/../z/././w/a///../..//./";  // it is an absolute path, it starts from the root  
   // Output: /x/z/c
   cout << simplifyPath(path)<<endl;  
   return 0; 
}
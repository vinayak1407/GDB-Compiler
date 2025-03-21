#include<iostream>
#include<map>
using namespace std;

/*
1. Generate all substrings
2. Generate their hash
3. Hash the 'hash' values to club all anagrams in single bucket, to get their frequency count
4. From freq count, we can easily count the paris
*/

vector<int> getHashValue(string s,int i,int j)
{
    vector<int> freq(26,0); 
     
    //iterate over the original string from i to j to fill this vector  
    for(int k=i;k<=j;k++)
    {
        char ch = s[k]; 
        freq[ch-'a']++; 
    }
    
    return freq;  
}




int anagrams_substrings(string s) {  
    map<vector<int>, int> m;                         // the key is a vector and a value is a frequency
    
    
    for(int i=0;i<s.length();i++)        
    {                                          
        for(int j=i;j<s.length();j++)
        {                                   // All this is going to take O(N^2) time 
            //Substring S[i......j]
            vector<int> h =getHashValue(s,i,j);  // Generates a vector of length 26 but still in the worst case we are iterating over the entire string to generate this vector, so it also takes N time 
            //put it inside a map
            m[h]++;  // the number of times the same vector is generating, we are increasing it frequency in a hashmap.  
        }
    }
    
    //pairs 
    int ans = 0; 
    for(auto p: m)       // in the worst case, this hashmap will store N^2 entries. 
    {
        int freq = p.second;
        if(freq>=2)
        {
            ans+=(freq)*(freq-1)/2; 
        }
    }
    
    return ans; 
}
        

 int main(){
	string s;
	cin>>s;

    cout<<anagrams_substrings(s)<<endl; 
	return 0;
  }
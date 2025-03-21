#include<iostream> 
#include<queue>
using namespace std; 

int main()
{
    // First Non- Repeating character in the running stream
    queue<char>q;
    int freq[27] = {0}; //created a frequency map of 27 elements and initialised it to 0
    char ch; 
    cin>> ch; 
    
    while(ch!='.')
    {
        //letter 
        q.push(ch);
        freq[ch-'a']++;     //ch-a gives us the right index
        
        //query-> remove all chars from front of queue till you get a char with freq 1
        while(!q.empty())
        {
            int idx = q.front() - 'a'; 
            if(freq[idx]>1)
            {
                q.pop(); 
            }
            else
            {
                cout<< q.front()<<endl; 
            }
        }
        
        if(q.empty())
        {
            cout<<"-1"<<endl; 
        }
        cin>>ch; 
    }
    
    
}
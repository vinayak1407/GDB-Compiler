#include<iostream>
#include<unordered_map>
using namespace std;


//Build a Prefix Tree - Trie
class Node{
public:
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;

	Node(char d){
		data = d;
		isTerminal = false;
	}
};


class SuffixTrie{

	Node*root;
public:
	SuffixTrie(){
		root = new Node('\0');
	}

	//later
	void insert_helper(string word){    // which inserts a particular word in the trie 

		Node* temp = root;

		for(char ch : word){

			if(temp->m.count(ch)==0){
				Node *n = new Node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}

		temp->isTerminal = true;
	 
	  void insert(string word)
	  {
	      //pick all substrings from (i,eos) and call the insert_helper function 
          for(int i=0;word[o]!='\0';i++)
          {
              insert_helper(word.substr(i));     // creating all possible substrings using for loop and creating them inside a trie                       
          }
	  }
	    
     }

	bool search(string word){

		Node*temp = root;

		for(char ch : word){

			if(temp->m.count(ch)==0){
				return false;
			}
			temp = temp->m[ch];


		}
		return temp->isTerminal;
	}
};


int main(){
        
        //Simplified Suffix Trie 
		string input = "hello";
		string suffixes[] = ["lo","ell","hello"];
        
        SuffixTrie t; 
        t.insert(input);     // it will insert all the suffixes 

        for(auto sf: suffixes)
        {
            if(t.search(sf))     // search function remains same as trie 
            {
                cout<<"yes"; 
            }
            else
            {
                cout<<"no"; 
            }
        }




		return 0;
}

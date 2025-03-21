#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Car {
 
 public:
 
    string id;
    int x, y; 
    Car(string id, int x, int y) 
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
  
  int dist() const{
      return x*x + y*y;       // at any car the distance from the origin is x^2 + y^2
  }
};

class CarCompare{
public:     
   bool operator()(const Car A, const Car B){           // we are not going to modify any of the data members of class A and class B, we are just going to do a comparison based upon the distance  
       return A.dist() < B.dist();  // this comparison is basically for a max heap 
   } 
}; 
 
  
 void printNearestCars(vector<Car> cars, int k) 
 {
    // create a maxheap of size k 
    priority_queue<Car, vector<Car> , CarCompare> max_heap(cars.begin(),cars.begin() + k);    // your heap is initialised and first k cars are already inside the heap 
     
    //remaining cars  
    for(int i=k; i<cars.size();i++)
    {
        auto car = cars[i];
        
        if(cars.dist() < max_heap.top().dist())   //if the distance of the current car is less than the largest distance that i have inside the heap, then i am going to replace that node inside the heap  
        {
            max_heap.pop();  // removes the root node largest 
            max_heap.push(car); 
        }
    }
     
    // print all the cars inside the heap that will be the smallest one 
    vector<Car> output; 
    while(!max_heap.empty())
    {
      // cout<< max_heap.top().id <<endl;
      output.push_back(max_heap.top()); 
      max_heap.pop(); 
    }
     
    //vector of k nearest cars  
    reverse(output.begin(),output.end(),distCompare);  // compare cars based upon distance   
     
    for(auto car : output)
    {
        cout << car.id <<endl; 
    }
    
     
    return;  
 }
 
 
int main() {
 
 
  int N, K;
  cin>>N>K; 
  
  string id;  
  int x,y; 
  
  vector<Car> cars; 
  
  for(int i=0;i<N;i++)
  {
      cin>> id>>x>>y; 
      Car car(id,x,y); 
      cars.push_back(car); 
  }
      
  printNearestCars(cars,K); 
  return 0; 
}
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }

    // min heap
    bool operator<(const Car &obj) const {
        return this->distSq > obj.distSq;  // min heap
    }
};

void nearestCars(vector<pair<int, int>> &pos, int k){
    vector<Car> cars;
    for(int i = 0; i < pos.size(); i++){
        int x = pos[i].first;
        int y = pos[i].second;
        int distSq = x*x + y*y;
        cars.push_back(Car(i, distSq));  //O(n)  car objects created
    }
    
    priority_queue<Car> pq( cars.begin(), cars.end());  // O(n)  best time complexacity heap created




    // for(int i = 0; i < cars.size(); i++){   // O(log n)   large  time complexcity 
    //     pq.push(cars[i]);  
    // }                  


    for(int i = 0; i < k; i++){   // O(k log n)
        Car c = pq.top();  // O(1)
        pq.pop();
        cout << "Car " << c.idx << " at distance " << c.distSq << endl;
    }
}

int main(){

    vector<pair<int, int>> pos = {
        {0, 25},
        {1, 16},
        {2, 9},
        {3, 4},
        {4, 1}
    };

    int k = 3;

    nearestCars(pos, k);

    return 0;
}
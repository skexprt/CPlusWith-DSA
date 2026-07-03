#include<bits/stdc++.h>
#include<queue>
#include<string>
using namespace std;

int main(){
    // priority_queue<int> pq; // max-heap by default

    // priority_queue<int, vector<int>, greater<int>> pq; // min-heap implementation
    // pq.push(5);
    // pq.push(10);
    // pq.push(3);
    // pq.push(8);
    // pq.push(1);
    

    priority_queue<string> pq; // max-heap by default
    // priority_queue<string, vector<string>, greater<string>> pq; // min-heap asinding order implementation
    pq.push("mango");
    pq.push("apple");
    pq.push("banana");
    pq.push("grapes");
    pq.push("orange");
    

    while (!pq.empty())
    {
        cout << "Elements in priority queue (max-heap):" <<pq.top()<< endl;
        pq.pop();
    }

    return 0;
}

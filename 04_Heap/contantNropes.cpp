#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int contantNropes(vector<int> ropes ){

    priority_queue<int,vector<int>,greater<int>> pq(ropes.begin(),ropes.end());
    int cost = 0;

    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost += first + second;
        pq.push(first + second);
    }

    cout << "Min cost to connect ropes: " << cost << endl;
    return cost;
    
}

int main(){

    vector<int> ropes = {4,3,2,6};
    contantNropes(ropes);

 return 0;
}

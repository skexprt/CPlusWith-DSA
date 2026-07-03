#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<double, int> p1,pair<double, int> p2){
    return p1.first > p2.first; // descending based on ratio
}

int fractionalKnapsack(int capacity, vector<int> value, vector<int> weight){
    int n = value.size();
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0));

    for(int i = 0; i < n; i++){
        double r = value[i] / (double) weight[i];
        ratio[i] = make_pair(r, i);
    }
    sort(ratio.begin(), ratio.end(), compare);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = ratio[i].second;   // wight ,value of return index
        if(capacity >= weight[idx]){
            ans += value[idx];
            capacity -= weight[idx];
        }else{
            ans += ratio[i].first * capacity;
            capacity = 0;
             break;
        }
    }
    
    cout<< "max value :"<< ans << endl;
}
int main(){
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20,30};
    int capacity = 50;
    fractionalKnapsack(capacity, value, weight);

    return 0;
}
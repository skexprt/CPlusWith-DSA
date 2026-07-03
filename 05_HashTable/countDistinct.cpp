#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int countDistinct(vector<int> &arr) {
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }

    cout << "Distinct elements are: ";
    for (auto it : s)
    {
        cout << it << " ";
    }
    

    return s.size();
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 4, 1, 5};
    cout << "\nNumber of distinct elements: " << countDistinct(arr) << endl;

    return 0;
}
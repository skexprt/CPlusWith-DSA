#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void unionOfArrays(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<int> s;

    for (int num : arr1) {
        s.insert(num);
    }
    for (int num : arr2) {
        s.insert(num);
    }

    cout << "Union of arrays: ";
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
}

void intersectionOfArrays(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<int> s(arr1.begin(), arr1.end());

    cout << "Intersection of arrays: ";
    for (int num : arr2) {
        if (s.find(num) != s.end()) {
            cout << num << " ";
            s.erase(num); // Remove to handle duplicates if present
        }
    }
    cout << endl;
}

int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {4, 5, 6, 7, 8};

    unionOfArrays(arr1, arr2);
    intersectionOfArrays(arr1, arr2);

    return 0;
}
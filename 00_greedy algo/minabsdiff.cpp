#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; ++i) cin >> arr[i];

//     sort(arr.begin(), arr.end()); // Greedy: sort to bring close values together

//     int minDiff = INT_MAX;
//     for(int i=1; i<n; ++i) {
//         minDiff = min(minDiff, abs(arr[i] - arr[i-1]));
//     }

//     cout << minDiff << endl;
//     return 0;
// }

int main(){
    vector<int> A = {1, 2, 3};
    vector<int> B = {2, 1, 3};

    int n = A.size();
    
    sort(A.begin(), A.end()); 
    sort(B.begin(), B.end()); 

    int minDiff = 0;

    for (int i = 0; i < n; i++)
    {
        minDiff += abs(A[i] - B[i]);
    }
    cout << "minimum absolute difference: "<< minDiff << endl;
    return 0;
}
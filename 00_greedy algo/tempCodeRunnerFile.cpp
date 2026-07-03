int main() {
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
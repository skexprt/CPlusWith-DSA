#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void slidingWindowMax(const vector<int> &arr, int k) {
    // Naive approach using max-heap (priority queue)
    priority_queue<pair<int, int>> pq; // pair<value, index>

    // 1st window
    for (int i = 0; i < k; i++){
        pq.push(make_pair(arr[i], i));
    }

    cout << pq.top().first << " ";

    for (int i = k; i < arr.size(); i++)
    {
        while (!pq.empty() && pq.top().second <= i - k) {  // Remove elements not in the current window
            pq.pop();
        }
        
        pq.push(make_pair(arr[i], i)); // Add current element
        cout << pq.top().first << " "; // The top of the heap is the largest element for the current window
    }
    
    
    cout << endl;


















    // deque<int> dq;
    // vector<int> result;

    // for(int i = 0; i < arr.size(); i++) {
    //     // Remove elements not in the current window
    //     if(!dq.empty() && dq.front() == i - k) {
    //         dq.pop_front();
    //     }

    //     // Remove elements smaller than the current element from the back
    //     while(!dq.empty() && arr[dq.back()] < arr[i]) {
    //         dq.pop_back();
    //     }

    //     // Add current element at the back of the deque
    //     dq.push_back(i);

    //     // The front of the deque is the largest element for the current window
    //     if(i >= k - 1) {
    //         result.push_back(arr[dq.front()]);
    //     }
    // }

    // // Print the result
    // for(int maxVal : result) {
    //     cout << maxVal << " ";
    // }
    // cout << endl;
}

int main(){
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    slidingWindowMax(arr, k);


    return 0;
}
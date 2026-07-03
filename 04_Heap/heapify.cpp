#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int>& arr, int i, int n) {
    int MaxI = i; // Initialize MaxI as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[MaxI])
        MaxI = left;

    // If right child is larger than MaxI so far
    if (right < n && arr[right] > arr[MaxI])
        MaxI = right;

    // If MaxI is not root
    if (MaxI != i) {
        swap(arr[i], arr[MaxI]);
        // Recursively heapify the affected sub-tree
        heapify(arr, MaxI, n);
    }
}

void buildHeap(vector<int>& arr, int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;
 
    // step:1
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {  //O(n*logn)
        heapify(arr, i, n );
    }
    // step:2
    for (int i = n-1; i >= 0; i--)  //O(n*logn)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
    
}

void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3, 7};
    int n = arr.size();

    buildHeap(arr, n);

    cout << "Max-Heap array: ";
    printArray(arr);

    return 0;
}
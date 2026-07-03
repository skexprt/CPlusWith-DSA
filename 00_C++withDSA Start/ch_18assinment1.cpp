#include<iostream>
#include<vector>
using namespace std;
void merge(string arr[], int lo, int mid, int hi){
    int m =mid;
    int n = hi;

    vector<string>temp;

    int i = lo;
    int j = mid+1;

    while (i <= m && j <= n)
    {
        if (arr[i]<= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
        
    }
    while (i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= n)
    {
        temp.push_back(arr[j]);
        j++;
    }
    
    for (int idx = 0, x=lo; x <=hi; x++)
    {
        arr[x] = temp[idx++];
    } 
}
void mergesort(string arr[], int  lo, int hi){
    if (lo >= hi)
    {
        return;
    }

    int mid = lo + (hi-lo)/2;
    mergesort(arr , lo, mid);
    mergesort(arr, mid+1, hi);
    
    merge(arr, lo,mid , hi);
    
}
int main(){
    string arr[4] = {"SUN" , "EARTH", "MARS","MERCURY"};
    mergesort(arr, 0, 3);

    for (int i = 0; i < 4; i++)
    {
       cout<< arr[i]<<endl;
    }
    return 0;
}

// // easy way me 
// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to merge two halves of the array
// void merge(vector<string>& arr, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
//     vector<string> L(n1), R(n2);

//     // Copy data to temporary arrays L[] and R[]
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     // Merge the temporary arrays back into arr[left..right]
//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of L[], if any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of R[], if any
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// // Function to perform Merge Sort
// void mergeSort(vector<string>& arr, int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }

// int main() {
//     vector<string> arr = {"apple", "orange", "banana", "grape", "cherry"};

//     mergeSort(arr, 0, arr.size() - 1);

//     cout << "Sorted array of strings:\n";
//     for (const string& s : arr)
//         cout << s << " ";
//     cout << endl;

//     return 0;
// }
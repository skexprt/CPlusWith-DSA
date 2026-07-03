#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    unordered_map<int, int> m;
    int arr[] = {1, 2, 7, 11, 15, 5, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 9;

    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];
        if (m.count(complement))
        {
            cout << "Pair found: (" << m[complement] << ", " << i << ")\n" << endl;
            break;
        }
        m[arr[i]] = i;
    }
    
    return 0;
}

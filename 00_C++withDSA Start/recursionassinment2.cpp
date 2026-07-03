#include<iostream>
using namespace std;
void alloccurences(int arr[],int key , int i , int n){
    if (i == n)
    {
        return;
    }
    if (arr[i]== key)
    {
        cout<< i <<endl;

    }
 alloccurences(arr , key, i+1, n);    
}
int main(){
    int arr[]= {1,3,2,7,2,2,3,4,2};
    int n =sizeof(arr)/sizeof(arr[0]);
    alloccurences(arr, 2, 0, n);
    return 0;
}
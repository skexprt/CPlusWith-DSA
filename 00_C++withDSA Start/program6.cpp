#include<iostream>
#include<climits>
using namespace std;
void subarraysumMax( int *arr, int n){
    int maxSum = INT_MIN;
  for (int start = 0; start < n; start++)
  {  
    int currentsum=0;
    for (int end = start; end < n; end++)
    {
        currentsum+=arr[end];
        maxSum=max(maxSum , currentsum );
    }
  }
  cout<< "maximum sabarray sum ="<< maxSum<<endl; 
}
int main(){
   int arr[]={ 2,-3,6,-5,4,2};
   int n= sizeof(arr)/sizeof(int);
   subarraysumMax(arr ,n);
    return 0;
}
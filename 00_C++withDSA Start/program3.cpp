#include<iostream>
using namespace std;
int binsearch( int *arr , int n , int key){
    int sta =0, end=n-1;
    while (sta<=end)
    {  
        int mid= (sta+end)/2;
      if (arr[mid]==key)
      {
          return mid; 
      }else if (arr[mid] < key)
      {
        mid= mid+1;
      }else{
        mid=mid-1;
      }
      
      
    } 
    return -1;
}
int main(){
    int arr[]={2,3,46,12,3,54,4};
    int n=sizeof(arr)/sizeof(int);
    cout<<binsearch( arr , n , 12)<<endl;
     
    return 0;
}
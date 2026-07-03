#include<iostream>
using namespace std;
int binsearch(int arr[], int si, int ei, int key){
    if (si>ei)
    {
        return -1;
    }
    int mid = si+(ei-si)/2;
    if (arr[mid] == key)
    {
        return mid;
    }else if(arr[mid]>key){
        return binsearch(arr, si, mid-1,key);
    }else{
        return binsearch(arr, mid+1,ei, key);
    }

}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    cout <<binsearch( arr,1, 7, 5)<<endl;
    return 0;
}
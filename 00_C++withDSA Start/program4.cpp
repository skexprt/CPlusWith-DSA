#include<iostream>
using namespace std;
int printArr( int *ptr , int n){
    for (int i = 0; i < n; i++)
    {
       cout <<*ptr<<"\n";
       ptr=ptr+1;
    }
    
}
int main(){
int arr []={1,2,3,4,5};
int n=sizeof(arr) /sizeof(int);
printArr(arr ,n);
    return 0;
}
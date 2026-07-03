#include<iostream>
using namespace std;
int main(){
    int arr[][3]={{1,4,9},{11,4,3},{2,2,3}};
    int n=3;
    int m=3;
     int sum=0;

    //  sum of second row element
    for (int j = 0; j < m; j++)
    {
       sum += arr[1][j];
    }
    cout<< "sum of second row element ="<<sum<<endl;
    return 0;
}
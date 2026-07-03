#include<iostream>
using namespace std;
int main(){
    int n=10829;
    int digsum=0;
    while (n>0)
    {
     int lastDig=n%10;
     if(lastDig%2!=0)
     digsum+= lastDig;
     n= n/10;

    }
    cout<<"sum="<<digsum<<endl;
    return 0;
}
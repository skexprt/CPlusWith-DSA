#include<iostream>
using namespace std;
int main(){
    int n=10829;
    while (n>0)
    {
      int lastDig=n%10;
      cout<<lastDig<<" ";
      n=n/10;
    }
    cout<<endl;
    return 0;
}
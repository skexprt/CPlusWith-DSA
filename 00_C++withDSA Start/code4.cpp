#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter he number :";
    cin>>n;
     int sum=0;
    for ( int num=1;num<=n;num++){
         sum +=num;
    }
    cout<<"sum="<<sum<<endl;
    return 0;
}
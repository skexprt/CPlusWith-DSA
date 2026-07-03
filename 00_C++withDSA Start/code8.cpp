#include<iostream>
using namespace std;
int main(){
    int n;
    bool isprime=true;
    cout <<"enter th number:";
    cin>>n;
    for (int i = 2; i <= n-1; i++)
    {
        if (n%i==0)  //i is a factor of n;i copletely divide n; nis a not-prime ;
        {
            isprime=false;
            break;
        }
        
    }
    if (isprime)
    {
        cout<<"number is prime "<<endl;

    } else{
        cout<< "number is not prime"<<endl;
    }
    
    return 0;
}
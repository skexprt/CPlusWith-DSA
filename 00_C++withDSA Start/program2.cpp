#include<iostream>
using namespace std;
int res=0;
int sum=0;
int reverse(int n){
    while (n>0)
    {
    
    int lastdig=n%10;
     res=res*10+lastdig;
     // sum +=lastdig;
    n=n/10;
    }
        cout<<res<<endl;
       // cout<<sum<<endl;
   
     return res;
}
int palindrome(int n){
      reverse(n);
      if (res==n)
      {
        cout<<"n is a palindome number"<<endl;
      }else{

        cout<<"n is  not a palindome number"<<endl;
      }
      
}
int main(){
    int num;
    cout<<"enter the number :";
    cin>>num;
   // palindrome(num);
   reverse(num);
    return 0;
}
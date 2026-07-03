#include<iostream>
using namespace std;
int main(){
   int income;
   float tax;
   cout<<"enter your income (in lakhs): ";
   cin>>income;

   if( income <5){
    // 0%
    tax=0;
   } else if( income<=10){
    // 20%
    tax=0.2* income;
   } else{
    // 30%
    tax =0.3*income;
   }
   cout<<"tax="<<(tax *100000)<<endl;
    return 0;
}
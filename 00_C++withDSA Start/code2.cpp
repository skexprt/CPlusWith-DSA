#include<iostream>
using  namespace std;
int main(){
    int a,b;
    char op;
    cout<<" enter the number a:";
    cin>>a;
    cout<<" enter the number b:";
    cin>>b;
    cout<<" enter operater( +,-,*,/):";
    cin>>op;
// calculator
cout<<"using by if-else statement";
if(op=='+'){
  cout<<"(a+b)="<<(a+b)<<endl;
}else if(op=='-'){
  cout<<"(a-b)="<<(a-b)<<endl;
}else if(op=='*'){
  cout<<"(a*b)="<<(a*b)<<endl;
}else if(op=='/'){
  cout<<"(a/b)="<<(a/b)<<endl;

}else{
    cout<<"invailid operater";
}
// using by switch statement
cout<<"using by switch statement";
switch (op)
{
case'+':cout<<"(a+b)="<<(a+b)<<endl;
  break;
case'-':cout<<"(a-b)="<<(a-b)<<endl;
  break;
  case'*':cout<<"(a*b)="<<(a*b)<<endl;
  break;
  case'/':cout<<"(a/b)="<<(a/b)<<endl;
  break;
default:cout<<"invailid operater"<<endl;
  break;
}
    return 0;
}
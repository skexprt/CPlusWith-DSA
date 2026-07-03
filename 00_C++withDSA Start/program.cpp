#include<iostream>
using namespace std;
int main(){
      int n=371;
      int num=n;
      int sum =0;
      while (n>0)
      {
            int lastdig =n%10;
            sum+=lastdig*lastdig*lastdig;
            n=n/10;
      }
      if (num==sum)
      {
         cout<<"is a amstrong\n";
      }else{
            cout<<"not is a amstrong\n";
      }
      
  return 0;
}
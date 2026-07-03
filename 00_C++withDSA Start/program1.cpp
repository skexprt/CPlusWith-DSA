#include<iostream>
using namespace std;
int main(){
    int n=12;
       for (int i = 2; i <=n; i++)
       {
          int curr=i;
          bool isprime=true;
          for (int j = 2; j <=curr/2; j++)
          {
            if (curr%j==0)
            {
                isprime=false;
            }
          }
         if (isprime)
         {
            cout<<curr<<"\n";
         }
          
       }
       
        

    
    return 0;
}
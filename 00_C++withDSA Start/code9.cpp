#include<iostream>
using namespace std;
int main(){
    int n=6;
    int fact=1;
    for (int i = 1; i <=n; i++)
    {
        fact*=i;
    }
    cout<<n<<"\tis fact number:"<<fact<<endl;
  return 0;
}
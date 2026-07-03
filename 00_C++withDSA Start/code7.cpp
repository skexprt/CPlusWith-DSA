#include<iostream>
using namespace std;
int main(){
    int n;
    do
    {
        cout<<"enter number";
        cin>>n;
        if (n%10==0)
        {
            break;
        }
        cout<<"your entered number ="<<n<<endl;
    } while (true);
    
    
    return 0;
}
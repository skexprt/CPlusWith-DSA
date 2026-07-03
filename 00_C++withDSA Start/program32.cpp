#include<iostream>
using namespace std; 
void FastExpon(int x, int n){
    int ans =1;
    while (n >0)
    {
        int lastbit = n & 1;

        if (lastbit)
        {
            ans = ans * x;

        }
        x = x * x;
        n = n >> 1 ;
    }
    cout << ans << endl;

}

int main(){
   FastExpon(3,4);
   FastExpon(3,5);
    return 0;
}
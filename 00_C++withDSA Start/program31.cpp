#include<iostream>
using namespace std;
int countsetbits(int num){
    int count = 0;

    while (num >0)
    {
        int lastdig = num & 1;

        count += lastdig;

        num =num >> 1;
    }
    cout<<count<<endl;
    return count;
}

int main(){
   
   countsetbits(10);
   countsetbits(7);
    return 0;
}
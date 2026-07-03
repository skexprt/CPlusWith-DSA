#include<iostream>
using namespace std;

int getithbit(int num , int i){
    int bitmask = 1<< i;

    if (!(num & bitmask))
    {
        return 0;
    }else{
        return 1;
    }
    
}

bool ispowerof2(int num){
    if (!(num & (num-1)))
    {
        return true;
    }else{
        return false;
    }
    
}
int main(){

 cout<<getithbit(6,2)<<endl;
 cout<<getithbit(7,1)<<endl;

 cout<<ispowerof2(5)<<endl;
    return 0;
}
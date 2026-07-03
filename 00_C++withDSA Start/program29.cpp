#include<iostream>
using namespace std;
// oddoreven number
void oddoreven(int num){
    if ((num & 1)==0)
    {
       cout<<"even\n";
    }else{
        cout<<"odd\n";
    }
    
}
int main(){
    oddoreven(34);
    oddoreven(35);
    return 0;
}
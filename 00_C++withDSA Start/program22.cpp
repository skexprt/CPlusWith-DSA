#include<bits/stdc++.h>
using namespace std;
int vowcount(string str){
    int vowcount=0;
    for (int i = 0; i < str.length(); i++)
    {
       if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] =='o' || str[i] == 'u'){
        vowcount++;
       }
    }
    return vowcount;
}
int main(){

   string str="grammer";
   vowcount(str);
   cout<< vowcount(str)<<endl;
    return 0;


}
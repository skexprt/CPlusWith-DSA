#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
map<int ,string> m;
m[100] = "Shiva";
m[110] = "Shivam";
m[120] = "Shivangi";
m[130] = "Suman";


m[110] = "Shivam Kumar"; //updates the value at key 110


m.insert({140,"Shafqat"}); //inserts a new key-value pair

cout<<m[120]<<endl; //indexing operator
cout<<m.at(120)<<endl; //at function
cout<<m.size()<<endl; //size function
cout<<m.count(130)<<endl; //count function
m.erase(130); //erase function


// auto print value using iterator
for(auto i:m){  
    cout<<i.first<<" :"<<i.second<<endl;
}
return 0;

}
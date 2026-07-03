#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){

    // unordered_map<string, int> m;  
    map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;
    m["Yurop"] = 70;
    m["India"] = 200; // ourwrite key->value


    m.erase("Yurop"); // Delete key pain

    for(pair<string , int> Country : m){
        cout << Country.first << "," << Country.second <<endl;
    }

    if (m.count("India"))
    {
        cout << "India is exist\n" << endl;
    }else{
        cout << "India dose't exist\n" << endl;
    }
    

    return 0;
}
#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;

    s.insert(1);
    s.insert(4);
    s.insert(7);
    s.insert(8);
    s.insert(1);  //doublicate value not store in a set

    cout<< s.size() << endl;

    s.erase(7);
    
    if (s.find(7) != s.end())
    {
        cout<< "number exist \n" << endl;
    }else{
        cout<< "number dosn't exist \n" << endl;
    }

    for (auto el : s)
    {
        cout<< el << " " ;
    }
    cout<< endl;
    
    

    return 0;
}
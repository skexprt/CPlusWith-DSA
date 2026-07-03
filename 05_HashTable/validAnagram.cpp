#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool validAnagram(string s1, string s2){

    if (s1.length() != s2.length()){
        return false;
    }

    unordered_map<char, int> m;

    for (char c : s1){
        m[c]++;
    }

    for (char c : s2){
        if (m.count(c) == 0){
            return false;
        }
        else{
            m[c]--;
            if (m[c] == 0){
                m.erase(c);
            }
        }
    }

    return m.empty();
}

int main(){

    string s1 = "listen";
    string s2 = "silent";

    if (validAnagram(s1, s2)){
        cout << "Ha Shiva "<< s1 << " and " << s2 << " are anagrams." << endl;
    }
    else{
        cout << "No Shiva " << s1 << " and " << s2 << " are not anagrams." << endl;
    }

    return 0;
}
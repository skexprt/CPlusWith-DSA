#include<iostream>
using namespace std;
void remooveDublicate(string str, string ans, int i, int map[26]){

    if (i == str.size())
    {
        cout<<"ans ="<<ans<<endl;
        return;
    }
    

    char ch = str[i];
    int  mapIdx = (int)(ch-'a');
    if (map[mapIdx])
    {
        remooveDublicate(str, ans, i+1, map);
    }else{
        map[mapIdx]= true;
        remooveDublicate(str, ans+str[i],i+1, map);
    }
    
}
int main(){
    string str = "shivanad";
    string ans = " ";
    int map[26]={false};
    remooveDublicate(str, ans, 0, map);
    return 0;
}
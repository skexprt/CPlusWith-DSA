#include<iostream>
using namespace std;
// void binstring(int n, int lasPlace, string ans){
//     if (n==0)
//     {
//         cout<<ans<<endl;
//         return;
//     }
//     if (lasPlace != 1)
//     {
//         binstring(n-1, 0 , ans+'0');
//         binstring(n-1, 1 , ans+'1');
//     }else{
//         binstring(n-1, 0 , ans+'0');

//     }    
// }
void binstring(int n, string ans){
    if (n==0)
    {
        cout<<ans<<endl;
        return;
    }if (ans[ans.size()-1]!= '1')
    {
        binstring(n-1, ans+'0');
        binstring(n-1, ans+'1');
    }else{
        binstring(n-1, ans+'0');

    }    
}
int main(){
    string ans = "";
    binstring(3, ans);
    return 0;
}
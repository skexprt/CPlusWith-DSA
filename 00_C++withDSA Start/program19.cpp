#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// void toUpper(char word[], int n){
//     for (int  i = 0; i < n; i++)
//     {
//       char ch= word[i];
//       if (ch>='a' && ch<= 'z')
//       {
//          continue;
//       } else{
//         word[i] = ch-'A' + 'a';
//       }
       
//     }
// }
// int main(){
//     char word[]="ApPle";
//     toUpper(word, strlen(word));

//   cout<< word<<endl;
//     return 0;
// }
void reverse (char word[], int n){
    int st= 0, end =n-1;
    while (st < end)
    {
       swap(word[st] , word[end]);
        st++;
        end--;
    }
    
}
int main(){
    char word[]= "code";
    reverse(word, strlen(word));

    cout<<"reverse="<<word<<endl;

    return 0;
}
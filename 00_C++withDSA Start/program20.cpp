
#include<bits/stdc++.h>
using namespace std;
bool ispalindrom(char word[], int n){
 int st = 0 , end = n-1;
 while (st < end)
 {
    if ( word[st] != word[end])
    {
        cout<< "not valid palindrome\n";
        return false;
    }
    st++;
    end--;
 }
  cout<<"valid palindrome\n";
  return true;

}
int main(){
    char word[]= "racecar";
    ispalindrom(word , strlen(word));
    return 0;
}
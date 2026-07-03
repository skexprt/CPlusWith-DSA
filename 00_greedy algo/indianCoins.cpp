#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minCoins(int amount, vector<int>coins){
   int ans = 0;
   int n = coins.size();
   for(int i = n-1; i > 0 && amount > 0; i--){
         if(amount >= coins[i]){
            ans += amount / coins[i]; // count how many coins of this denomination can be used
            amount = amount % coins[i]; // update the remanding amount
         }
   } 
   cout << "minimum nmber of coins required:" << ans << endl;
   return ans;
}

int main(){
    int  n ;
    cout<< "Enter number of coins: ";
    cin >> n;
    vector<int> coins = {1, 2, 5, 10 , 20 , 50,100, 500, 1000, 2000};

    minCoins(n, coins);
    return 0;
}
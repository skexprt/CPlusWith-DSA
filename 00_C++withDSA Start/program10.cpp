#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool containsDuplicate(vector<int>& nums, int n){
 sort(nums.begin(), nums.end());

 for (int i = 1; i <nums.size(); i++)
 {
    if (nums[i-1] == nums[i])
    {
       return true;
    }
    
 }
 return false;
}
int main(){
    vector<int> nums ={2,2,3,4,5};
    int n=sizeof(nums)/sizeof(int);
    cout<<containsDuplicate(nums, n);
    return 0;
}
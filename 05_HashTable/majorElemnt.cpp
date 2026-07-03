#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void majorityElemnt(vector<int> nums){
    int n = nums.size();
    unordered_map<int , int>  m;

    for(int i = 0; i < n; i++){
        if (m.count(nums[i]))
        {
            m[nums[i]]++;
        }
        else
        {
            m[nums[i]] = 1;
        }
    }

    for (pair<int, int> p : m){
        if (p.second > n/3)
        {
            cout << p.first << endl;
        }
        
        cout<<"--"<<endl;
    }

}

int main(){
    
      vector<int> nums = { 1, 3, 2, 5, 1, 3, 1, 5, 1};

      majorityElemnt (nums);


    return 0;
}
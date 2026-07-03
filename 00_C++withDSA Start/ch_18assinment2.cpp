#include<iostream>
#include <vector>
using namespace std;

int countInRange(int nums[], int num , int lo , int hi){
    int count = 0;
    for (int  i = lo; i <= hi; i++)
    {
        if (nums[i] == num)
        {
            count++;
        }
        
    }
    return count;
}
int majorityElement(int nums[], int lo , int hi){
     // base case
     if (lo == hi)
     {
        return lo;
     }
     
     // recurse left and right 
     int mid = lo + (hi-lo)/2;
     int left = majorityElement(nums , lo , mid);
     int right = majorityElement(nums, mid+1 , hi);


     // 
     
}
int main(){
    int nums[] = {2,3,1.3,2,4,3};
    int n = 8;

    // majorityElement();

}

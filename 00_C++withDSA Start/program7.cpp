#include<iostream>
#include<climits>
using namespace std;
void maxprofit(int *prices , int n){
    int bestbuy[100000];
    bestbuy[0]= INT_MAX;
    cout<<bestbuy[0]<<",";
    for (int i = 1; i < n; i++)
    {
        bestbuy[i]=min(bestbuy[i-1],prices[i-1]);
        cout<< bestbuy[i]<<",";
    }
    cout <<endl;
    

}
int main(){
    int prices[]={7,1,5,3,6,4};
    int n=sizeof(prices)/sizeof(int);
    maxprofit(prices ,n);
    return 0;
}
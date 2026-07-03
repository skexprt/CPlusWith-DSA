#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(3);
    dq.push_front(2);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_front(1);

    dq.pop_back();
    dq.pop_front();
    dq.push_front(0);
    dq.pop_back();

    cout<< dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq.size() << endl;
    
    return 0;

}
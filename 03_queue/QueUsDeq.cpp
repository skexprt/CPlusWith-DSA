#include<iostream>
#include<deque>
using namespace std;

class Queue {
    deque<int> dq;
    public:
     void push(int x){
        dq.push_back(x);
     }
     void pop(){
        if (!dq.empty()){
            dq.pop_front();
        } else 
        {
            cout<<"Queue is empty"<<endl;
        }
     }
     int front(){
        if (!dq.empty()){
            return dq.front();
        }else
        {
            cout<<"Queue is empty"<<endl;
            return -1; 
        }
     }
     int back(){
        if (!dq.empty()){
            return dq.back();
        }else
        {
            cout << "Queue is empty"<<endl;
            return -1;
        }
     }
     bool empty(){
        return dq.empty();
     }
};
int main(){
     Queue q;
     for (int  i = 0; i <= 5; i++)
     {
           q.push(i);
     }
     for (int  i = 0; i <= 5; i++)
     {
        cout << q.front()<< " ";
        q.pop();
     }
     

    return 0;
}
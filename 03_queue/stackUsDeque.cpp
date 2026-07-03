#include<iostream>
#include<deque>
#include<stack>
using namespace std;

class Stack
{
private:
    deque<int> dq;
public:
    void push(int data){
        dq.push_front(data);
    }
    void pop(){
        if(!dq.empty()){
            dq.pop_front();
        }else{
            cout<<"Stack is empty, cannot pop."<<endl;
        }
    }
    int top(){
        if(!dq.empty()){
            return dq.front();
        }else{
            cout<<"Stack is empty, no top element."<<endl;
            return -1;
        }
    }
};   
int main(){
    Stack s;
    for (int i = 0; i <= 5; i++)
    {
        s.push(i);
    }
    for (int i = 0; i <= 5; i++)
    {
        cout<< s.top()<<endl;
        s.pop();
    }
    return 0;
}
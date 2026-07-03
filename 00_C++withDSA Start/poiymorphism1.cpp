#include<iostream>
using namespace std;
class Parent{
    public:
      virtual void hello(){
        cout<<"parent class\n";
      }
};
class Child :public Parent{
    public:
       void hello(){
        cout<<"child class\n";
       }
};
int main(){

/*Child class to call function*/
    // Child Child1;
    // Parent *ptr;   // point the object of parent class
    // ptr = &Child1;   //run time binding
    // ptr->hello();    //virtual function call

/*parent class to call function*/
    Parent prt1;
    Parent *ptr;
    ptr = &prt1;
    ptr->hello();
    return 0;
}
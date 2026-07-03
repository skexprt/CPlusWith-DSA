#include<iostream>
using namespace std;
//abstract class
class Shape{
    public:
      virtual void draw()=0;  // abstract fun,pure virtual fun.
};
class Circle:public Shape{
    public:
       void draw(){
          cout<<"draw the circle\n";
       }
};
class Sqaure:public Shape{
    public:
      void draw(){
        cout<<"draw the square\n";
      }
};
int main(){
    Circle  Crl1;
    Crl1.draw();

    Sqaure Sqr1;
    Sqr1.draw();

    return 0;
}
#include<iostream>
#include<string>
using namespace std;
class Car
{

public:
    string name;
    string color;
    int *mileage;

    Car(string name, string color){
        this->name = name;
        this->color = color;
        mileage = new int; // dynamic Allocation
        *mileage = 12;
     }
};
int main(){

    Car c1("maruti 800","white");
    Car c2(c1);

    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    cout<< *c2.mileage<<endl;

    // *c2.mileage= 10;

    cout<<*c1.mileage<<endl;
    return 0;
}
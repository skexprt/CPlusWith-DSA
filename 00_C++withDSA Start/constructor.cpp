#include<iostream>
#include<string>
using namespace std;
class Car{

  string name;
  string color;
public:
     Car(){
        cout<<"constructer is called.object being created..";
     }
     Car(string nameval, string colorval){
        cout<<"constructer is called.object being created..";
        name = nameval;
        color = colorval;
     }
     void start(){
        cout<<"car has start...\n";
     }
     void stop(){
        cout<<"car has stop..\n";
     }

     //Getters
     string getName(){

        return name;
     }
};
 int main(){
    Car c1("hundacity1900","white");

    cout<<"car name:"<<c1.getName()<<endl;


    return 0;
 }
#include<iostream>
using namespace std;
/*single inheritance*/
// class Animal{
//     public:
//        string color;

//        void eat(){
//          cout<<"eats\n";
//        }
//        void breathe(){
//          cout<<"breathe\n";
//        }
// };
// class Fish : public Animal{
//     public:
//          int fisn;

//          void swim(){
//             cout<<"swims\n";
//          }
// };
// int main(){

//     Fish f1;
//     f1.eat();
//     f1.breathe();
//     f1.swim();


//     return 0;
// }


/*multi level inheritace*/
// class Animal{
//     public:
//        string color;

//        void eat(){
//          cout<<"eats\n";
//        }
//        void breathe(){
//          cout<<"breathe\n";
//        }
// };
// class Fish : public Animal{
//     public:
//          int fisn;

//          void swim(){
//             cout<<"swims\n";
//          }
// };
// class Dog: public Fish{
//   public:
//       string taileag;

//       void taieag(){
//         cout <<"taileag\n";
//       }
// };
// int main(){

//     Dog d1;
//     d1.eat();
//     d1.breathe();
//     d1.swim();
//     d1.taieag();
//     return 0;
// }

/*multiple inheritance*/

class techear{
  public:
    int selary;
    string subject;
};
class student{
  public:
      int rollno;
      float cgpa;
};
class marge:public techear , public student{
  public:
      string name;
};
int main(){

  marge m1;
  m1.cgpa = 9.1;
  m1.name= "shiva";
  m1.rollno = 273405;
  m1.subject = "coding";

  cout<<"rollno:"<<m1.rollno<<endl;
  cout<<"name:"<<m1.name<<endl;
  cout<<"subjet:"<<m1.subject<<endl;
  cout<<"cgpa:"<<m1.cgpa<<endl;

  return 0;
}
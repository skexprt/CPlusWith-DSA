#include<iostream>
using namespace std;
/*assinment qeution*/
class Parson{
    protected:
   string name;
   int age;
   public:
      Parson(string n, int a){
        name = n ;
        age = a;
      }
};
class Student : public Parson{
     string studentid;

     public:
       Student(string n , int a, string id):Parson(n,a){

           studentid=id;
       }

       void displaystudent(){
          cout <<"name="<<this->name<<endl;
          cout <<"name="<<this->age<<endl;
          cout <<"name="<<this->studentid<<endl;
       }

};
int main(){
    Student student("shiva",20,"s41325");
    student.displaystudent();

    return 0;
}
#include<iostream>
using namespace std;
class Student
{
private:
    string name;
    float cgpa;
public:
void getpercentage(){
    cout<< (cgpa*10)<<"%\n";
}

// Setters
void SetName(string nameval){
    name = nameval;
}
void SetCgpa(float cgpaval){
    cgpa = cgpaval;
}

// Gettters
string GetName(){
   return name;
}
 float GetCgpa(){
    return cgpa;
}
};
int main(){
    Student s1;
    s1.SetName("Shiva");
    s1.SetCgpa(9.1);

    cout<<s1.GetName()<<endl;
    cout<<s1.GetCgpa()<<endl;
    return 0;
}
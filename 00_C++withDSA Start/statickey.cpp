#include<iostream>
using namespace std;

// // static keyword in function
// void Counter(){
//     static int count = 0;  //static const behieve
//     count++;
//     cout <<"count:"<<count<<endl;
// }
// int main(){

//     Counter(); 
//     Counter(); 
//     Counter(); 
//     return 0;
// }

// /*static keyword in class*/
// class Example{
//     public:
//     //    static const int x = 0; // const behive not allowed
//        static int x;    // initailizetion out side
// };
// int Example::x=0;
// int main(){

//      Example exa1;
//      Example exa2;
//      Example exa3;

//      cout<<exa1.x++<<endl;
//      cout<<exa2.x++<<endl;
//      cout<<exa3.x++<<endl;

//     return 0;
// }

/*static  object */
class Example{
    public:
     Example(){
        cout<<"constructor...\n";
     }
     ~Example(){
        cout<<"destructor\n";
     }
};
int main(){
    int a = 0;
    if (a==0)
    {
      static Example exa1;
    }
    cout<<"end coding...\n"<<endl;
}
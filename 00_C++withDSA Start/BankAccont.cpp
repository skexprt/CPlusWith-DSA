#include<iostream>
using namespace std;
/*assinment quetion*/
class BankAccount{
    int AccountNum;
    int balance;

  public:
    BankAccount(double BA, int bal){
        AccountNum = BA;
        balance = bal;

    }

    public:
       void diposit(double amount){
        cout<<"Acount in add the balance\n";
        balance += amount;
       }
       void Widthdrow(double amount){
        cout<<"Acount widthdrow\n";
         if (balance >= amount)
         {
            balance -= amount;
         }else{
            cout << "No sufficint balance for this widthrow\n";
         }
         

       }
       double GetBalance(){
        cout<<"Check the balance\n";
        return balance;
       }
};

int main(){
    BankAccount MyAcount(44824387265,500);
    MyAcount.diposit(100);
    MyAcount.Widthdrow(200);

    cout<<"current balance:"<<MyAcount.GetBalance()<<endl;;



    return 0;
}
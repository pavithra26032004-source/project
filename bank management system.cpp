#include <iostream>
using namespace std;

class BankAccount
{
private:
int accountNo;
string name;
float balance;

public:
void createAccount()
{
cout <<"\nEnter Account Number:";
cin >> accountNo;

cout <<"enter Account holder name:";
cin >> name;

cout <<"Enter initial balance:";
cin >> balance;  // 1000 -> 1000+2000 = 3000
}

void deposit()
{
float amount;
cout <<"\nEnter Account to deposit:";
cin >> amount;  // 2000
balance += amount;  // balance = balance + amount
cout <<"Amount deposited successfully!" << endl;
}
void withdraw()
{
float amount;
cout <<"\nEnter Amount to withdraw:";  // 4000  2500
cin >> amount ;  // 4000

if(amount <= balance) // 4000 <= 3000   2500 <= 3000
{
balance -= amount;  // balance = balance - amount
cout <<"Amount withdrawn successfully!" <<endl;
}

else
{
cout <<"Insufficient Balance!" << endl;
}}

void display(){
cout << "\n Account Number :" << accountNo;
cout << "\n name : " << name;
cout <<"\n balance: " << balance << endl;
}};

int main(){
BankAccount account;
int choice;
do
{
cout <<"\nBank Management system";
cout <<"\n1. create account";
cout <<"\n2. deposit money";
cout <<"\n3. withdraw money";
cout <<"\n4. display Account details";
cout <<"\n5. Exit";
cout <<"\nEnter your choice:"; // 1
cin >> choice;

switch(choice)  // 1
{
case 1:
account.createAccount();
break;

case 2:
account.deposit();
break;

case 3:
account.withdraw();
break;

case 4:
account.display();
break;

case 5:
cout << "\n thank you!";
break;

default:
cout << "\n Invalid choice";
}
}
while(choice!=5);
return 0;

}

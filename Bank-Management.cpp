#include<iostream>
#include<string>
using namespace std;


// Define a class to represent a bank account which includes the 
// following members as: a. Name of the depositor b. b. Account 
// Number c. c. Withdrawal amount d. d. Balance amount in the 
// account Member Functions: e. e. To assign initial values f. f.
//  To deposit an amount g. g. To withdraw an amount after checking
//  the balance h. h. To display name and balance. Implement the
//   program by using features of OOP in C++


class BankAccount {
    public :
    string accountHolderName ;
    string accountNumber  ;
    double balance   ;

    
    double withdrawalAmount ;
    double depositAmount ;

    BankAccount() {
         accountHolderName = "Rohit khokale";
         accountNumber = "1234567890";
         withdrawalAmount = 0.0;
         depositAmount = 0.0;

         balance = 10000.0 ;
    }

    ~ BankAccount(){
        cout << " Destroying Object !!!! " ;
    }

    void assignInitialValues(string name, string number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: Rs" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: Rs" << amount << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    

    void displayAccountDetails() {
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs" << balance << endl ; 

    }

};

int main(){
    int n = 2 ;
    BankAccount Account[n] ;

    string Account_Name ;
    string Account_Number ;
    double Account_Balance ;
    
    for ( int i = 0 ; i < n ; i++ ){
        cout << "Enter your Name " << endl ;
        cin >> Account_Name ;
        cout << "Enter your Account_Number " << endl ;
        cin >> Account_Number ;
        cout << "Enter your Account your Balance " << endl ;
        cin >> Account_Balance ;
        Account[i].assignInitialValues(Account_Name , Account_Number , Account_Balance) ;
        }
    int choice;
    do{
        cout << endl <<  "Enter your choice: " << endl;
        cout << "1. Deposit Amount" << endl;
        cout << "2. Withdraw Amount" << endl;
        cout << "3.Display" << endl ;
        cout << "4.Exit" << endl ;
        cin >> choice;
        switch(choice){
            case 1 : {
                    cout << "Enter your Account_Number " << endl ;
                    string temp_no ;
                    getchar() ; 
                    getline (cin , temp_no ) ;
                    int deposit_amount ;
                    cout << "Enter deposit Amount :  " ;
                    cin >> deposit_amount ;
                    
                    for(int i = 0 ; i < n ; i++ ){
                        
                        if (Account[i].accountNumber == temp_no ){
                            Account[i].withdraw (deposit_amount) ;
                            cout << "withdrawl successfull " << endl ;
                            break ;
                        }
                    }
                    break ;
            }
            case 2 : {
                    cout << "Enter your Account_Number " << endl ;
                    string temp_no ;
                    getchar() ; 
                    getline (cin , temp_no ) ;
                    int withdraw_amount ;
                    cout << "Enter Withdraw Amount :  " ;
                    cin >> withdraw_amount ;
                    
                    for(int i = 0 ; i < n ; i++ ){
                        
                        if (Account[i].accountNumber == temp_no ){
                            Account[i].withdraw (withdraw_amount) ;
                            cout << "withdrawl successfull " << endl ;
                            break ;
                        }
                    }
                    break ;
            }
            case 3 : {
                cout << "Enter your Account_Number " << endl ;
                string temp_no ;
                getchar() ; 
                getline (cin , temp_no ) ;
                
                for(int i = 0 ; i < n ; i++ ){
                    
                    if (Account[i].accountNumber == temp_no ){
                        Account[i].displayAccountDetails () ;
                        break ;
                    }
                }
                break ;
            }
            case 4 :{
                return 0 ;
            }


        }
    }while(1);

    return 0 ;
}


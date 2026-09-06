#include<bits/stdc++.h>
using namespace std;


// Define a class to represent a bank account which includes the 
// following members as: a. Name of the depositor b. b. Account 
// Number c. c. Withdrawal amount d. d. Balance amount in the 
// account Member Functions: e. e. To assign initial values f. f.
//  To deposit an amount g. g. To withdraw an amount after checking
//  the balance h. h. To display name and balance. Implement the
//   program by using features of OOP in C++
    
string generate_account_number( int length ){
        string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        string account_no = "";
        for( int i = 0 ; i < length ; i++ ) {
            account_no += chars[rand() % chars.length()] ;
        }
        return account_no ;
    }

class BankAccount {
    
    char * accountHolderName ;
    char * accountNumber  ;
    double balance   ;

    public : 

    static int total_records ;

    BankAccount() {
        accountHolderName = new char ;
        accountNumber = new char ;
        strcpy( accountHolderName , "UNKNOWN" ) ;
        strcpy( accountNumber , "ABC000" );
        balance =  0.0 ;
    }

    ~ BankAccount(){
        delete[] accountHolderName ;
        delete[] accountNumber ;
    }


    void create_account( string accno) {
        
        char name [100] ;
        cout << "\tInitializing account registration process\n" ;
        cout << "Enter Account Holder Name : " ;
        getchar() ;  
        fgets( name , 100 , stdin ) ;
        // cin >> name ;
        strcpy( accountHolderName , name ) ;

        strcpy( accountNumber , &accno[0] ) ;

        cout << "Enter Account Balance : " ;
        cin >> balance ;

        total_records ++ ;
        displayAccountDetails("displayone") ;
        cout << "Account Created Successfully" << endl ;
        cout << "Note : Save your account number for future reference" << endl ;

    }


    void deposit(double amount) {

        if (amount > 0 && amount < 100000 ) {
            balance += amount;
            cout << "Deposited: Rs" << amount << endl;
            cout << "Total balance : Rs" << balance << endl ;
        } 
        else {
            cout << "Invalid deposit amount! Daily deposit limit is upto 100000" << endl;
        }

    }


    void withdraw(double amount) {
        
        if (amount > 0 && amount <= balance + 1000 ) {
            balance -= amount;
            cout << "Withdrawn: Rs" << amount << endl;
            cout << "Total balance : Rs" << balance << endl ;
        } 
        else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }

    }
    

    void displayAccountDetails( string purpose ) {
        if( purpose == "displayone"){
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance : Rs" << balance << endl ; 
        }
        else if( purpose == "displayall" ){
            cout << accountNumber << setw(15) << accountHolderName << setw(15) << balance <<endl ;
        }
    }

    friend void search( BankAccount [] , string purpose , char [] ) ;
    friend void deleteAccount( BankAccount [] , int ) ;
    friend string check_acc_no( BankAccount [] ) ;
    

};

string check_acc_no( BankAccount account[] ){
    while(1){
        string accno = generate_account_number(6);
        int flag = 0 ;
        for( int i = 0 ; i < BankAccount :: total_records ; i++ ){
            if( strcmp( account[i].accountNumber , &accno[0] ) == 0 ){
                flag = 1 ;
                break ;
            }
        }
        if( flag == 0 ){
            return accno ;
        }
    }
}

void deleteAccount( BankAccount account[] , int n ){

    cout << "Deleting following record " << endl ;
    account[n].displayAccountDetails("displayone") ;

    for( int i = n ; i < BankAccount :: total_records - 1 ; i++ ){
        account[i] = account[i+1] ;
    }
    BankAccount :: total_records -- ; 
    cout << "Records Deleted Successfully" << endl ;

}
 
void search( BankAccount account[] , string purpose , char account_no [] ) {

    int flag = 0 ; 

    for( int i = 0 ; i < BankAccount :: total_records ; i++ ) {

        if ( strcmp( account[i].accountNumber , account_no ) == 0 ) {

            cout << "Account Found" << endl ;
            flag = 1 ;

            if (purpose == "deposit") {
                double amount ;
                cout << "Enter Amount to Deposit : " ;
                cin >> amount ;
                account[i].deposit(amount) ;
            }
            else if (purpose == "withdraw") {
                double amount ;
                cout << "Enter Amount to Withdraw : " ;
                cin >> amount ;
                account[i].withdraw(amount) ;
            }
            else if (purpose == "display") {
                account[i].displayAccountDetails("displayone") ;
            }
            else if ( purpose == "delete" ){
                deleteAccount( &account[i] , i ) ;
            }

            break ;

        }
        
    }

    if( flag == 0 ) {
        cout << "Account Not Found" ;
    }
     
}


int BankAccount :: total_records = 0 ; 

int main(){
    int n = 100 ;
    BankAccount Account[n] ;

    int choice;
    do{
        cout << endl <<  "Enter your choice: " << endl;
        cout << "1. Register Account" << endl ;
        cout << "2. Deposit Amount" << endl;
        cout << "3. Withdraw Amount" << endl;
        cout << "4. Display" << endl ;
        cout << "5. Delete" << endl ;
        cout << "6. Display All Records" << endl ;
        cout << "7. Exit" << endl ;
        cin >> choice;

        switch(choice){
            case 1 : {
                    int i = BankAccount :: total_records ;
                    string accno = check_acc_no( &Account[0] ) ;
                    Account[i].create_account( accno ) ;
                    break ;
            }
            case 2 : {
                    char account_no [100] ;
                    cout << "Enter Account No : " ; 
                    cin >> account_no ;
                    search( &Account[0] , "deposit" , account_no ) ;
                    break ;
            }
            case 3 : {
                    char account_no [100] ;
                    cout << "Enter Account No : " ; 
                    cin >> account_no ;
                    search( &Account[0] , "withdraw" , account_no ) ;
                    break ;
            }
            case 4 :{
                    char account_no [100] ;
                    cout << "Enter Account No : " ; 
                    cin >> account_no ;
                    search( &Account[0] , "display" , account_no ) ;
                    break ;
            }
            case 5 :{
                    char account_no [100] ;
                    cout << "Enter Account No : " ; 
                    cin >> account_no ;
                    search( &Account[0] , "delete" , account_no ) ;
                    break ;
            }
            case 6 :{
                    cout << "Displaying all registered records : " << endl ;
                    cout << "Sr no" << setw(15) << "Account No" << setw(15) << "Account Holder" << setw(15) << "Balance" <<endl ;
                    for( int i = 0 ; i < BankAccount :: total_records ; i++ ){
                        cout << i+1 << setw(15) ;
                        Account[i].displayAccountDetails("displayall") ;
                    }
                    break ;
            } 
            case 7 :{
                    cout << "Exiting the program" ;
                    return 0 ;
            }


        }
    } while(1);

    return 0 ;
}


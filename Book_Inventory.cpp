#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>

using namespace std;

class Book {
    char *title ;
    char *author ;
    char *publisher ;
    float price ;
    int stock ;
    
    static int records ;

    public: 
        Book(){

            title = new char ;
            author = new char ;
            publisher = new char ;
            strcmp( title , "Unknown" ) ;
            strcmp( publisher , "Unknown" ) ;
            strcmp( author , "Unknown" ) ;
            price = 0.0 ;
            stock = 0 ;

        }
        Book( char *t , char *a , char *p , float pr, int s){

            title = new char ;
            author = new char ;
            publisher = new char ;
            strcpy( title , t ) ;
            strcpy( author , a ) ;
            strcpy( publisher , p ) ;
            price = pr ;
            stock = s ;

        }
        ~Book(){

            cout << "Destructor called for Book : " << title << "Author : " << author << "Publisher : " << publisher << endl ;
            
            delete title ;
            delete author ;
            delete publisher ;

        }

        friend bool search(Book B , char *t , char *a ) ;

        void accept(){
            
            records ++ ;

            cout << "Enter title of book : "  ;
            cin.getline( title , 20 ) ;

            cout << "Enter author of book : " ;
            cin.getline( author , 20 ) ;

            cout << "Enter publisher of book : " ;
            cin.getline( publisher , 20 ) ;

            cout << "Enter price of book : " ;
            cin >> price ;

            cout << "Enter stock of book : " ;
            cin >> stock ;

        }

        void sell( int copy ){
            if( copy <= stock && copy > 0 ){
                stock = stock - copy ;
                cout << "Book : " << title << endl << "Author : " << author << endl << "Price : " << endl << price << "Total Price : " << price * copy << endl ;
            }
            else {
                cout << " The Book has no required stock or required copies are less than 1 " << endl ;
                cout << "Available Stock : " << stock << endl ;
            }
        }

        void display(){
             cout << title << setw(15) << author << setw(15) << publisher << setw(15) << price << setw(15) << stock << endl ;
        }
}B[100] ;


bool search( Book B , char *t , char *a ){

    if( strcmp( B.title , t ) == 0 && strcmp( B.author , a ) == 0 ){
        return true ;
    }
    else {
        return false ;
    }

}

int main(){

    int choice , i = 0 , copy ;

     cout << "MENU" << endl ;
     cout << "1. Add Book" << endl ;
     cout << "2. Sell Book" << endl ;
     cout << "3. Display Books" << endl ;
     cout << "4. Exit" << endl ;

     cin >> choice ;

     switch( choice ){

        case 1 : 
            B[i].accept() ;
            i++ ;
            break ;

        case 2 :

            char t[20] ;
            char a[20] ;

            cout << "Enter the title of book to sell : " ;
            cin.getline( t , 20 ) ;

            cout << "Enter the author of book to sell : " ;
            cin.getline( a , 20 ) ;

            int flag = 0 ;

            for( int j = 0 ; j < i ; j++ ){

                if( search( B[j] , t , a ) ){

                    cout << "Enter the number of copies to sell : " ;
                    cin >> copy ;
                    B[j].sell( copy ) ;
                    flag = 1 ;
                    break ;
                }

            }
            if( flag == 0 ){
                cout << "Book not found" << endl ;
            }
            break ;

        case 3 :
            for( int j = 0 ; j < i ; j++ ){
                B[j].display() ;
            }
            break ;

        case 4 :
            exit(0) ;
            break ;

        default :
            cout << "Invalid Choice" << endl ;
     }

}
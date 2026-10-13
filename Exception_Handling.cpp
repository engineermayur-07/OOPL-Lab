 

// Aim : To Create a Television class and implement it using the concept of exception handling in C++.

// Problem Statement : Create a C++ class nammed Television that has data members to hold the model number and 
// the screen size in inches and the price. Member functions include overloaded insertion and extraction operators.
// If more than four digits are entered for the model number, if the screen size is smaller than 12 or greater than 70
// inches, or if the price is negative or over $5000 then throw an integer. Write a main() function that instantiates
// a television object, allows user to enter data and displays the data members. If an exception is caught, replace 
// all the data member values with zero values.


#include <iostream>
#include <stdexcept>
using namespace std;

class Television {
    private:
        int modelNumber;
        int screenSize;
        double price;
    public :
        static int records ;
        friend istream &operator >>(istream & , Television &) ;
        friend ostream &operator << (ostream & , Television & ) ;
    
};

int Television :: records = 0 ;

istream &operator >> ( istream & i , Television &T ){

    cout << "Enter the model no of Television : " ;
    i >> T.modelNumber ;
    if( T.modelNumber > 9999 || T.modelNumber < 1000 ) {
        string s = "Model Number should be a 4 digit number" ;
        throw s ;
    }

    cout << "Enter the screensize of Television : " ;
    i >> T.screenSize ;
    if( T.screenSize < 12 || T.screenSize > 70 ) {
        throw 1 ;
    }

    cout << "Enter the price of the Television ($): " ;
    i >> T.price ;
    if( T.price < 0 || T.price > 5000 ){
        throw 1.0 ;
    }

    Television::records ++ ;

    return i ;
    
}

ostream &operator << ( ostream & o , Television &T ){
    
    o << "Model No : " << "T" << T.modelNumber << endl ;
    o << "Screen Size : " << T.screenSize << " inches "<< endl ;
    o << "Price : " << "$" << T.price << endl ; 
    
    return o ;
}



int main () {

     Television T[10] ;
     int choice = 0 ; 
     while( true ) {
        cout << endl << "MENU" << endl ;
        cout << "Add Data : 1" << endl ;
        cout << "Display Data : 2" << endl ;
        cout << "Exit : 3" << endl ;
        cout << "Enter your choice : " ;
        cin >> choice ;

        switch(choice){
            case 1 : {
                try{
                    cin >> T[Television :: records] ;
                }
                catch( string s ){
                    cout << endl << s << endl ;
                }
                catch ( int i ){
                    cout << endl << "Screen Size should be between 12 and 70 inches" << endl ;
                }
                catch ( double d ){
                    cout << endl << "Price should be between $0 and $5000" << endl ;
                }
                break ;
            }
            
            case 2 : {
                for( int i = 0 ; i < Television :: records ; i++ ){
                    cout << "Television No : " << i+1 << endl ; 
                    cout << T[i] ;
                }
                break ;
            }

            case 3 : {
                cout << "Exiting the program " << endl ; 
                return 0 ;
            }
        }

        
     }
}

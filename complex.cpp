#include<iostream>
using namespace std ;

class Complex{
    float real ;
    float img ;
    
    public :
    Complex(){
        real = 0.0 ;
        img = 0.0 ;
    }
    void accept(){
        cout << "Enter Real Part : " ;
        cin >> real ;
        cout << "Enter Imaginary Part : " ;
        cin >> img ;
    }
    void display(){
        if( img < 0 ){
            cout << endl << real << img << "i" ;
        }
        cout << endl << real << " + " << img << "i" ;
    }
    friend Complex operator + ( Complex c1 , Complex c2 ){
        Complex temp ;
        temp.real = c1.real + c2.real ;
        temp.img = c1.img + c2.img ;
        return temp ;
    }
    friend Complex operator - ( Complex c1 , Complex c2 ){
        Complex temp ;
        temp.real = c1.real - c2.real ;
        temp.img = c1.img - c2.img ;
        return temp ;
    }
    friend Complex operator * ( Complex c1 , Complex c2 ){
        Complex temp ;
        temp.real = (c1.real*c2.real) - (c1.img*c2.img) ;
        temp.img = (c1.real*c2.img) - (c2.real*c1.img) ;
        return temp ;
    }
    friend Complex operator / ( Complex c1 , Complex c2 ){
        Complex temp ;
        temp.real = (c1.real*c2.real + c1.img*c2.img) / (c2.real*c2.real + c2.img*c2.img) ;
        temp.img = (c1.img*c2.real - c1.real*c2.img) / (c2.real*c2.real + c2.img*c2.img) ;
        return temp ;
    }
};

int main(){


    while(true){
        int choice = -1 ;
        cout <<endl << "MENU" << endl ;
        cout << "1. Add " << endl ;
        cout << "2. Subtract " << endl ;
        cout << "3. Multiply " << endl ;
        cout << "4. Divide " << endl ;
        cout << "5. Exit " << endl ;
        cin >> choice ;

        Complex c1 , c2 , c3 ;

        switch( choice ){
            case 1 : {
                
                cout << "Enter First Complex Number : " << endl ;
                c1.accept() ;
                cout << "Enter Second Complex Number : " << endl ;
                c2.accept() ;
                c3 = c1 + c2 ;
                cout << "Result : " ;
                c3.display() ;
                break ;

            }
            case 2 : {
                
                cout << "Enter First Complex Number : " << endl ;
                c1.accept() ;
                cout << "Enter Second Complex Number : " << endl ;
                c2.accept() ;
                c3 = c1 - c2 ;
                cout << "Result : " ;
                c3.display() ;
                break ;
            }
            case 3 : {
                
                cout << "Enter First Complex Number : " << endl ;
                c1.accept() ;
                cout << "Enter Second Complex Number : " << endl ;
                c2.accept() ;
                c3 = c1 * c2 ;
                cout << "Result : " ;
                c3.display() ;
                break ;

            }
            case 4 : {
                
                cout << "Enter First Complex Number : " << endl ;
                c1.accept() ;
                cout << "Enter Second Complex Number : " << endl ;
                c2.accept() ;
                c3 = c1 / c2 ;
                cout << "Result : " ;
                c3.display() ;
                break ;

            }
            case 5 : {
                exit(0) ;
            }
        }

    }
}
#include <iostream>
using namespace std;

// Write a C++ program using a function template to 
// implement the Bubble Sort algorithm. The program should
//  accept an array of elements of different data types such
//   as int, float, and double. Create a function template named 
//   bubbleSort() that sorts the elements of the array in ascending
//    order by repeatedly comparing adjacent elements and swapping them
//    when they are in the wrong order.

template <class T>
void bubbleSort(T arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                 
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

        }
    }
}

template <class T>
int acceptArray( T arr[] ) {

    int n ;
    cout << "Enter the number of elements less than 100 : ";
    cin >> n ;
    cout << "Enter " << n << " elements: ";
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    return n ;
}

int main() {
     
    int intArr[100] ;
    float floatArr[100] ;
    char charArr[100] ;

    while(true){
    cout << "MENU" << endl ;
    cout << "1. Integer Sorting " << endl ;
    cout << "2. Float Sorting " << endl ;
    cout << "3. Character Sorting " << endl ;
    cout << "4. Exit " << endl ;
    
    int choice ;
    cout << "Enter your choice : " ;
    cin >> choice ;

    switch (choice){
        
        case 1 : {
            
            int n = acceptArray(intArr) ;
            bubbleSort(intArr, n) ;
            cout << "Sorted Integer Array : " ;
            for (int i = 0 ; i < n ; i++) {
                cout << intArr[i] << " " ;
            }
            cout << endl ;
            break ;
        }

        case 2 : {
            int n = acceptArray(floatArr) ;
            bubbleSort(floatArr, n) ;
            cout << "Sorted Float Array : " ;
            for (int i = 0 ; i < n ; i++) {
                cout << floatArr[i] << " " ;
            }
            cout << endl ;
            break ;
        }

        case 3 : {
            int n = acceptArray(charArr) ;
            bubbleSort(charArr, n) ;
            cout << "Sorted Character Array : " ;
            for (int i = 0 ; i < n ; i++) {
                cout << charArr[i] << " " ;
            }
            cout << endl ;
            break ;
        }

        case 4 : {
            cout << "Exiting..." << endl ;
            return 0 ;
        }
    }
}

    return 0;
}
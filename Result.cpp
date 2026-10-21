#include <bits/stdc++.h>
using namespace std;

int records = 0 ;

class Student {
protected :
    string name ;
    int rollNumber ;
    string course ;
    string mother ;

    public :

    void acceptStudentDetails() {
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Course: ";
        cin >> course;
        cout << "Enter Mother's Name: ";
        cin >> mother;
        
    }

     

};

class Exam : virtual public Student {
protected :
    float ESEmarks[5];
    float CIAmarks[5];
     
  
    string subjects[5] ;
    string subjectcodes[5] ;

     
public : 
    void acceptExamDetails() {
        cout << "Enter Subject Codes and Marks for 5 subjects:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Subject Code: ";
            cin >> subjectcodes[i];
            cout << "Subject Name: ";
            cin >> subjects[i];
            cout << "ESE Marks of " << subjects[i] << ": ";
            cin >> ESEmarks[i];
            cout << "CIA Marks of " << subjects[i] << ": ";
            cin >> CIAmarks[i];
             
        }
         
        
    }

    
};

class CCA : protected virtual Student {
    protected :
    string CCA ;
    string grade ;
    public :
    void acceptCCADetails() {
        cout << "Enter CCA: ";
        cin >> CCA;
        cout << "Enter Grade: ";
        cin >> grade;
    }

};

class Result : public Exam, public CCA {
    protected :
     
    string result ;

    public :


    void displayResult() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Mother's Name: " << mother << endl;

        cout << "Sr No\tSubject Code\tSubject Name\tESE Marks\tCIA Marks\tTotal" << endl;
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << "\t" << subjectcodes[i] << "\t\t" << subjects[i] << "\t\t" << ESEmarks[i] << "\t\t" << CIAmarks[i] << "\t\t" << ESEmarks[i] + CIAmarks[i] << endl;
        }
         
    }

    friend void deleteStudentRecord( Result result[] , int a ){
        for( int i = a ; i < records-1 ; i++ ){
            result[i] = result[i+1] ;
        }
        cout << "Record deleted successfully" ;
        records -- ;
    }

    friend void searchStudent(Result result[], int rollNumber, string purpose ) {
        for (int i = 0; i < records; i++) {
            if (result[i].rollNumber == rollNumber) {
                cout << "Student Found!" << endl;
                if(purpose == "display"){
                    result[i].displayResult();
                }
                else if( purpose == "delete"){
                    return deleteStudentRecord( result , i ) ;
                }
                else if( purpose == "modify"){
                    result[i].acceptStudentDetails() ;
                    result[i].acceptExamDetails() ;
                    result[i].acceptCCADetails() ;
                    result[i].displayResult();
                    cout << "Modified Succcessfully" ;                    
                }
                return;
            }
        }
        cout << "Student Not Found!" << endl;
    }
};

int main(){
    Result result[10] ;
    int choice ; 
    while(true){
        cout << "MENU" << endl;
        cout << "1. Enter Student Details" << endl ;
        cout << "2. Display Result" << endl ;
        cout << "3. Edit Student Details" << endl ;
        cout << "4. Delete Student Details" << endl ;
        cout << "5. Exit" << endl ;
        cin >> choice ;
        switch (choice) {
            case 1:
                if( records <= 10 ){
                    
                    
                
                result[records].acceptStudentDetails() ;
                result[records].acceptExamDetails() ;
                result[records].acceptCCADetails() ;
                records++ ;
                }
                else{
                    cout << "Maximum Records Reached" ;
                }
                break ;

            case 2:
                int rollNumber ;
                cout << "Enter Roll Number to Display: ";
                cin >> rollNumber ;
                searchStudent(result, rollNumber, "display") ;                
                break ;

            case 3:
                cout << "Enter Roll Number to Edit Details" ;
                cin >> rollNumber ;
                searchStudent(result,rollNumber,"modify") ;
                break ;
            
            case 4 :
                cout << "Enter Roll Number to Delete the Record" ;
                cin >> rollNumber ;
                searchStudent(result,rollNumber,"delete") ;
                break ;

            case 5 :
                cout << "Exiting the program" ;
                return 0 ;
                
            default:
                cout << "Invalid Choice" << endl ;
        }
    }
    
}

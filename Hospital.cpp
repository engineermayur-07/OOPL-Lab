// Problem Statement: Hospital Management System

// Design and develop a simple Hospital Management System using C++ to store and display information about different hospital employees.

// Create a base class named Person that stores common information such as name, age, and contact number. Derive three classes from the Person class:

// Doctor – stores doctor-specific information such as specialization and experience.
// Nurse – stores nurse-specific information such as department and shift.
// Admin – stores administrative information such as designation and department.
// Use inheritance to reuse the common properties of the Person class. Implement a virtual function display() in the base class and override it in each derived class to display the respective details



#include <bits/stdc++.h>
using namespace std ;

class Person {
    protected :
        string name ;
        int age ;
        string contactNumber ;
        
    
    public :
        static int records ;
        virtual void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Contact Number: " << contactNumber << endl;
            
        }

        virtual void acceptDetails() {
            cout << "Enter Name: ";
            cin >> name ;
            cout << "Enter Age: ";
            cin >> age ;
            cout << "Enter Contact Number: ";
            cin >> contactNumber ;
        }
};

class Doctor : public Person {
    protected :
        string specialization ;
        int experience ;
        int DoctorID ;

        
    public :
        static int doctorCount ;  
        void display() override {
            Person::display();
            cout << "Doctor ID: " << DoctorID << endl;
            cout << "Specialization: " << specialization << endl;
            cout << "Experience: " << experience << " years" << endl;
        }

        void acceptDetails() override {
            Person::acceptDetails();
            cout << "Enter Specialization: ";
            cin >> specialization ;
            cout << "Enter Experience (in years): ";
            cin >> experience ;
            cout << "Enter Doctor ID: ";
            cin >> DoctorID ;
        }

        friend void searchDoctor(Doctor doctors[], int doctorID, string purpose) {
            for (int i = 0; i < doctorCount; i++) {
                if (doctors[i].DoctorID == doctorID) {

                    Person *ptr = &doctors[i];
                    cout << "Doctor Found!" << endl;
                    if (purpose == "display") {
                        ptr->display();
                    }
                    else if (purpose == "modify") {
                        ptr->acceptDetails();
                        cout << "Doctor details modified successfully." << endl;
                    }
                    else if (purpose == "delete") {
                        for (int j = i; j < doctorCount - 1; j++) {
                            doctors[j] = doctors[j + 1];
                        }
                        doctorCount--;
                        cout << "Doctor record deleted successfully." << endl;
                    }
                    return;
                }
            }
            cout << "Doctor with ID " << doctorID << " not found." << endl;
        }
};

class Nurse : public Person {
    protected :
        string department ;
        string shift ;
        int NurseID ;
        

    public :
        static int nurseCount ;
        void display() override {
            Person::display();
            cout << "Nurse ID: " << NurseID << endl;
            cout << "Department: " << department << endl;
            cout << "Shift: " << shift << endl;
        }

        void acceptDetails() override {
            Person::acceptDetails();
            cout << "Enter Department: ";
            cin >> department ;
            cout << "Enter Shift: ";
            cin >> shift ;
            cout << "Enter Nurse ID: ";
            cin >> NurseID ;
        }

        friend void searchNurse(Nurse nurses[], int nurseID, string purpose) {
            for (int i = 0; i < nurseCount; i++) {
                if (nurses[i].NurseID == nurseID) {

                    Person *ptr = &nurses[i];
                    cout << "Nurse Found!" << endl;
                    if (purpose == "display") {
                        ptr->display();
                    }
                    else if (purpose == "modify") {
                        ptr->acceptDetails();
                        cout << "Nurse details modified successfully." << endl;
                    }
                    else if (purpose == "delete") {
                        for (int j = i; j < nurseCount - 1; j++) {
                            nurses[j] = nurses[j + 1];
                        }
                        nurseCount--;
                        cout << "Nurse record deleted successfully." << endl;
                    }
                    return;
                }
            }
            cout << "Nurse with ID " << nurseID << " not found." << endl;
        }
};

class Admin : public Person {
    protected :
        string designation ;
        string department ;
        int AdminID ;

    public :
        static int adminCount ;
        void display() override {
            Person::display();
            cout << "Admin ID: " << AdminID << endl;
            cout << "Designation: " << designation << endl;
            cout << "Department: " << department << endl;
        }

        void acceptDetails() override {
            Person::acceptDetails();
            cout << "Enter Designation: ";
            cin >> designation ;
            cout << "Enter Department: ";
            cin >> department ;
            cout << "Enter Admin ID: ";
            cin >> AdminID ;
        }

        friend void searchAdmin(Admin admins[], int adminID, string purpose) {
            for (int i = 0; i < adminCount; i++) {
                if (admins[i].AdminID == adminID) {

                    Person *ptr = &admins[i];
                    cout << "Admin Found!" << endl;
                    if (purpose == "display") {
                        ptr->display();
                    }
                    else if (purpose == "modify") {
                        ptr->acceptDetails();
                        cout << "Admin details modified successfully." << endl;
                    }
                    else if (purpose == "delete") {
                        for (int j = i; j < adminCount - 1; j++) {
                            admins[j] = admins[j + 1];
                        }
                        adminCount--;
                        cout << "Admin record deleted successfully." << endl;
                    }
                    return;
                }
            }
            cout << "Admin with ID " << adminID << " not found." << endl;
        }
};

int Admin::adminCount = 0;
int Doctor::doctorCount = 0;
int Nurse::nurseCount = 0;
int Person::records = 0 ;


int main() {
    Doctor doctors[10];
    Nurse nurses[10];
    Admin admins[10];

    int choice;
    while (true) {
        cout << "MENU" << endl;
        cout << "1. Enter Doctor Details" << endl;
        cout << "2. Enter Nurse Details" << endl;
        cout << "3. Enter Admin Details" << endl;
        cout << "4. Display Doctor Details" << endl;
        cout << "5. Display Nurse Details" << endl;
        cout << "6. Display Admin Details" << endl;
        cout << "7. Edit Doctor Details" << endl;
        cout << "8. Edit Nurse Details" << endl;
        cout << "9. Edit Admin Details" << endl;
        cout << "10. Delete Doctor Details" << endl;
        cout << "11. Delete Nurse Details" << endl;
        cout << "12. Delete Admin Details" << endl;
        cout << "13. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                if (Doctor::doctorCount < 10) {
                    Person *ptr = &doctors[Doctor::doctorCount];
                    ptr->acceptDetails();
                    Doctor::doctorCount++;
                }
                else {
                    cout << "Maximum Doctor Records Reached." << endl;
                }
                break;

            case 2:
                if (Nurse::nurseCount < 10) {
                    Person *ptr = &nurses[Nurse::nurseCount] ;
                    ptr->acceptDetails() ;
                    Nurse::nurseCount++;
                }
                else {
                    cout << "Maximum Nurse Records Reached." << endl;
                }
                break;

            case 3:
                if (Admin::adminCount < 10) {
                    Person *ptr = &admins[Admin::adminCount];
                    ptr->acceptDetails();
                    Admin::adminCount++;
                } else {
                    cout << "Maximum Admin Records Reached." << endl;
                }
                break;

            case 4: {
                int doctorID;
                cout << "Enter Doctor ID to Display: ";
                cin >> doctorID;
                searchDoctor(doctors, doctorID, "display");
                break;
            }

            case 5: {
                int nurseID;
                cout << "Enter Nurse ID to Display: ";
                cin >> nurseID;
                searchNurse(nurses, nurseID, "display");
                break;
            }

            case 6: {
                int adminID;
                cout << "Enter Admin ID to Display: ";
                cin >> adminID;
                searchAdmin(admins, adminID, "display");
                break;
            }

            case 7: {
                int doctorID;
                cout << "Enter Doctor ID to Edit: ";
                cin >> doctorID;
                searchDoctor(doctors, doctorID, "modify");
                break;
            }

            case 8: {
                int nurseID;
                cout << "Enter Nurse ID to Edit: ";
                cin >> nurseID;
                searchNurse(nurses, nurseID, "modify");
                break;
            }

            case 9: {
                int adminID;
                cout << "Enter Admin ID to Edit: ";
                cin >> adminID;
                searchAdmin(admins, adminID, "modify");
                break;
            }

            case 10: {
                int doctorID;
                cout << "Enter Doctor ID to Delete: ";
                cin >> doctorID;
                searchDoctor(doctors, doctorID, "delete");
                break;
            }

            case 11: {
                int nurseID;
                cout << "Enter Nurse ID to Delete: ";
                cin >> nurseID;
                searchNurse(nurses, nurseID, "delete");
                break;
            }

            case 12: {
                int adminID;
                cout << "Enter Admin ID to Delete: ";
                cin >> adminID;
                searchAdmin(admins, adminID, "delete");
                break;
            }

            case 13:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
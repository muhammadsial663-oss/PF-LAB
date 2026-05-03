#include <iostream>
using namespace std;

// --- Global Variables ---
const int maxstudent = 100;
string names[maxstudent] = {"ali", "aminaa", "ammar", "hafsa"};
int rollnumber[maxstudent] = {1, 3, 4, 5};
float marks[maxstudent] = {1009, 1000, 1001, 1054};
string nameAdmin = "admin", passcode = "123";
int currentcount = 4; 

// --- Admin Section Functions ---

void addStudent() {
    system("cls");
    if (currentcount < maxstudent) {
        cout << "Enter name: "; cin >> names[currentcount];
        cout << "Enter roll number: "; cin >> rollnumber[currentcount];
        cout << "Enter marks: "; cin >> marks[currentcount];
        currentcount++;
        cout << "---Data is saved---" << endl;
    } else { cout << "No more space!" << endl; }
}

void viewAll() {
    system("cls");
    cout << "Name\tRollnumber\tMarks" << endl;
    for (int i = 0; i < currentcount; i++) {
        cout << names[i] << "\t" << rollnumber[i] << "\t\t" << marks[i] << endl;
    }
}

void deleteStudent() {
    system("cls");
    int roll;
    cout << "Enter roll to delete: "; cin >> roll;
    bool found = false;
    for (int i = 0; i < currentcount; i++) {
        if (rollnumber[i] == roll) {
            for (int j = i; j < currentcount - 1; j++) {
                names[j] = names[j + 1];
                rollnumber[j] = rollnumber[j + 1];
                marks[j] = marks[j + 1];
            }
            currentcount--;
            found = true;
            cout << "---Record Deleted---" << endl;
            break;
        }
    }
    if (!found) cout << "Roll Number Not Found!" << endl;
}

void updateMarks() {
    system("cls");
    int roll;
    cout << "Enter roll to update marks: "; cin >> roll;
    for (int i = 0; i < currentcount; i++) {
        if (rollnumber[i] == roll) {
            cout << "Previous Marks: " << marks[i] << endl;
            cout << "Enter New Marks: "; cin >> marks[i];
            cout << "---Marks updated---" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void searchStudent() {
    system("cls");
    int roll;
    cout << "Enter roll to search: "; cin >> roll;
    for (int i = 0; i < currentcount; i++) {
        if (rollnumber[i] == roll) {
            cout << "Name: " << names[i] << " Marks: " << marks[i] << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void sortByMarks() {
    system("cls");
    for (int i = 0; i < currentcount - 1; i++) {
        for (int j = 0; j < currentcount - i - 1; j++) {
            if (marks[j] < marks[j + 1]) {
                swap(marks[j], marks[j + 1]);
                swap(names[j], names[j + 1]);
                swap(rollnumber[j], rollnumber[j + 1]);
            }
        }
    }
    cout << "Sorted by Marks (Descending)!" << endl;
}

void classAverage() {
    system("cls");
    if (currentcount == 0) return;
    float total = 0;
    for (int i = 0; i < currentcount; i++) total += marks[i];
    cout << "Average marks of class: " << total / currentcount << endl;
}

void totalAdmissions() {
    system("cls");
    cout << "Total students registered: " << currentcount << endl;
}

void deleteAllData() {
    system("cls");
    string confirm;
    cout << "Enter --YES-- to confirm delete all: "; cin >> confirm;
    if (confirm == "YES") {
        currentcount = 0;
        cout << "All data cleared!" << endl;
    }
}

void updateAdmin() {
    system("cls");
    string u, p;
    cout << "Old User: "; cin >> u;
    cout << "Old Pass: "; cin >> p;
    if (u == nameAdmin && p == passcode) {
        cout << "New Username: "; cin >> nameAdmin;
        cout << "New Password: "; cin >> passcode;
        cout << "Credentials Updated!" << endl;
    }
}

// --- User Section Functions ---

void userViewResult() {
    system("cls");
    int roll;
    cout << "Enter your roll number: "; cin >> roll;
    for (int i = 0; i < currentcount; i++) {
        if (rollnumber[i] == roll) {
            cout << "Name: " << names[i] << " Marks: " << marks[i] << endl;
            return;
        }
    }
    cout << "Result not found!" << endl;
}

void userHighestMarks() {
    system("cls");
    if (currentcount == 0) return;
    float maxM = marks[0];
    for (int i = 1; i < currentcount; i++) if (marks[i] > maxM) maxM = marks[i];
    cout << "Highest marks in class: " << maxM << endl;
}

void userViewAllNames() {
    system("cls");
    for (int i = 0; i < currentcount; i++) cout << i + 1 << ". " << names[i] << endl;
}

void userSearchByName() {
    system("cls");
    string n;
    cout << "Enter name to search: "; cin >> n;
    for (int i = 0; i < currentcount; i++) {
        if (names[i] == n) {
            cout << "Found! Name: " << names[i] << " Roll: " << rollnumber[i] << " Marks: " << marks[i] << endl;
            return;
        }
    }
    cout << "Name not found!" << endl;
}

main() {
    int mainchoice, adminchoice, userchoice;
    bool keeprunning = true;

    while (keeprunning) {
        system("cls");
        cout<<"============================================================"<<endl;
        cout<<"===========WELCOME TO SCHOOL MANAGEMENT SYSTEM=============="<<endl;
        cout<<"============================================================"<<endl;
        cout <<" 1. Enter as Admin"<<endl;
        cout <<" 2. Enter as User "<<endl;
        cout <<" 3. Exit the system "<<endl;
        cout<<" Please Enter your choice :";
        cin >> mainchoice;

        if (mainchoice == 1) {
            string u, p;
            cout << "User: "; cin >> u;
            cout << "Pass: "; cin >> p;
            if (u == nameAdmin && p == passcode) {
                bool admin = true;
                while (admin) {
                    system("cls");
                    cout << "1. Add\n2. View\n3. Delete\n4. Update Marks\n5. Search\n6. Sort\n7. Average\n8. Total\n9. Delete All\n10. Main Menu\n11. Update Admin\nChoice: ";
                    cin >> adminchoice;

                    if (adminchoice == 1) addStudent();
                    else if (adminchoice == 2) viewAll();
                    else if (adminchoice == 3) deleteStudent();
                    else if (adminchoice == 4) updateMarks();
                    else if (adminchoice == 5) searchStudent();
                    else if (adminchoice == 6) sortByMarks();
                    else if (adminchoice == 7) classAverage();
                    else if (adminchoice == 8) totalAdmissions();
                    else if (adminchoice == 9) deleteAllData();
                    else if (adminchoice == 10) admin = false;
                    else if (adminchoice == 11) updateAdmin();

                    if (adminchoice != 10) { cout << "\nPress Enter..."; cin.ignore(); cin.get(); }
                }
            }
        } 
        else if (mainchoice == 2) {
            bool student = true;
            while (student) {
                system("cls");
                cout << "1. View Result\n2. High Marks\n3. All Names\n4. Search Name\n5. Exit\nChoice: ";
                cin >> userchoice;
                if (userchoice == 1) userViewResult();
                else if (userchoice == 2) userHighestMarks();
                else if (userchoice == 3) userViewAllNames();
                else if (userchoice == 4) userSearchByName();
                else if (userchoice == 5) student = false;
                
                if (userchoice != 5) { cout << "\nPress Enter..."; cin.ignore(); cin.get(); }
            }
        } 
        else if (mainchoice == 3) {
            keeprunning = false;
        }
    }
}

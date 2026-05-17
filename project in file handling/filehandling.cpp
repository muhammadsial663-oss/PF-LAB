#include <iostream>
#include <fstream> // Required for file handling (ifstream and ofstream)
using namespace std;

// --- Global Variables ---
const int maxstudent = 100;
string names[maxstudent] = {"ali", "aminaa", "ammar", "hafsa"};
int rollnumber[maxstudent] = {1, 3, 4, 5};
float marks[maxstudent] = {1009, 1000, 1001, 1054};
string nameAdmin = "admin", passcode = "123";
int currentcount = 4;

// --- File Handling Functions ---

void saveData()
{
    ofstream file("students.txt"); // Open file for writing
    if (file.is_open())
    {
        file << currentcount << endl; 
        for (int i = 0; i < currentcount; i++)
        {
            // Save student details separated by space
            file << names[i] << " " << rollnumber[i] << " " << marks[i] << endl;
        }
        file << nameAdmin << " " << passcode << endl; 
        file.close();                                 // Close the file stream
    }
}

// Loads data from the text file back into the arrays when the program starts
void loadData()
{
    ifstream file("students.txt"); // Open file for reading
    if (file.is_open())
    {
        file >> currentcount; // Read the total number of records
        for (int i = 0; i < currentcount; i++)
        {
            // Read student details in the exact same sequence they were saved
            file >> names[i] >> rollnumber[i] >> marks[i];
        }
        file >> nameAdmin >> passcode;
        file.close();                  // Close the file stream
    }
}

// --- Admin Functions ---

void addStudent()
{
    system("cls");
    if (currentcount < maxstudent)
    {
        cout << "Enter name: ";
        cin >> names[currentcount];
        cout << "Enter roll number: ";
        cin >> rollnumber[currentcount];
        cout << "Enter marks: ";
        cin >> marks[currentcount];
        currentcount++;
        saveData(); // Save changes to the file permanently
        cout << "---Data is saved---" << endl;
    }
    else
    {
        cout << "No more space!" << endl;
    }
}

void viewAll()
{
    system("cls");
    cout << "Name\tRollnumber\tMarks" << endl;
    for (int i = 0; i < currentcount; i++)
    {
        cout << names[i] << "\t" << rollnumber[i] << "\t\t" << marks[i] << endl;
    }
}

void deleteStudent()
{
    system("cls");
    int roll;
    cout << "Enter roll to delete: ";
    cin >> roll;
    bool found = false;
    for (int i = 0; i < currentcount; i++)
    {
        if (rollnumber[i] == roll)
        {
            for (int j = i; j < currentcount - 1; j++)
            {
                names[j] = names[j + 1];
                rollnumber[j] = rollnumber[j + 1];
                marks[j] = marks[j + 1];
            }
            currentcount--;
            saveData(); // Save changes to the file permanently
            found = true;
            cout << "---Record Deleted---" << endl;
            break;
        }
    }
    if (found==false){
        cout << "Roll Number Not Found!" << endl;
    }
}

void updateMarks()
{
    system("cls");
    int roll;
    cout << "Enter roll to update marks: ";
    cin >> roll;
    bool found=false;
    for (int i = 0; i < currentcount; i++)
    {
        if (rollnumber[i] == roll)
        {
            cout << "Previous Marks: " << marks[i] << endl;
            cout<<"Name of the student "<<names[i]<<endl;
            cout << "Enter New Marks: ";
            cin >> marks[i];
            saveData(); // Save changes to the file permanently
            cout << "---Marks updated---" << endl;
            found=true;
            break;
            return;
        }
    }
    if(found==false){
    cout << "Not found!" << endl;
    }
}

void searchStudent()
{
    system("cls");
    int roll;
    cout << "Enter roll to search: ";
    cin >> roll;
    bool found=false;
    for (int i = 0; i < currentcount; i++)
    {
        if (rollnumber[i] == roll)
        {
            cout << "Name of student: " << names[i]<<endl;
            cout<<"Marks of the student :"<<marks[i]<<endl;
            found=true;
            break;
            
        }
    }
    if(found==false){
        cout<<"Not found !";
    }
}

void sortByMarks()
{
    system("cls");
    for (int i = 0; i < currentcount - 1; i++)
    {
        for (int j = 0; j < currentcount - i - 1; j++)
        {
            if (marks[j] < marks[j + 1])
            {
               int temp=marks[j];
               marks[j]=marks[j+1];
               marks[j+1]=temp;
            }
        }
    }
    saveData(); // Save the new sorted order to the file permanently
    cout << "Sorted by Marks From Highest to Lowest" << endl;
    cout<<"Name\tRoll number\tMarks"<<endl;
    for(int i=0;i<currentcount;i++){
        cout<<names[i]<<"\t "<<rollnumber[i]<<"\t\t"<<marks[i]<<endl;
    }
}

void classAverage()
{
    system("cls");
   
        
    float total = 0;
    for (int i = 0; i < currentcount; i++){
        total =total + marks[i];
    
    }
    cout << "Average marks of class: " << total / currentcount << endl;
}

void totalAdmissions()
{
    system("cls");
    cout << "Total students registered: " << currentcount << endl;
}

void deleteAllData()
{
    system("cls");
    string confirm;
    cout << "Enter --YES-- to confirm delete all: ";
    cin >> confirm;
    if (confirm == "YES")
    {
        currentcount = 0;
        saveData(); // Clear file contents by saving empty state
        cout << "All data cleared!" << endl;
    }
}

void updateAdmin()
{
    system("cls");
    string u, p;
    cout << "Old User Name: ";
    cin >> u;
    cout << "Old Pass: ";
    cin >> p;
    if (u == nameAdmin && p == passcode)
    {
        cout << "New Username: ";
        cin >> nameAdmin;
        cout << "New Password: ";
        cin >> passcode;
        saveData(); // Save updated credentials to the file permanently
        cout << "Password Updated!" << endl;
    }
}

// --- User Section Functions ---

void userViewResult()
{
    system("cls");
    int roll;
    cout << "Enter your roll number: ";
    cin >> roll;
    bool found=false;
    for (int i = 0; i < currentcount; i++)
    {
        if (rollnumber[i] == roll)
        {
            cout << "Name: " << names[i]<<endl; 
           cout << "Marks: " << marks[i] << endl;
            found=true;
            break;
        }
    }
    if(found==false){
    cout << "Result not found!" << endl;
    }
}

void userHighestMarks()
{
    system("cls");
   
    float maxMarks = marks[0];
    for(int i=1;i<currentcount;i++){
        if(maxMarks<marks[i]){
            maxMarks=marks[i];
        }
    }
    cout<<"Highest marks in the class is :"<<maxMarks;
    
}

void userViewAllNames()
{
    system("cls");
    for (int i = 0; i < currentcount; i++)
        cout << i + 1<<" Name :" << names[i] << endl;
}

void userSearchByName()
{
    system("cls");
    string n;
    cout << "Enter name to search: ";
    cin >> n;
    bool found=false;
    for (int i = 0; i < currentcount; i++)
    {
        if (names[i] == n)
        {
            cout << "Name\tRoll number\tMarks"<<endl;
            cout<<names[i]<<"\t"<<rollnumber[i]<<"\t\t"<<marks[i]<<endl;
            found=true;
            break;
        }
    }
    if(found==false){
        cout<<"Not found !";
    }
}

int main()
{
    loadData(); // Load any previously saved data from file
    int mainchoice, adminchoice, userchoice;
    bool keeprunning = true;

    while (keeprunning)
    {
        system("cls");
        cout << "============================================================" << endl;
        cout << "===========WELCOME TO SCHOOL MANAGEMENT SYSTEM==============" << endl;
        cout << "============================================================" << endl;
        cout << " 1. Enter as Admin" << endl;
        cout << " 2. Enter as User " << endl;
        cout << " 3. Exit the system " << endl;
        cout << " Please Enter your choice :";
        cin >> mainchoice;

        if (mainchoice == 1)
        {
            string u, p;
            cout << "User Name: ";
            cin >> u;
            cout << "PassWord: ";
            cin >> p;
            if (u == nameAdmin && p == passcode)
            {
                bool admin = true;
                while (admin)
                {
                    system("cls");
                    cout << "1. Add Student\n2. View All Students\n3. Delete Student By Rollnumber\n4. Update Marks\n5. Search BY Rollnumber\n6. Sort By Marks\n7.Total Average Of Class\n8. Total Admissions\n9. Delete All Data\n10. Main Menu\n11. Update Password\nEnter your Choice: ";
                    cin >> adminchoice;

                    if (adminchoice == 1)
                        addStudent();
                    else if (adminchoice == 2)
                        viewAll();
                    else if (adminchoice == 3)
                        deleteStudent();
                    else if (adminchoice == 4)
                        updateMarks();
                    else if (adminchoice == 5)
                        searchStudent();
                    else if (adminchoice == 6)
                        sortByMarks();
                    else if (adminchoice == 7)
                        classAverage();
                    else if (adminchoice == 8)
                        totalAdmissions();
                    else if (adminchoice == 9)
                        deleteAllData();
                    else if (adminchoice == 10)
                        admin = false;
                    else if (adminchoice == 11)
                        updateAdmin();

                    if (adminchoice != 10)
                    {
                        cout << "\nPress Enter...";
                        cin.ignore();
                        cin.get();
                    }
                }
            }
        }
        else if (mainchoice == 2)
        {
            bool student = true;
            while (student)
            {
                system("cls");
                cout << "1. View Result By Rollnumber\n2. Highest Marks in class\n3. All Names of student\n4. See Student Status By Name\n5. Exit to MainMenu\nChoice: ";
                cin >> userchoice;
                if (userchoice == 1)
                    userViewResult();
                else if (userchoice == 2)
                    userHighestMarks();
                else if (userchoice == 3)
                    userViewAllNames();
                else if (userchoice == 4)
                    userSearchByName();
                else if (userchoice == 5)
                    student = false;

                if (userchoice != 5)
                {
                    cout << "\nPress Enter...";
                    cin.ignore();
                    cin.get();
                }
            }
        }
        else if (mainchoice == 3)
        {
            cout<<"Exiting from Main System... ";
            keeprunning = false;
            
        }
    }
    return 0;
}
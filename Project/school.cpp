#include <iostream>
using namespace std;
main()
{
    int maxstudent = 100;
    string names[maxstudent]={"ali","aminaa","ammar","hafsa"};
    int rollnumber[maxstudent]={1,3,4,5};
    float marks[maxstudent]={1009,1000,1001,1054};
    string username, password,name="admin",passcode="123";
    int mainchoice, adminchoice, userchoice, currentcount = 0;
    bool keeprunning = true;
    // program will run until user himself want to exit
    while (keeprunning)
    {
        system("cls");

        cout
            << endl
            << "--------------------------------------------------" << endl;
        cout << "-------WELCOME TO SCHOOL MANAGEMENT SYSTEM--------" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "1. Enter as ADMIN" << endl;
        cout << "2. Enter as User/Student (to view only)" << endl;
        cout << "3. To EXIT The System" << endl;
        cout << "Please enter your choice(1-3):";
        cin >> mainchoice;

        if (mainchoice == 1)
        {
            // admin section
            system("cls");
               

            cout << "------ADMIN SECTION------" << endl;


            cout << "VERIFICATION BY PASS" << endl;
            cout << "Enter User name :";
            cin >> username;
            cout << "Enter Password:";
            cin >> password;
            if (name == username && passcode == password)
            {
                // after enterining in admin
                bool admin = true;
                while (admin)
                {

                    // admin code
                    system("cls");

                    cout << endl
                         << endl
                         << "---WelCome TO ADMIN PANAL---" << endl;
                    cout << "1. Add student record" << endl;
                    cout << "2. View all student " << endl;
                    cout << "3. Delete student " << endl;
                    cout << "4. Update marks" << endl;
                    cout << "5. Search students " << endl;
                    cout << "6. Sort by marks" << endl;
                    cout << "7. Calculate class average" << endl;
                    cout << "8. Total number of admissions" << endl;
                    cout << "9. DELETE all " << endl;
                    cout << "10.Return to Main Manu" << endl;
                    cout << "11. Update your User name and Password";
                    cout << "Please enter your choice :";
                    cin >> adminchoice;
                    // choices starts from here
                    if (adminchoice == 1)
                    {
                        // Add student

                        system("cls");

                        if (currentcount < maxstudent)
                        {

                            cout << "Enter name of the student :";
                            cin >> names[currentcount];
                            cout << "Enter roll number of the student :";
                            cin >> rollnumber[currentcount];
                            cout << "Enter marks of the student :";
                            cin >> marks[currentcount];
                            currentcount++;
                            cout << "---Data is saved---" << endl;
                        }
                    }
                    else if (adminchoice == 2)
                    {

                        system("cls");

                        // view all students

                        cout << "---student list---" << endl;
                        cout<<"Name\tRollnumber\tMarks"<<endl;
                        for (int i = 0; i < currentcount; i++)
                        {
                            cout <<names[i] << "\t   " << rollnumber[i] << "\t\t" << marks[i] << endl;
                        }
                    }
                    
                    else if (adminchoice == 3)
                    {

                        // Delete any student from record
                        system("cls");

                        cout << "Delete student from record" << endl;
                        cout << "Enter the roll no of the student you want to delete :";
                        int roll;
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
                                found = true;
                                cout << "---Record Deleted---" << endl;
                                break;
                            }
                        }
                        if (found == false)
                        {
                            cout << "Roll Number Not Found !" << endl;
                        }
                    }

                    // exit from admin

                    else if (adminchoice == 10)
                    {
                        
                        // exixting from admin
                        cout << "---Exiting to the main menu---";
                        admin = false;
                        break;
                    }

                    //update password

                    else if(adminchoice==11){

                        system("cls");

                        string newUsername,newPassword;
                        
                        cout<<"Enter your previous user :";
                        cin>>username;
                        cout<<"Enter your previous password :";
                        cin>>password;
                        if(username=="admin" && password=="123"){
                            cout<<"enter new user name : ";
                            cin>>newUsername;
                            cout<<"enter new password : ";
                            cin>>newPassword;
                            name=newUsername;
                            passcode=newPassword;


                        }

                    }

                    else if (adminchoice == 4)

                    // update marks of the student

                    {
                        system("cls");

                        cout << "Enter the roll no. you want to update marks :";
                        int roll;
                        int m;
                        bool found = false;
                        cin >> roll;
                        for (int i = 0; i < currentcount; i++)
                        {
                            if (rollnumber[i] == roll)
                            {
                                cout << "Previous Marks :" << marks[i] << endl;
                                cout << "Name of student :" << names[i] << endl;
                                cout << "Enter Updated Marks :";
                                cin >> m;
                                marks[i] = m;
                                found = true;
                                cout << "---Marks updated---";
                                break;
                            }
                        }
                        if (found == false)
                        {
                            cout << "Roll no not found !!" << endl;
                        }
                    }
                    else if (adminchoice == 5)

                    // search by roll number

                    {
                        system("cls");

                        cout << "Ente the roll no. of the student you want to search : ";
                        int roll;
                        cin >> roll;
                        bool found = false;
                        for (int i = 0; i < currentcount; i++)
                        {
                            if (rollnumber[i] == roll)
                            {
                                cout << "Student name :" << names[i] << " Marks obtained :" << marks[i];
                            }

                            found = true;
                            cout << "roll number not found ";

                            break;
                        }
                        if (found == false)
                        {
                            cout << "Student not found !!";
                        }
                    }
                    else if (adminchoice == 6)

                    // sort by marks

                    {
                        system("cls");

                        // Bubble sorting by marks
                        for (int i = 0; i < currentcount - 1; i++)
                        {
                            for (int j = 0; j < currentcount - i - 1; j++)
                            {
                                if (marks[j] < marks[j + 1])
                                {
                                    int temp = marks[j];
                                    marks[j] = marks[j + 1];
                                    marks[j + 1] = temp;
                                }
                            }
                        }
                        // Total students
                        cout << "Students are arranged in assending oreder according to roll no ! ";
                        cout<<endl<<"Name\tRollnumber\tMarks"<<endl;
                        for (int i = 0; i < currentcount; i++)
                        {
                            cout <<names[i] << "\t   " << rollnumber[i] << "\t\t" << marks[i] << endl;
                        }               
                    }
                    else if (adminchoice == 7)
                    // class average
                    {

                        system("cls");

                        float total = 0;
                        float average;
                        for (int i = 0; i < currentcount; i++)
                        {
                            total = total + marks[i];
                        }
                        if (currentcount > 0)
                        {
                            average = total / currentcount;
                            cout << "Average of the class marks is " << average << endl;
                        }
                    }
                    else if (adminchoice == 8)
                    // total number of admissions

                    {
                        system("cls");

                        cout << "Total student registered :" << currentcount << endl;
                    }
                    else if (adminchoice == 9)
                    {
                        // delete all data

                        system("cls");
                        string n;
                        cout << "Enter --YES-- to confirm :";
                        cin >> n;

                        if (n == "YES")
                        {

                            currentcount = 0;
                            cout << "=============================" << endl;
                            cout << "==== All data is cleared====" << endl;
                            cout << "=============================" << endl;
                        }
                        else
                        {

                            cout << "---Not Confirm---";
                        }
                    }
                }
            }
            else
            {
                cout << "Incorrect user name or password !" << endl;
                cout<<"press ENTER key to continue....";
                cin.ignore();
                cin.get();
                
            }
        
        }
        // exit the system

        else if (mainchoice == 3)
        {

            cout << "---Exiting from the main system---" << endl;
            keeprunning = false;
        }
        else if (mainchoice == 2)
        {
            // user menu

            system("cls");

            bool student = true;
            while (student)
            {
                // user menu
                cout << endl

                     << endl
                     << "------USER MENU------" << endl;
                cout << "1. View Result By Roll Number " << endl;

                cout << "2. View Highest Marks" << endl;
                cout << "3. View All student names " << endl;
                cout << "4. Search student by names " << endl;
                cout << "5. Exit to MAIN MENU" << endl;
                cout << "Enter your choice :";
                cin >> userchoice;

                // user choice if 1 view result

                if (userchoice == 1)
                {

                    // view result by roll number
                    system("cls");

                    cout << "----View Your Result----" << endl;
                    int roll;
                    cout << "Please Enter your Roll number :";
                    cin >> roll;
                    bool found = false;
                    for (int i = 0; i < currentcount; i++)
                    {
                        if (roll == rollnumber[i])
                        {
                            cout << "Your name is " << names[i] << "you obtained " << marks[i] << "Marks" << endl;
                            found = true;
                            break;
                        }
                    }
                    if (found == false)
                    {
                        cout << "----Result Not Found----" << endl;
                    }
                }

                // choice 2 highest marks

                else if (userchoice == 2)
                // highest marks

                {
                    system("cls");
                    cout << "---Highest Marks Obtained---" << endl;
                    int max;
                    max = marks[0];
                    for (int i = 1; i < currentcount; i++)
                    {
                        if (marks[i] > max)
                        {
                            max = marks[i];
                        }
                    }
                    cout << "Highest Marks obtained in class is " << max;
                }
                else if (userchoice == 5)
                {
                    // exit to main menu
                    cout << "---Exiting From Student Menu---" << endl;
                    student = false;
                }
                else if (userchoice == 3)
                // names of all the students

                {
                    system("cls");

                    cout << "==== All students names ====";
                    for (int i = 0; i < currentcount; i++)
                    {
                        cout << i + 1 << " Name is :" << names[i] << endl;
                    }
                }
                else if (userchoice == 4)
                {

                    system("cls");

                    // seaarch by name
                    cout << "Enter the name of the student you want to search :";
                    string n;
                    cin >> n;
                    bool found = false;
                    for (int i = 0; i < currentcount; i++)
                    {
                        if (names[i] == n)
                        {

                            cout << "Name of the student : " << names[i] << "Marks obtain : " << marks[i] << " Roll number is : " << rollnumber[i];
                            found = true;
                            break;
                        }
                    }

                    if (found == false)
                    {
                        cout << "--- Name not found ---";
                    }
                }

                else

                {
                    cout << "Your Choice is invalid please enter again !" << endl;
                }
            }
        }
        else
        {
            cout << "Your choice is invalid please enter again !" << endl;
        }
    }
}
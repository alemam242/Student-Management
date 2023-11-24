#include <bits/stdc++.h>
using namespace std;
void isLoggedIn();
string registration();
void forgotPassword();

class Student
{

private:
    int rollno, age;

    string name;

public:
    Student(int stdId, string stdName, int stdAge)
    {

        rollno = stdId;

        name = stdName;

        age = stdAge;
    }

    void setRollno(int stdId)
    {

        rollno = stdId;
    }

    int getRollno()
    {

        return rollno;
    }

    void setName(string stdName)
    {

        name = stdName;
    }

    string getName()
    {

        return name;
    }

    void setAge(int stdAge)
    {

        age = stdAge;
    }

    int getAge()
    {

        return age;
    }

    void displayStudent()
    {

        cout << "Roll No : " << rollno << endl;

        cout << "Name :" << name << endl;

        cout << "Age : " << age << endl;
    }
};

// Create functionto update Student record

void updateStudent(vector<Student> &students)
{

    string sname;

    bool found = false;

    int choice;

    cout << "\t\tEnter Name to Update Record :";

    cin.ignore();

    getline(cin, sname);

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].getName() == sname)
        {

            found = true;

            cout << "\t\t---Student Found -----" << endl;

            cout << "\t\t 1. Update Rollno " << endl;

            cout << "\t\t 2. Update Name " << endl;

            cout << "\t\t 3. Update Age " << endl;

            cout << "\t\tEnter Your Choice :";

            cin >> choice;

            switch (choice)
            {

            case 1:
            {

                int rno;

                cout << "\t\tEnter New Rollno :";

                cin >> rno;

                students[i].setRollno(rno);

                break;
            }

            case 2:
            {

                string name;

                cout << "\t\tEnter New Name :";

                cin.ignore();

                getline(cin, name);

                students[i].setName(name);

                break;
            }

            case 3:
            {

                int age;

                cout << "\t\tEnter New Age :";

                cin >> age;

                students[i].setAge(age);

                break;
            }

            default:

                cout << "\t\tInvalid Number" << endl;
            }
        }

        if (!found)
        {

            cout << "\t\tRecord Not Found" << endl;

            return;
        }
    }
}

// create function to search studnet in list

void SearchStudent(vector<Student> &students)
{

    int rollno;

    cout << "\t\tEnter Rollno :";

    cin >> rollno;

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].getRollno() == rollno)
        {

            cout << "\t\t--------Student Found ------------" << endl;

            students[i].displayStudent();

            return;
        }
    }
}

// create function to show all list of  student

void DisplayAllStudent(vector<Student> &students)
{

    if (students.empty())
    {

        cout << "\t\t No Student Found " << endl;

        return;
    }

    for (int i = 0; i < students.size(); i++)
    {

        students[i].displayStudent();

        cout << endl;
    }
}

// create function to add new student

void addNewStudent(vector<Student> &students)
{

    int rollno, age;

    string name;

    cout << "Enter Rollno :";

    cin >> rollno;

    // check if student already exit

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].getRollno() == rollno)
        {

            cout << "\t\tStudent Already Exit" << endl;

            return;
        }
    }

    cout << "Enter Name : ";

    cin >> name;

    cout << "Enter Age : ";

    cin >> age;

    Student newStudent(rollno, name, age);

    students.push_back(newStudent);
}

// create function to delete student in list

void deleteStudent(vector<Student> &students)
{

    string name;

    cout << "Enter Name to Delete :";

    cin.ignore();

    getline(cin, name);

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].getName() == name)
        {

            students.erase((students.begin() + i));

            cout << "\t\tStudent Remove Successfully" << endl;
        }
    }
}

main()
{
    int choice;

    do
    {
        system("CLS");
        cout << "\n\t\t--------------------------------";

        cout << "\n\t\t*** Student Management System ***";

        cout << "\n\t\t--------------------------------";

        cout << "\n\t\t 1. Registration" << endl;

        cout << "\t\t 2. Login " << endl;

        cout << "\t\t 3. Forgot Password " << endl;

        cout << "\t\t 4. Exit" << endl;

        cout << "\t\t Enter Your Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            cout << registration();
            system("PAUSE");
            main();
        }
        else if (choice == 2)
        {
            isLoggedIn();
        }
        else if (choice == 3)
        {
            forgotPassword();
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            cout << "Please Enter valid key\n";
            system("PAUSE");
        }
    } while (choice != 1 || choice != 2);
}

void dashboard()
{
    vector<Student> students;

    // students.push_back(Student(1, "ali", 35));

    char choice;

    do
    {

        system("cls");

        int op;

        cout << "\n\t\t--------------------------------";

        cout << "\n\t\t*** Student Management System ***";

        cout << "\n\t\t--------------------------------";

        cout << "\n\t\t 1. Add New Student" << endl;

        cout << "\t\t 2. Display All Student " << endl;

        cout << "\t\t 3. Search Student" << endl;

        cout << "\t\t 4. Update Student" << endl;

        cout << "\t\t 5. Delete Student " << endl;

        cout << "\t\t 6. Logout" << endl;

        cout << "\t\t 7. Exit" << endl;

        cout << "\t\t Enter Your Choice : ";

        cin >> op;

        switch (op)
        {

        case 1:

            addNewStudent(students);

            break;

        case 2:

            DisplayAllStudent(students);

            break;

        case 3:

            SearchStudent(students);

            break;

        case 4:

            updateStudent(students);

            break;

        case 5:

            deleteStudent(students);

            break;

        case 6:

            main();

            break;

        case 7:

            exit(0);

        default:

            cout << "\t\tInvalid Number " << endl;
        }

        cout << "\t\tDo You Want to Continue [Yes/No] ? :";

        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

void isLoggedIn()
{
    string username, password, un, ps;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, ps);

    if (un == username && ps == password)
    {
        dashboard();
    }
    else
    {
        cout << "Login Failed" << endl;
        system("PAUSE");
        main();
    }
}

string registration()
{
    string username, password;
    cout << "Set username: ";
    cin >> username;

    cout << "Set password: ";
    cin >> password;

    ofstream file;

    file.open(username + ".txt");

    file << username << endl
         << password;

    file.close();

    return "Registration successful.\nNow you can login.\n";
}

void forgotPassword()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    ifstream read(username + ".txt");

    if (!read.is_open())
    {
        cout << "User does not exist!" << endl;
        system("PAUSE");
        main();
    }

    cout << "Set new password: ";
    cin >> password;

    ofstream file;

    file.open(username + ".txt");

    file << username << endl
         << password;

    file.close();

    cout << "Password changed successfully.\nNow you can login.\n";

    system("PAUSE");
    main();
}
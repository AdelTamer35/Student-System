#include "controller/Contoller.cpp"
void showService(string service)
{
    cout << "****************** Hello " << service << " Management System ******************" << endl;
    cout << "1. Add " << service << "\t\t"
         << "2. Update " << service << endl;
    cout << "3. Delete " << service << "\t"
         << "4. Display " << service << endl;
    cout << "5. Exit \n";
}
void AddStudent()
{
    Student student;
    string name, phoneNumber, email;
    int age, ID;
    double GPA;

    // Get Student Data from User
    cout << "Please Enter Student Data ! \n";

    cout << "Enter Student Name : ";
    cin >> name;
    student.setName(name);

    cout << "Enter Phone Number : ";
    cin >> phoneNumber;
    student.setPhoneNumber(phoneNumber);

    cout << "Enter Email :";
    cin >> email;
    student.setEmail(email);

    cout << "Enter Age :";
    cin >> age;
    student.setAge(age);

    cout << "Enter GPA :";
    cin >> GPA;
    student.setGPA(GPA);

    // Store Student
    StudentController studentController;
    ID = studentController.addStudent(student);

    cout << "Student Data = { " << "Name : " << name << endl
         << "ID : " << ID << endl
         << "Phone Number : " << phoneNumber << endl
         << "Email : " << email << endl
         << "Age : " << age << endl
         << "GPA : " << GPA << " }\n";
}
int main()
{

    int process = 1, service;
    while (process != 4)
    {
        cout << "****************** Hello Management System ******************" << endl;
        cout << "Please Enter Your Process You Want To Do ! \n";

        cout << "1. About Student \t 2. About Course \n";
        cout << "3. About Teacher \t 4. Exit \n";
        cin >> process;

        switch (process)
        {

        // **************** Student Services ****************
        case 1:
        {
            showService("Student");

            cout << "which Service You Want To Need ! \n";
            cin >> service;

            switch (service)
            {
            case 1:
            {
                while (true)
                {
                    cout << "Add Student \n";
                    AddStudent();
                    cout << "Do you want to add another student? (y/n) ";
                    char choice;
                    cin >> choice;
                    if (choice == 'n' || choice == 'N')
                        break;
                }
                break;
            }
            case 2:
            {
                cout << "Update Student \n";
                break;
            }
            case 3:
            {
                cout << "Delete Student \n";
                break;
            }
            case 4:
            {
                cout << "Display Student \n";
                break;
            }
            case 5:
            {
                cout << "Exit \n";
                break;
            }
            default:
                cout << "Invalid Process \n";
                break;
            }

            break;
        }

        // **************** Course Services ****************
        case 2:
            showService("Course");
            break;

        // **************** Teacher Services ****************
        case 3:
            showService("Teacher");
            break;
        case 4:
            cout << "Exit \n";
            break;
        default:
            cout << "Invalid Process \n";
            break;
        }
    }

    return 0;
}
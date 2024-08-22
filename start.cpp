#include "controller/Contoller.cpp"
void showService(string service)
{
    cout << "****************** Hello " << service << " Management System ******************" << endl;
    cout << "1. Add " << service << endl;
    cout << "2. Update " << service << endl;
    cout << "3. Delete " << service << endl;
    cout << "4. Display " << service << endl;
    cout << "5. Exit \n";
}
int main()
{

    int process = 1;
    while (process != 4)
    {
        cout << "****************** Hello Management System ******************" << endl;
        cout << "Please Enter Your Process You Want To Do ! \n";

        cout << "1. About Student \n";
        cout << "2. About Course \n";
        cout << "3. About Teacher \n";
        cout << "4. Exit \n";
        cin >> process;

        switch (process)
        {
        case 1:
        {
            showService("Student");
            int service;
            cin >> service;
            if (service == 1) // Add Student
            {
                Student student;
                string name, phoneNumber, email;
                int age;
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
                studentController.addStudent(student);

                cout << "Student Data = { " << "Name : " << name << endl
                     << "Phone Number : " << phoneNumber << endl
                     << "Email : " << email << endl
                     << "Age : " << age << endl
                     << "GPA : " << GPA << " }\n";
            }

            break;
        }
        case 2:
            showService("Course");
            break;
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
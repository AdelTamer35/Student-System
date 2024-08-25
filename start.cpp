#include "controller/Contoller.cpp"
// Display Services
void showService(string service)
{
    cout << "****************** Hello " << service << " Management System ******************" << endl;
    cout << "1. Add " << service << "\t\t"
         << "2. Update " << service << endl;
    cout << "3. Delete " << service << "\t"
         << "4. Display " << service << endl;
    cout << "5. Exit \n";
}
// Add Student
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

    // Display Student Data
    cout << "Student Data = { " << "Name : " << name << endl
         << "ID : " << ID << endl
         << "Phone Number : " << phoneNumber << endl
         << "Email : " << email << endl
         << "Age : " << age << endl
         << "GPA : " << GPA << " }\n";
}
// Add Course
void AddCourse()
{
    Course course;
    double hour;
    int ID;
    string name;

    // Get Course Data from User
    cout << "Please Enter Course Data ! \n";

    cout << "Enter Course Name : ";
    cin >> name;
    course.setName(name);

    cout << "Enter Hour :";
    cin >> hour;
    course.setHour(hour);

    // Store Course
    CoureController courseController;
    ID = courseController.addCourse(course);

    // Display Course Data
    cout << "Course Data = { " << "Name :" << name << endl
         << "ID = " << ID << endl
         << "Hour = " << hour << " }\n";
}
// Add Teacher
void AddTeacher()
{
    Teacher teacher;
    string name, phoneNumber, email;
    int ID, age;
    double salary;

    // Get Teacher Data from User
    cout << "Please Enter Teacher Data ! \n";

    cout << "Enter Teacher Name : ";
    cin >> name;
    teacher.setName(name);

    cout << "Enter Phone Number : ";
    cin >> phoneNumber;
    teacher.setPhoneNumber(phoneNumber);

    cout << "Enter Age :";
    cin >> age;
    teacher.setAge(age);

    cout << "Enter Email :";
    cin >> email;
    teacher.setEmail(email);

    cout << "Enter Salary :";
    cin >> salary;
    teacher.setSalary(salary);

    // Store Teacher
    TeacherController teacherController;
    ID = teacherController.addTeacher(teacher);

    // Display Teacher Data
    cout << "Teacher Data = { " << "Name : " << name << endl
         << "ID : " << ID << endl
         << "Phone Number : " << phoneNumber << endl
         << "Email : " << email << endl
         << "Age : " << age << endl
         << "Salary : " << salary << " }\n";
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
            // Add Student
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
            // Update Student
            case 2:
            {
                cout << "Update Student \n";
                break;
            }
            // Delete Student
            case 3:
            {
                cout << "Delete Student \n";
                break;
            }
            // Display Student
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
            cout << "which Service You Want To Need ! \n";
            cin >> service;

            switch (service)
            {
            // Add Course
            case 1:
            {
                while (true)
                {
                    cout << "Add Course \n";
                    AddCourse();
                    cout << "Do you want to add another course? (y/n) ";
                    char choice;
                    cin >> choice;
                    if (choice == 'n' || choice == 'N')
                        break;
                }
                break;
            }
            // Update Course
            case 2:
            {
                cout << "Update Course \n";
                break;
            }
            // Delete Course
            case 3:
            {
                cout << "Delete Course \n";
                break;
            }
            // Display Course
            case 4:
            {
                cout << "Display Course \n";
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

        // **************** Teacher Services ****************
        case 3:
            showService("Teacher");
            cout << "which Service You Want To Need ! \n";
            cin >> service;

            switch (service)
            {
            // Add Teacher
            case 1:
            {
                while (true)
                {
                    cout << "Add Teacher \n";
                    AddTeacher();
                    cout << "Do you want to add another teacher? (y/n) ";
                    char choice;
                    cin >> choice;
                    if (choice == 'n' || choice == 'N')
                        break;
                }

                break;
            }
            // Update Teacher
            case 2:
            {
                cout << "Update Teacher \n";
                break;
            }
            // Delete Teacher
            case 3:
            {
                cout << "Delete Teacher \n";
                break;
            }
            // Display Teacher
            case 4:
            {
                cout << "Display Teacher \n";
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
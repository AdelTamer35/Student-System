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
    string name, phoneNumber, email, s;
    int age, ID;
    double GPA;

    // Get Student Data from User
    cout << "Please Enter Student Data ! \n";

    getline(cin, s);

    cout << "Enter Student Name : ";
    getline(cin, name);
    student.setName(name);

    cout << "Enter Phone Number : ";
    getline(cin, phoneNumber);
    student.setPhoneNumber(phoneNumber);

    cout << "Enter Email :";
    getline(cin, email);
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

    if (ID != -1)
    {
        // Display Student Data
        cout << "Student Data = { " << "Name : " << name << endl
             << "ID : " << ID << endl
             << "Phone Number : " << phoneNumber << endl
             << "Email : " << email << endl
             << "Age : " << age << endl
             << "GPA : " << GPA << " }\n";
    }
    else
        cout << "Student Not Added\n";
}
// Add Course
void AddCourse()
{
    Course course;
    double hour;
    int ID;
    string name, s;

    // Get Course Data from User
    cout << "Please Enter Course Data ! \n";

    getline(cin, s);

    cout << "Enter Course Name : ";
    getline(cin, name);
    course.setName(name);

    cout << "Enter Hour :";
    cin >> hour;
    course.setHour(hour);

    // Store Course
    CoureController courseController;
    ID = courseController.addCourse(course);

    if (ID != -1)
    {
        // Display Course Data
        cout << "Course Data = { " << "Name :" << name << endl
             << "ID = " << ID << endl
             << "Hour = " << hour << " }\n";
    }
    else
        cout << "Course Not Added\n";
}
// Add Teacher
void AddTeacher()
{
    Teacher teacher;
    string name, phoneNumber, email, s;
    int ID, age;
    double salary;

    // Get Teacher Data from User
    cout << "Please Enter Teacher Data ! \n";

    getline(cin, s);

    cout << "Enter Teacher Name : ";
    getline(cin, name);
    teacher.setName(name);

    cout << "Enter Phone Number : ";
    getline(cin, phoneNumber);
    teacher.setPhoneNumber(phoneNumber);

    cout << "Enter Email :";
    getline(cin, email);
    teacher.setEmail(email);

    cout << "Enter Age :";
    cin >> age;
    teacher.setAge(age);

    cout << "Enter Salary :";
    cin >> salary;
    teacher.setSalary(salary);

    // Store Teacher
    TeacherController teacherController;
    ID = teacherController.addTeacher(teacher);

    if (ID != -1)
    {
        // Display Teacher Data
        cout << "Teacher Data = { " << "Name : " << name << endl
             << "ID : " << ID << endl
             << "Phone Number : " << phoneNumber << endl
             << "Email : " << email << endl
             << "Age : " << age << endl
             << "Salary : " << salary << " }\n";
    }
    else
        cout << "Teacher Not Added\n";
}

// Dispaly Student
void DisplayStudentByID()
{
    int id;
    cout << "Enter The Student ID You Want To Diplay His Data : ";

    // Get Student ID From User
    cin >> id;

    // Search About Student ID
    StudentController studentController;
    Student student;
    student = studentController.dispalyStudenByID(id);

    if (student.getID() != -1)
    {
        // Display Student Data
        cout << "Student Is Found" << endl;
        cout << "Student Data = { " << "Name : " << student.getName() << endl
             << "ID : " << student.getID() << endl
             << "Phone Number : " << student.getPhoneNumber() << endl
             << "Email : " << student.getEmail() << endl
             << "Age : " << student.getAge() << endl
             << "GPA : " << student.getGPA() << " }\n";
    }
    else
        cout << "Student Not Found" << endl;
}

// Student Services
void SwitchStudent(int service)
{
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
        while (true)
        {
            cout << "Display Student \n";
            DisplayStudentByID();
            cout << "Do you want to Dispaly another student? (y/n) ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N')
                break;
        }

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
}
// Course Services
void SwitchCourse(int service)
{
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
}
// Teacher Services
void SwitchTeacher(int service)
{
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
            SwitchStudent(service);

            break;
        }

        // **************** Course Services ****************
        case 2:
        {
            showService("Course");

            cout << "which Service You Want To Need ! \n";
            cin >> service;
            SwitchCourse(service);

            break;
        }
        // **************** Teacher Services ****************
        case 3:
        {
            showService("Teacher");
            cout << "which Service You Want To Need ! \n";
            cin >> service;
            SwitchTeacher(service);

            break;
        }
        case 4:
        {
            cout << "Exit \n";
            break;
        }
        default:
        {
            cout << "Invalid Process \n";
            break;
        }
        }
    }

    return 0;
}
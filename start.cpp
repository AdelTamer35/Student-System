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

// Dispaly Student By ID
void DisplayStudentByID()
{
    int id;
    cout << "Enter The Student ID You Want To Diplay His Data : ";

    // Get Student ID From User
    cin >> id;

    // Search About Student ID
    StudentController studentController;
    Student student;
    student = studentController.displayStudenByID(id);

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
// Display Course By ID
void DisplayCourseByID()
{
    int id;
    cout << "Enter The Course ID You Want To Diplay His Data : ";

    // Get Course ID From User
    cin >> id;

    // Search About Course ID
    CoureController courseController;
    Course course;
    course = courseController.displayCourseByID(id);

    if (course.getID() != -1)
    {
        // Display Course Data
        cout << "Course Is Found" << endl;
        cout << "Course Data = { " << "Name : " << course.getName() << endl
             << "ID : " << course.getID() << endl
             << "Hour : " << course.getHour() << " }\n";
    }
    else
        cout << "Course Not Found" << endl;
}
// Display Teacher By ID
void DisplayTeacherByID()
{
    int id;
    cout << "Enter The Teacher ID You Want To Diplay His Data : ";

    // Get Teacher ID From User
    cin >> id;

    // Search About Teacher ID
    TeacherController teacherController;
    Teacher teacher;
    teacher = teacherController.displayTeacherByID(id);

    if (teacher.getID() != -1)
    {
        // Display Teacher Data
        cout << "Teacher Data = { " << "Name : " << teacher.getName() << endl
             << "ID : " << teacher.getID() << endl
             << "Phone Number : " << teacher.getPhoneNumber() << endl
             << "Email : " << teacher.getEmail() << endl
             << "Age : " << teacher.getAge() << endl
             << "Salary : " << teacher.getSalary() << " }\n";
    }
    else
        cout << "Teacher Not Found" << endl;
}

// Update Student Data
Student updateStudentData(int choice, Student &student)
{
    string data;
    switch (choice)
    {
    // Update Student Name
    case 1:
    {
        cout << "Enter New Name : ";
        cin.ignore();
        getline(cin, data);
        student.setName(data);
        break;
    }
    // Update Student Phone Number
    case 2:
    {
        cout << "Enter New Phone Number : ";
        cin.ignore();
        getline(cin, data);
        student.setPhoneNumber(data);
        break;
    }
    // Update Student Email
    case 3:
    {
        cout << "Enter New Email : ";
        cin.ignore();
        getline(cin, data);
        student.setEmail(data);
        break;
    }
    // Update Student Age
    case 4:
    {
        cout << "Enter New Age : ";
        cin >> data;
        student.setAge(stoi(data));
        break;
    }
    // Update Student GPA
    case 5:
    {
        double GPA;
        cout << "Enter New GPA : ";
        cin >> GPA;
        student.setGPA(GPA);
        break;
    }
    }
    return student;
}
// Update Student By ID
void UpdateStudentByID()
{
    int id;
    cout << "Enter The Student ID You Want To Update His Data : ";

    // Get Student ID From User
    cin >> id;

    // Search About Student ID
    StudentController studentController;
    Student student;
    student = studentController.displayStudenByID(id);

    if (student.getID() != -1)
    {
        // Select Which Student Data You Want To Update
        cout << "Select Which Student Data You Want To Update : \n";
        cout << "1. Name \t 2. Phone Number \n"
             << "3. Email \t 4. Age \n"
             << "5. GPA \t\t 6. Exit \n";

        int choice;
        cin >> choice;

        if (choice == 6)
        {
            cout << "Exiting Update Student Menu \n";
            cout << "Student Not Updated\n";
            return;
        }
        else if (choice > 6 || choice < 1)
        {
            cout << "Invalid Choice \n";
            cout << "Student Not Updated\n";
            return;
        }

        // Update Student Data
        student = updateStudentData(choice, student);

        // Validate Student Data
        if (studentController.validateStudentData(student))
        {
            // Update Student Data in Database
            student = studentController.updateStudent(student);

            // Display Updated Student Data
            cout << "Student Data Updated Successfully \n";
            cout << "Updated Student Data = { " << "Name : " << student.getName() << endl
                 << "ID : " << student.getID() << endl
                 << "Phone Number : " << student.getPhoneNumber() << endl
                 << "Email : " << student.getEmail() << endl
                 << "Age : " << student.getAge() << endl
                 << "GPA : " << student.getGPA() << " }\n";
        }
        else
            cout << "Student Not Updated\n";
    }
    else
        cout << "Student Not Found \n";
}
// Update Course Data
Course updateCourseData(int choice, Course course)
{
    string data;
    switch (choice)
    {
    // Update Course Name
    case 1:
    {
        cout << "Enter New Name : ";
        cin.ignore();
        getline(cin, data);
        course.setName(data);
        break;
    }
    // Update Course Hour
    case 2:
    {
        cout << "Enter New Hour : ";
        cin >> data;
        course.setHour(stoi(data));
        break;
    }
    }
    return course;
}
// Update Course By ID
void UpdateCourseByID()
{
    int id;
    cout << "Enter The Course ID You Want To Update His Data : ";

    // Get Course ID From User
    cin >> id;

    // Search About Course ID
    CoureController courseController;
    Course course;
    course = courseController.displayCourseByID(id);

    if (course.getID() != -1)
    {
        // Select Which Course Data You Want To Update
        cout << "Select Which Course Data You Want To Update : \n";
        cout << "1. Name \t 2. Hour \n 3.Exit \n";

        int choice;
        cin >> choice;

        if (choice == 3)
        {
            cout << "Exiting Update Course Menu \n";
            cout << "Course Not Updated\n";
            return;
        }
        else if (choice > 3 || choice < 1)
        {
            cout << "Invalid Choice \n";
            cout << "Course Not Updated\n";
            return;
        }

        // Update Course Data
        course = updateCourseData(choice, course);

        // Validate Course Data
        if (courseController.validateCourseData(course))
        {
            // Update Course Data in Database
            course = courseController.updateCourse(course);
            // Display Updated Course Data
            cout << "Course Data Updated Successfully \n";
            cout << "Updated Course Data = { " << "Name : " << course.getName() << endl
                 << "ID : " << course.getID() << endl
                 << "Hour : " << course.getHour() << " }\n";
        }
        else
            cout << "Course Not Updated\n";
    }
    else
        cout << "Course Not Found \n";
}
// Update Teacher Data
Teacher updateTeacherData(int choice, Teacher teacher)
{
    string data;
    switch (choice)
    {
    case 1:
    {
        cout << "Enter New Name : ";
        cin.ignore();
        getline(cin, data);
        teacher.setName(data);
        break;
    }
    case 2:
    {
        cout << "Enter New Phone Number : ";
        cin.ignore();
        getline(cin, data);
        teacher.setPhoneNumber(data);
        break;
    }
    case 3:
    {
        cout << "Enter New Email : ";
        cin.ignore();
        getline(cin, data);
        teacher.setEmail(data);
        break;
    }
    case 4:
    {
        cout << "Enter New Age : ";
        cin >> data;
        teacher.setAge(stoi(data));
        break;
    }
    case 5:
    {
        double salary;
        cout << "Enter New Salary : ";
        cin >> salary;
        teacher.setSalary(salary);
        break;
    }
    }
    return teacher;
}
// Update Teacher By ID
void UpdateTeacherByID()
{
    int id;
    cout << "Enter The Teacher ID You Want To Update His Data : ";

    // Get Teacher ID From User
    cin >> id;

    // Search About Teacher ID
    TeacherController teacherController;
    Teacher teacher;
    teacher = teacherController.displayTeacherByID(id);

    if (teacher.getID() != -1)
    {
        // Select Which Teacher Data You Want To Update
        cout << "Select Which Teacher Data You Want To Update : \n";
        cout << "1. Name \t 2. Phone Number \n"
             << "3. Email \t 4. Age \n"
             << "5. Salary \t 6. Exit \n";

        int choice;
        cin >> choice;

        if (choice == 6)
        {
            cout << "Exiting Update Teacher Menu \n";
            cout << "Teacher Not Updated\n";
            return;
        }
        else if (choice > 6 || choice < 1)
        {
            cout << "Invalid Choice \n";
            cout << "Teacher Not Updated\n";
            return;
        }

        // Update Teacher Data
        teacher = updateTeacherData(choice, teacher);

        // Validate Teacher Data
        if (teacherController.validateTeacherData(teacher))
        {
            // Update Teacher Data in Database
            teacher = teacherController.updateTeacher(teacher);

            // Display Updated Teacher Data
            cout << "Teacher Data Updated Successfully \n";
            cout << "Updated Teacher Data = { " << "Name : " << teacher.getName() << endl
                 << "ID : " << teacher.getID() << endl
                 << "Phone Number : " << teacher.getPhoneNumber() << endl
                 << "Email : " << teacher.getEmail() << endl
                 << "Age : " << teacher.getAge() << endl
                 << "Salary : " << teacher.getSalary() << " }\n";
        }
        else
            cout << "Teacher Not Updated\n";
    }
    else
        cout << "Student Not Found\n";
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
        while (true)
        {
            cout << "Update Student \n";
            UpdateStudentByID();
            cout << "Do you want to Update another student? (y/n) ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N')
                break;
        }

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
            cout << "Display Student\n";
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
        while (true)
        {
            cout << "Update Course \n";
            UpdateCourseByID();
            cout << "Do you want to Update another course? (y/n) ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N')
                break;
        }
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
        while (true)
        {
            cout << "Display Course By ID\n";
            DisplayCourseByID();
            cout << "Do you want to Dispaly another course? (y/n) ";
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
        while (true)
        {
            cout << "Update Teacher \n";
            UpdateTeacherByID();
            cout << "Do you want to Update another teacher? (y/n) ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N')
                break;
        }
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
        while (true)
        {
            cout << "Display Teacher By ID\n";
            DisplayTeacherByID();
            cout << "Do you want to Dispaly another teacher? (y/n) ";
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
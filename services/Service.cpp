#include "../repo/Repository.cpp"
#include <regex>
// Abstract "Interface" Class For Student
class StudentService
{
public:
    virtual int addStudent(Student student) = 0;
    virtual Student displayStudenByID(int ID) = 0;
    virtual Student updateStudent(Student student) = 0;
    virtual bool validateStudentData(Student student) = 0;
    virtual Student *deleteStudent(int ID) = 0;
};
// Concrete "Implementation" Class for Student Service
class StudentServiceImp : public StudentService
{
private:
    StudentRepoImpl studentRepo;
    Data data;

public:
    // override
    // Add Student Validation
    int addStudent(Student student)
    {
        if (StudentServiceImp::validateStudentData(student))
            return studentRepo.addStudent(student);
        else
            return -1;
    }

    // Student Data Validation
    bool validateStudentData(Student student)
    {
        bool f = true;

        // Check Student Name
        if (student.getName().length() <= 2)
        {
            cout << "Invalid Student Name \n";
            cout << "The Length Of The Student Name Must Be At Least 3 Characters \n";
            f = false;
        }
        else
        {
            for (int i = 0; i < student.getName().length(); i++)
            {
                // check if  student.getName()[i] is not char or space
                if (!(student.getName()[i] == ' ' || isalpha(student.getName()[i])))
                {
                    cout << "Invalid Student Name \n";
                    cout << "The Student Name Must Only Contain Letter Or Space" << endl;
                    f = false;
                    break;
                }
            }
        }

        // Check Student Phone Number
        if (student.getPhoneNumber().length() != 11)
        {
            cout << "Invalid Student Phone Number \n";
            cout << "The Length Of The Student Phone Number Must Be 11 Digits \n";
            f = false;
        }
        else
        {

            /*
            010
            011
            012
            015
            */

            // Check three digits of Student Phone Number
            if (student.getPhoneNumber().substr(0, 3) != "010" &&
                student.getPhoneNumber().substr(0, 3) != "011" &&
                student.getPhoneNumber().substr(0, 3) != "012" &&
                student.getPhoneNumber().substr(0, 3) != "015")
            {
                cout << "Invalid Student Phone Number \n";
                cout << "The Student Phone Number Must Be Start With 010 || 011 || 012 || 015" << endl;
                f = false;
            }

            // Check if Student Phone Number is Numeric
            for (int i = 3; i < student.getPhoneNumber().length(); i++)
            {
                if (!isdigit(student.getPhoneNumber()[i]))
                {
                    cout << "Invalid Student Phone Number \n";
                    cout << "The Phone Number Must Be A Numerical." << endl;
                    f = false;
                    break;
                }
            }
        }

        // Check Student Email
        const std::regex pattern(R"((\w+)(\.{1}\w+)*@(\w+)(\.\w+)+)");
        if (std::regex_match(student.getEmail(), pattern) != 1)
        {
            cout << "Invalid Student Email \n";
            cout << "The Email Must Be Such That example@example.com \n";
            f = false;
        }

        // Check Student Age
        if (!(student.getAge() >= 18 && student.getAge() <= 30))
        {
            cout << "Invalid Student Age \n";
            cout << "The Student Age Must Be Between [18, 30] Inclusive \n";
            f = false;
        }

        // Check Student GPA
        if (!(student.getGPA() >= 0.0 && student.getGPA() <= 4.0))
        {
            cout << "Invalid Student GPA \n";
            cout << "The Student GPA Must Be between [0.0, 4.0] Inclusive \n";
            f = false;
        }

        return f;
    }

    Student displayStudenByID(int ID)
    {
        return studentRepo.displayStudenByID(ID);
    }

    Student updateStudent(Student student)
    {
        return studentRepo.updateStudent(student);
    }

    int searchAboutID(int ID)
    {
        // Search About ID using Binary Search
        int left = 0, right = data.indexStudent - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (data.student[mid].getID() == ID)
                return mid;
            else if (data.student[mid].getID() < ID)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    Student *deleteStudent(int ID)
    {
        // Check if There is No Student or Not
        if (data.indexStudent == 0)
            cout << "There Is No Student To Delete. Repository Is Empty! \n";
        else if (StudentServiceImp::searchAboutID(ID) != -1)
        {
            return studentRepo.deleteStudent(StudentServiceImp::searchAboutID(ID));
        }
        return nullptr;
    }
};

// Abstract "Interface" Class For Course
class CourseService
{
public:
    virtual int addCourse(Course course) = 0;
    virtual Course displayCourseByID(int ID) = 0;
    virtual Course updateCourse(Course course) = 0;
    virtual bool validateCourseData(Course course) = 0;
};
// Concrete "Implementation" Class for Course Service
class CourseServiceImp : public CourseService
{
private:
    CourseRepoImpl courseRepo;
    Data data;

public:
    // override
    // Add Course Validation
    int addCourse(Course course)
    {
        if (CourseServiceImp::validateCourseData(course))
            return courseRepo.addCourse(course);
        else
            return -1;
    }

    bool validateCourseData(Course course)
    {
        bool f = true;

        // Check Course Name
        if (course.getName().length() <= 1)
        {
            cout << "Invalid Course Name \n";
            cout << "The Course Name Must Be At Least 2 Characters \n";
            f = false;
        }

        // Check Course Hours
        if (!(course.getHour() >= 1 && course.getHour() <= 4))
        {
            cout << "Invalid Course Hours \n";
            cout << "The Course Hours Must Be Between [1, 4] Inclusive \n";
            f = false;
        }
        return f;
    }

    Course displayCourseByID(int ID)
    {
        return courseRepo.displayCourseByID(ID);
    }

    Course updateCourse(Course course)
    {
        return courseRepo.updateCourse(course);
    }

    int searchAboutID(int ID)
    {
        // Search About ID using Binary Search
        int left = 0, right = data.indexCourse - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (data.course[mid].getID() == ID)
                return mid;
            else if (data.course[mid].getID() < ID)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    Course *deleteCourse(int ID)
    {
        // Check if There is No Course or Not
        if (data.indexCourse == 0)
            cout << "There Is No Course to Delete. Repository Is Empty! \n";
        else if (CourseServiceImp::searchAboutID(ID) != -1)
            return courseRepo.deleteCourse(CourseServiceImp::searchAboutID(ID));
        return nullptr;
    }
};

// Abstract "Interface" Class For Teacher
class TeacherService
{
public:
    virtual int addTeacher(Teacher teacher) = 0;
    virtual Teacher displayTeacherByID(int ID) = 0;
    virtual bool validateTeacherData(Teacher teacher) = 0;
    virtual Teacher updateTeacher(Teacher teacher) = 0;
    virtual Teacher *deleteTeacher(int ID) = 0;
};
// Concrete "Implementation" Class for Teacher Service
class TeacherServiceImp : public TeacherService
{
private:
    TeacherRepoImpl teacherRepo;
    Data data;

public:
    // override
    // Add Teacher Validation
    int addTeacher(Teacher teacher)
    {
        if (TeacherServiceImp::validateTeacherData(teacher))
            return teacherRepo.addTeacher(teacher);
        else
            return -1;
    }

    bool validateTeacherData(Teacher teacher)
    {
        bool f = true;

        // Check Teacher Name
        if (teacher.getName().length() <= 2)
        {
            cout << "Invalid Teacher Name \n";
            cout << "The Teacher Name Must Be At Least 3 Characters \n";
            f = false;
        }
        else
        {
            for (int i = 0; i < teacher.getName().length(); i++)
            {
                // check if  teacher.getName()[i] is not char or space
                if (!(teacher.getName()[i] == ' ' || isalpha(teacher.getName()[i])))
                {
                    cout << "Invalid Teacher Name \n";
                    cout << "The Teacher Name Must Only Contain Letters And Spaces \n";
                    f = false;
                    break;
                }
            }
        }

        // Check Teacher Phone Number
        if (teacher.getPhoneNumber().length() != 11)
        {
            cout << "Invalid Teacher Phone Number \n";
            cout << "The Length Of The Teacher Phone Number Must Be 11 Digits \n";
            f = false;
        }
        else
        {
            // Check three digits of Teacher Phone Number
            if (teacher.getPhoneNumber().substr(0, 3) != "010" &&
                teacher.getPhoneNumber().substr(0, 3) != "011" &&
                teacher.getPhoneNumber().substr(0, 3) != "012" &&
                teacher.getPhoneNumber().substr(0, 3) != "015")
            {
                cout << "Invalid Teacher Phone Number \n";
                cout << "The Student Phone Number Must Be Start With 010 || 011 || 012 || 015" << endl;
                f = false;
            }

            // Check if Teacher Phone Number is Numeric
            for (int i = 3; i < teacher.getPhoneNumber().length(); i++)
            {
                if (!isdigit(teacher.getPhoneNumber()[i]))
                {
                    cout << "Invalid Teacher Phone Number \n";
                    cout << "The Phone Number Must Be A Numerical." << endl;
                    f = false;
                    break;
                }
            }
        }

        // Check Teacher Email
        const std::regex pattern(R"((\w+)(\.{1}\w+)*@(\w+)(\.\w+)+)");
        if (std::regex_match(teacher.getEmail(), pattern) != 1)
        {
            cout << "Invalid Teacher Email \n";
            cout << "The Email Must Be Such That example@example.com \n";
            f = false;
        }

        // Check Teacher Age
        if (!(teacher.getAge() >= 30 && teacher.getAge() <= 75))
        {
            cout << "Invalid Teacher Age \n";
            cout << "The Teacher Age Must Be Between [30, 75] Inclusive \n";
            f = false;
        }

        // Check Teacher Salary
        if (!(teacher.getSalary() >= 10000 && teacher.getSalary() <= 50000))
        {
            cout << "Invalid Teacher Salary \n";
            cout << "The Teacher Salary Must Be between [10000.0, 50000.0] Inclusive \n";
            f = false;
        }
        return f;
    }

    Teacher displayTeacherByID(int ID)
    {
        return teacherRepo.displayTeacherByID(ID);
    }

    Teacher updateTeacher(Teacher teacher)
    {
        return teacherRepo.updateTeacher(teacher);
    }

    int searchAboutID(int ID)
    {
        // Search About ID using Binary Search
        int left = 0, right = data.indexTeacher - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (data.teacher[mid].getID() == ID)
                return mid;
            else if (data.teacher[mid].getID() < ID)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    Teacher *deleteTeacher(int ID)
    {
        // Check if There is No Course or Not
        if (data.indexTeacher == 0)
            cout << "There Is No Teacher to Delete. Repository Is Empty! \n";
        else if (TeacherServiceImp::searchAboutID(ID) != -1)
            return teacherRepo.deleteTeacher(TeacherServiceImp::searchAboutID(ID));
        return nullptr;
    }
};

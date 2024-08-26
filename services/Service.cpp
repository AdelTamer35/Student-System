#include "../repo/Repository.cpp"
#include <regex>
// Abstract "Interface" Class For Student
class StudentService
{
public:
    virtual int addStudent(Student student) = 0;
};
// Concrete "Implementation" Class for Student Service
class StudentServiceImp : public StudentService
{
private:
    StudentRepoImpl studentRepo;

public:
    // override
    // Add Student Validation
    int addStudent(Student student)
    {
        bool f = true;

        // Check Student Name
        if (student.getName().length() <= 2)
        {
            cout << "Invalid Student Name \n";
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
                    f = false;
                    break;
                }
            }
        }

        // Check Student Phone Number
        if (student.getPhoneNumber().length() != 11)
        {
            cout << "Invalid Student Phone Number \n";
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
                f = false;
            }

            // Check if Student Phone Number is Numeric
            for (int i = 3; i < student.getPhoneNumber().length(); i++)
            {
                if (!isdigit(student.getPhoneNumber()[i]))
                {
                    cout << "Invalid Student Phone Number \n";
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
            f = false;
        }

        // Check Student Age
        if (!(student.getAge() >= 18 && student.getAge() <= 30))
        {
            cout << "Invalid Student Age \n";
            f = false;
        }

        // Check Student GPA
        if (!(student.getGPA() >= 0.0 && student.getGPA() <= 4.0))
        {
            cout << "Invalid Student GPA \n";
            f = false;
        }

        if (f)
            return studentRepo.addStudent(student);
        else
            return -1;
    }
};

// Abstract "Interface" Class For Course
class CourseService
{
public:
    virtual int addCourse(Course course) = 0;
};
// Concrete "Implementation" Class for Course Service
class CourseServiceImp : public CourseService
{
private:
    CourseRepoImpl courseRepo;

public:
    // override
    // Add Course Validation
    int addCourse(Course course)
    {
        bool f = true;

        // Check Course Name
        if (course.getName().length() <= 1)
        {
            cout << "Invalid Course Name \n";
            f = false;
        }

        // Check Course Hours
        if (!(course.getHour() >= 1 && course.getHour() <= 4))
        {
            cout << "Invalid Course Hours \n";
            f = false;
        }

        if (f)
            return courseRepo.addCourse(course);
        else
            return -1;
    }
};

// Abstract "Interface" Class For Teacher
class TeacherService
{
public:
    virtual int addTeacher(Teacher teacher) = 0;
};
// Concrete "Implementation" Class for Teacher Service
class TeacherServiceImp : public TeacherService
{
private:
    TeacherRepoImpl teacherRepo;

public:
    // override
    // Add Teacher Validation
    int addTeacher(Teacher teacher)
    {
        bool f = true;

        // Check Teacher Name
        if (teacher.getName().length() <= 2)
        {
            cout << "Invalid Teacher Name \n";
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
                    f = false;
                    break;
                }
            }
        }

        // Check Teacher Phone Number
        if (teacher.getPhoneNumber().length() != 11)
        {
            cout << "Invalid Teacher Phone Number \n";
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
                f = false;
            }

            // Check if Teacher Phone Number is Numeric
            for (int i = 3; i < teacher.getPhoneNumber().length(); i++)
            {
                if (!isdigit(teacher.getPhoneNumber()[i]))
                {
                    cout << "Invalid Teacher Phone Number \n";
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
            f = false;
        }

        // Check Teacher Age
        if (!(teacher.getAge() >= 30 && teacher.getAge() <= 75))
        {
            cout << "Invalid Teacher Age \n";
            f = false;
        }

        // Check Teacher Salary
        if (!(teacher.getSalary() >= 10000 && teacher.getSalary() <= 50000))
        {
            cout << "Invalid Teacher Salary \n";
            f = false;
        }

        if (f)
            return teacherRepo.addTeacher(teacher);
        else
            return -1;
    }
};

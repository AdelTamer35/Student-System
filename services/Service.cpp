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
    int addCourse(Course course)
    {
        return courseRepo.addCourse(course);
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
    int addTeacher(Teacher teacher)
    {
        return teacherRepo.addTeacher(teacher);
    }
};

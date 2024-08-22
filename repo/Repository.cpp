#include "../model/Model.cpp"
// Abstract "Interface" Class For Student
class StudentRepo
{
public:
    virtual int addStudent(Student student) = 0;
};
// Concrete "Implementation" Class for Student Repository
class StudentRepoImpl : public StudentRepo
{
private:
    Student student[25];
    int index = 0;

public:
    // override
    int addStudent(Student student)
    {
        if (index == 25)
        {
            cout << "Cannot add more students. Repository is full." << endl;
            return -1;
        }
        else
        {
            this->student[index] = student;
            index++;
            return 0;
        }
    }
};

// Abstract "Interface" Class For Course
class CourseRepo
{
public:
    virtual int addCourse(Course course) = 0;
};
// Concrete "Implementation" Class for Course Repository
class CourseRepoImpl : public CourseRepo
{
private:
    Course course[25];
    int index = 0;

public:
    // override
    int addCourse(Course course)
    {
        if (index == 25)
        {
            cout << "Cannot add more courses. Repository is full." << endl;
            return -1;
        }
        else
        {
            this->course[index] = course;
            index++;
            return 0;
        }
    }
};

// Abstract "Interface" Class For Teacher
class TeacherRepo
{
public:
    virtual int addTeacher(Teacher teacher) = 0;
};
// Concrete "Implementation" Class for Teacher Repository
class TeacherRepoImpl : public TeacherRepo
{
private:
    Teacher teacher[25];
    int index = 0;

public:
    // override
    int addTeacher(Teacher teacher)
    {
        if (index == 25)
        {
            cout << "Cannot add more teachers. Repository is full." << endl;
            return -1;
        }
        else
        {
            this->teacher[index] = teacher;
            index++;
            return 0;
        }
    }
};

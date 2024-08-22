#include "../repo/Repository.cpp"

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
        return studentRepo.addStudent(student);
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

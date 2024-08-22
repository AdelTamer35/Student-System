#include "../services/Service.cpp"
using namespace std;

class StudentController
{
private:
    StudentServiceImp studentService;

public:
    int addStudent(Student student)
    {
        return studentService.addStudent(student);
    }
};

class CoureController
{
private:
    CourseServiceImp courseService;

public:
    int addCourse(Course course)
    {
        return courseService.addCourse(course);
    }
};

class TeacherController
{
private:
    TeacherServiceImp teacherService;

public:
    int addTeacher(Teacher teacher)
    {
        return teacherService.addTeacher(teacher);
    }
};

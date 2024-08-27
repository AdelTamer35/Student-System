#include "../services/Service.cpp"
// Class Student Controller
class StudentController
{
private:
    StudentServiceImp studentService;

public:
    int addStudent(Student student)
    {
        return studentService.addStudent(student);
    }

    Student displayStudenByID(int ID)
    {
        return studentService.displayStudenByID(ID);
    }


};

// Class Course Controller
class CoureController
{
private:
    CourseServiceImp courseService;

public:
    int addCourse(Course course)
    {
        return courseService.addCourse(course);
    }

    Course displayCourseByID(int ID)
    {
        return courseService.displayCourseByID(ID);
    }
};

// Class Teacher Controller
class TeacherController
{
private:
    TeacherServiceImp teacherService;

public:
    int addTeacher(Teacher teacher)
    {
        return teacherService.addTeacher(teacher);
    }
    
    Teacher displayTeacherByID(int ID)
    {
        return teacherService.displayTeacherByID(ID);
    }
};

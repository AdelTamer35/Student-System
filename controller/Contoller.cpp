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

    bool validateStudentData(Student student)
    {
        return studentService.validateStudentData(student);
    }

    Student updateStudent(Student student)
    {
        return studentService.updateStudent(student);
    }

    Student *deleteStudent(int ID)
    {
        return studentService.deleteStudent(ID);
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

    bool validateCourseData(Course course)
    {
        return courseService.validateCourseData(course);
    }

    Course updateCourse(Course course)
    {
        return courseService.updateCourse(course);
    }

    Course *deleteCourse(int ID)
    {
        return courseService.deleteCourse(ID);
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

    bool validateTeacherData(Teacher teacher)
    {
        return teacherService.validateTeacherData(teacher);
    }

    Teacher updateTeacher(Teacher teacher)
    {
        return teacherService.updateTeacher(teacher);
    }

    Teacher *deleteTeacher(int ID)
    {
        return teacherService.deleteTeacher(ID);
    }
};

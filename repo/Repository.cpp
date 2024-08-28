#include "../model/Model.cpp"
// Static Data
class Data
{
public:
    static Student student[25];
    static int indexStudent, indexCourse, indexTeacher, IDStudent, IDCourse, IDTeacher;
    static Course course[25];
    static Teacher teacher[25];
};
// initilaization Student Data
Student Data::student[25];
int Data::indexStudent = 0;
int Data::IDStudent = 1;

// initilaization Course Data
Course Data::course[25];
int Data::indexCourse = 0;
int Data::IDCourse = 100;

// initilaization teacher Data
Teacher Data::teacher[25];
int Data::indexTeacher = 0;
int Data::IDTeacher = 10;

// Abstract "Interface" Class For Student
class StudentRepo
{
public:
    virtual int addStudent(Student student) = 0;
    virtual Student displayStudenByID(int ID) = 0;
    virtual Student updateStudent(Student student) = 0;
};
// Concrete "Implementation" Class for Student Repository
class StudentRepoImpl : public StudentRepo
{
private:
    Data data;

public:
    // override
    int addStudent(Student student)
    {
        if (data.indexStudent == 25)
            cout << "Cannot add more students. Repository is full." << endl;
        else
        {
            student.setID(data.IDStudent++);
            data.student[data.indexStudent++] = student;
            return student.getID();
        }
        return -1;
    }

    Student displayStudenByID(int ID)
    {
        Student noStudent;
        noStudent.setID(-1);
        if (data.indexStudent == 0)
            cout << "There is no student here. Repository is empty." << endl;
        else
        {
            // Search about student ID USing Binary Search
            int l = 0, r = data.indexStudent - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (data.student[mid].getID() == ID)
                {
                    // ID is Found
                    return data.student[mid];
                }
                else if (data.student[mid].getID() < ID)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        // there is no ID like this or Repository is empty
        return noStudent;
    }

    Student updateStudent(Student student)
    {
        // Search about student ID USing Binary Search and update data
        int l = 0, r = data.indexStudent - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (data.student[mid].getID() == student.getID())
            {
                // ID is Found
                return data.student[mid] = student;
            }
            else if (data.student[mid].getID() < student.getID())
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
};

// Abstract "Interface" Class For Course
class CourseRepo
{
public:
    virtual int addCourse(Course course) = 0;
    virtual Course displayCourseByID(int ID) = 0;
    virtual Course updateCourse(Course course) = 0;
};
// Concrete "Implementation" Class for Course Repository
class CourseRepoImpl : public CourseRepo
{
private:
    Data data;

public:
    // override
    int addCourse(Course course)
    {
        if (data.indexCourse == 25)
            cout << "Cannot add more courses. Repository is full." << endl;
        else
        {
            course.setID(data.IDCourse++);
            data.course[data.indexCourse++] = course;
            return course.getID();
        }
        return -1;
    }

    Course displayCourseByID(int ID)
    {
        Course noCourse;
        noCourse.setID(-1);
        if (data.indexCourse == 0)
            cout << "There is no course here. Repository is empty." << endl;
        else
        {
            // Search about course ID USing Binary Search
            int l = 0, r = data.indexCourse - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (data.course[mid].getID() == ID)
                {
                    // ID is Found
                    return data.course[mid];
                }
                else if (data.course[mid].getID() < ID)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        // there is no ID like this or Repository is empty
        return noCourse;
    }

    Course updateCourse(Course course)
    {
        // Search about course ID USing Binary Search and update data
        int l = 0, r = data.indexCourse - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (data.course[mid].getID() == course.getID())
            {
                // ID is Found
                return data.course[mid] = course;
            }
            else if (data.course[mid].getID() < course.getID())
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
};

// Abstract "Interface" Class For Teacher
class TeacherRepo
{
public:
    virtual int addTeacher(Teacher teacher) = 0;
    virtual Teacher displayTeacherByID(int ID) = 0;
    virtual Teacher updateTeacher(Teacher teacher) = 0;
};
// Concrete "Implementation" Class for Teacher Repository
class TeacherRepoImpl : public TeacherRepo
{
private:
    Data data;

public:
    // override
    int addTeacher(Teacher teacher)
    {
        if (data.indexTeacher == 25)
            cout << "Cannot add more teachers. Repository is full." << endl;
        else
        {
            teacher.setID(data.IDTeacher++);
            data.teacher[data.indexTeacher++] = teacher;
            return teacher.getID();
        }
        return -1;
    }

    Teacher displayTeacherByID(int ID)
    {
        Teacher noTeacher;
        noTeacher.setID(-1);
        if (data.indexTeacher == 0)
            cout << "There is no teacher here. Repository is empty." << endl;
        else
        {
            // Search about teacher ID USing Binary Search
            int l = 0, r = data.indexTeacher - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (data.teacher[mid].getID() == ID)
                {
                    // ID is Found
                    return data.teacher[mid];
                }
                else if (data.teacher[mid].getID() < ID)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        // there is no ID like this or Repository is empty
        return noTeacher;
    }

    Teacher updateTeacher(Teacher teacher)
    {
        // Search about teacher ID USing Binary Search and update data
        int l = 0, r = data.indexTeacher - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (data.teacher[mid].getID() == teacher.getID())
            {
                // ID is Found
                return data.teacher[mid] = teacher;
            }
            else if (data.teacher[mid].getID() < teacher.getID())
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
};

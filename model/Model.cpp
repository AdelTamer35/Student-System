#include <iostream>
using namespace std;
// Create a class for shared data between baseEntity and Course
class ShareData
{
private:
    int ID;
    string name;

public:
    // Getter for ID
    int getID() const
    {
        return ID;
    }

    // Setter for ID
    void setID(int id)
    {
        ID = id;
    }

    // Getter for name
    string getName() const
    {
        return name;
    }

    // Setter for name
    void setName(string n)
    {
        name = n;
    }
};

//  Create a class for shared data between Teacher and Student
class baseEntity : public ShareData
{
private:
    int age;
    string phoneNumber, email;

public:
    // Getter for age
    int getAge() const
    {
        return age;
    }

    // Setter for age
    void setAge(int a)
    {
        age = a;
    }

    // Getter for phoneNumber
    string getPhoneNumber() const
    {
        return phoneNumber;
    }

    // Setter for phoneNumber
    void setPhoneNumber(string p)
    {
        phoneNumber = p;
    }

    // Getter for email
    string getEmail() const
    {
        return email;
    }

    // Setter for email
    void setEmail(string e)
    {
        email = e;
    }
};

// Create a Teacher Model
class Teacher : public baseEntity
{
private:
    double salary;
    int studentID[5]; // one teacher has many students

public:
    // Getter for salary
    double getSalary() const
    {
        return salary;
    }

    // Setter for salary
    void setSalary(double s)
    {
        salary = s;
    }

    // Setter for studentIDS
    void setStudentIDs(int studentIDs[])
    {
        for (int i = 0; i < 5; i++)
        {
            this->studentID[i] = studentIDs[i];
        }
    }

    // Getter fot studentIDS
    int *getStudentIDs()
    {
        return studentID;
    }
};

// Create a Course Model
class Course : public ShareData
{
private:
    double hour;
    int studentID[5]; // // one courses has many Student

public:
    // Setter for hour
    void setHour(double h)
    {
        hour = h;
    }

    // Getter for hour
    double getHour() const
    {
        return hour;
    }

    // setter for studentID
    void setStudentIDs(int studentIDs[])
    {
        for (int i = 0; i < 5; i++)
        {
            this->studentID[i] = studentIDs[i];
        }
    }

    // Getter for studentID
    int *getStudentIDs()
    {
        return studentID;
    }
};

// Create a Student Model
class Student : public baseEntity
{
private:
    double GPA;
    Teacher teachers[5]; // one student has many teachers
    Course courses[5];   // one student has many courses
public:
    // Getter for GPA
    double getGPA() const
    {
        return GPA;
    }

    // Setter for GPA
    void setGPA(double &GPA)
    {
        this->GPA = GPA;
    }

    // Setter for teachers
    void setTeachers(Teacher teachers[])
    {
        for (int i = 0; i < 5; i++)
        {
            this->teachers[i] = teachers[i];
        }
    }

    // Getter for teachers
    Teacher *getTeachers()
    {
        return teachers;
    }

    // Setter for courses
    void setCourses(Course courses[])
    {
        for (int i = 0; i < 5; i++)
        {
            this->courses[i] = courses[i];
        }
    }

    // Getter for courses
    Course *getCourses()
    {
        return courses;
    }
};

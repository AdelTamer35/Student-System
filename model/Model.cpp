#include <iostream>
using namespace std;
class baseEntity
{
private:
    int ID, age;
    string name, phoneNumber, email;

public:
    baseEntity();

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

    ~baseEntity() {}
};
// Create a Teacher Model
class Teacher : public baseEntity
{
private:
    double salary;
    int studentID[5]; // one teacher has many students

public:
    Teacher();

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

    ~Teacher();
};
// Create a Student Model
class Student : public baseEntity
{
private:
    double GPA;
    Teacher teachers[5]; // one student has many teachers

public:
    Student();

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

    ~Student();
};

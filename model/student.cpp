#include <iostream>
using namespace std;
class Student
{
private:
    int ID, age;
    string name, phoneNumber, email;
    double GPA;

public:
    Student();
    Student(int newID, int newAge, const string &newName, const string &newPhoneNumber, const string &newEmail)
        : ID(newID), age(newAge), name(newName), phoneNumber(newPhoneNumber), email(newEmail) {}

    // Getter for ID
    int getID() const
    {
        return ID;
    }

    // Setter for ID
    void setID(int newID)
    {
        ID = newID;
    }

    // Getter for age
    int getAge() const
    {
        return age;
    }

    // Setter for age
    void setAge(int newAge)
    {
        age = newAge;
    }

    // Getter for name
    string getName() const
    {
        return name;
    }

    // Setter for name
    void setName(const string &newName)
    {
        name = newName;
    }

    // Getter for phoneNumber
    string getPhoneNumber() const
    {
        return phoneNumber;
    }

    // Setter for phoneNumber
    void setPhoneNumber(const string &newPhoneNumber)
    {
        phoneNumber = newPhoneNumber;
    }

    // Getter for email
    string getEmail() const
    {
        return email;
    }

    // Setter for email
    void setEmail(const string &newEmail)
    {
        email = newEmail;
    }

    // Getter for GPA
    double getGPA()
    {
        return GPA;
    }

    // Setter for GPA
    void setEmail(double &GPA)
    {
        this->GPA = GPA;
    }

    ~Student();
};

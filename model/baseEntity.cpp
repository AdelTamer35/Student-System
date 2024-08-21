#include <iostream>
using namespace std;
class baseEntity
{
private:
    int ID, age;
    string name, phoneNumber, email;

public:
    baseEntity();
    baseEntity(int id, int a, string n, string p, string e)
        : ID(id), age(a), name(n), phoneNumber(p), email(e) {}

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
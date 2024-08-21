#include "baseEntity.cpp"
class Teacher : public baseEntity
{
private:
    double salary;

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

    ~Teacher();
};
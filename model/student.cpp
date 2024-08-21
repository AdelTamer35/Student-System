#include "baseEntity.cpp"
class Student : public baseEntity
{
private:
    double GPA;

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

    ~Student();
};

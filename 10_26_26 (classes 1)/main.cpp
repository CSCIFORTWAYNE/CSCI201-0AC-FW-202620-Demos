#include <iostream>
#include <string>

class StudentType
{
public:
    std::string printStudentInfo();

    void setGPA(double g);

private:
    std::string fname;
    std::string lname;
    std::string email;
    double gpa;
};

int main()
{
    StudentType student;
    student.fname = "Harry";
    student.lname = "Potter";
    student.email = "hpotter@ivytech.edu";
    student.gpa = 3.0;
    std::cout << student.fname << " " << student.lname << std::endl;

    return 0;
}

void StudentType::setGPA(double g)
{
    if (g < 0 || g > 4)
    {
        g = 0;
    }
    gpa = g;
}
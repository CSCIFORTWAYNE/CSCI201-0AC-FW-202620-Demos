#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class StudentType
{
public:
    StudentType(std::string fname, std::string lname, std::string email, double gpa);
    std::string getFname() const;
    std::string getLname() const;
    std::string getEmail() const;
    double getGPA() const;

    void setFname(std::string newFname);
    void setLname(std::string newLname);
    void setEmail(std::string newEmail);
    void setGPA(double newGPA);

    std::string printStudentInfo();

private:
    std::string fname;
    std::string lname;
    std::string email;
    double gpa;
};

int main()
{
    StudentType student("Harry", "Potter", "hpotter@ivytech.edu", 3.0);
    std::cout << "Hello new student!" << std::endl;

    std::cout << student.printStudentInfo() << std::endl;

    student.setLname("");
    std::cout << student.printStudentInfo() << std::endl;

    return 0;
}

StudentType::StudentType(std::string f, std::string l, std::string e, double g)
{
    setGPA(g);
    setFname(f);
    setLname(l);
    setEmail(e);
}

std::string StudentType::getFname() const
{
    return fname;
}

std::string StudentType::getLname() const
{
    return lname;
}

std::string StudentType::getEmail() const
{
    return email;
}

double StudentType::getGPA() const
{
    return gpa;
}

void StudentType::setGPA(double g)
{
    if (g < 0 || g > 4)
    {
        g = 0;
    }
    gpa = g;
}

void StudentType::setFname(std::string newFname)
{
    if (newFname.empty() && fname.empty())
    {
        newFname = "Charlie";
    }
    else if (!fname.empty())
    {
        newFname = fname;
    }
    fname = newFname;
}

void StudentType::setLname(std::string newLname)
{
    if (newLname.empty() && lname.empty())
    {
        newLname = "Brown";
    }
    else if (!lname.empty())
    {
        newLname = lname;
    }
    lname = newLname;
}

void StudentType::setEmail(std::string newEmail)
{
    email = newEmail;
}

std::string StudentType::printStudentInfo()
{
    // StudentType othersTudent("","","", 4.0);
    // othersTudent.fname;
    /*  std::string outStr;
     outStr += fname + " " + lname + " -- GPA:" + std::to_string(gpa);
     return outStr;*/
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << fname << " " << lname << std::endl;
    out << "Email Address: " << email << std::endl;
    out << "GPA: " << gpa << std::endl;
    return out.str();
}

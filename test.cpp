#include <iostream>
using std::string;

class IEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : IEmployee
{
private:
    string Company;
    int Age;

protected:
    string Name;

public:
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void IntroduceYourself()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    void AskForPromotion()
    {
        if (Age > 30)
            std::cout << Name << " got promoted" << std::endl;
        else
            std::cout << Name << ", sorry NO promotion for you" << std::endl;
    }
    virtual void Work()
    {
        std::cout << Name << "is checking email, task backlog, performing those tasks.." << std::endl;
    }

    void setName(string name)
    {
        Name = name;
    }

    string getName()
    {
        return Name;
    }

    void setCompany(string company)
    {
        Company = company;
    }

    string getCompany()
    {
        return Company;
    }

    void setAge(int age)
    {
        if (age >= 18)
            Age = age;
    }

    int getAge()
    {
        return Age;
    }
};

class Developer : public Employee
{
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        : Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void FixBug()
    {
        std::cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
    }
    void Work()
    {
        std::cout << Name << "is writing some code using " << FavProgrammingLanguage << " code" << std::endl;
    }
};

class Teacher : public Employee
{
public:
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        Subject = subject;
    }

    string Subject;
    void prepareLesson()
    {
        std::cout << Name << " Is preparing " << Subject << " lesson " << std::endl;
    }
    void Work()
    {
        std::cout << Name << " is teaching " << Subject << std::endl;
    }
};
int main()
{
    Employee firstEmployee = Employee("Alex", "PPRO", 33);
    Employee secondEmployee = Employee("Vitor", "PPRO Latam", 28);
    Developer developerEmployee = Developer("Alex", "PPRO", 23, "JavaScript");
    // developerEmployee.FixBug();
    // developerEmployee.AskForPromotion();
    Teacher teacher = Teacher("Adriana", "Luiz Gonzaga", 54, "Portuguese");
    // teacher.prepareLesson();
    // // teacher.AskForPromotion();
    // developerEmployee.Work();
    // teacher.Work();
    Employee *e1 = &developerEmployee;
    Employee *e2 = &teacher;

    e1->Work();
    e2->Work();
}
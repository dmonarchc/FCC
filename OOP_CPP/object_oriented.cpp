#include <iostream>
using std::string;

class AbstractEmployee {
  virtual void AskForPromotion()=0;
};
class Employee:AbstractEmployee {
private:
  string Company;
  int Age;
protected:
  string Name;
public:
  void setName(string name) { //setter
    Name = name;
  }
  string getName() { //getter
    return Name;
  }
  void setCompany(string company) {
    Company = company;
  }
  string getCompany() {
    return Company;
  }
  void setAge(int age) {
    if(age>=18)
    Age = age;
  }
  int getAge() {
    return Age;
  }
  void IntroduceYourself() {
    std::cout << "Name - " << Name << std::endl;
    std::cout << "Company -" << Company << std::endl;
    std::cout << "Age - " << Age << std::endl;
  }
  Employee(string name, string company, int age) {
    Name = name;
    Company = company;
    Age = age;
  }
  void AskForPromotion() {
    if(Age>30)
      std::cout << Name << " got promoted! " << std::endl;
    else
      std::cout << Name << ", sorry NO promotion for you!" << std::endl;
  }
  virtual void Work() {
    std::cout << Name << " is checking email, task backlog, performing task..." << std::endl;
  }
};

class Developer:public Employee {
public:
  string FavProgrammingLanguage;
  Developer(string name, string company, int age, string favProgrammingLanguage)
    :Employee(name, company, age)
  {
    FavProgrammingLanguage = favProgrammingLanguage;
  }
  void FixBug() {
    std::cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
  }
  void Work() {
    std::cout << Name << " is writing " << FavProgrammingLanguage << " code " << std::endl;
  }
};

class Teacher:public Employee{
public:
  string Subject;
  void PrepareLesson() {
    std::cout << Name << " is preparing " << Subject << " lesson " << std::endl;
  }
  Teacher(string name, string company, int age, string subject)
    :Employee(name, company, age)
  {
    Subject = subject;
  }
  void Work() {
    std::cout << Name << " is teaching " << Subject << std::endl;
  }
};

int main()
{
  Employee employee1("Daniel", "dmonach", 25);
  Employee employee2("John", "Amazon", 35);

  //Inheritance
  std::cout << "Inheritance" << std::endl;
  Developer d = Developer("Sardina", "Lore", 23, "HTML");
  d.FixBug();
  d.AskForPromotion();
  Teacher t = Teacher("Jack", "Cool School", 35, "History");
  t.PrepareLesson();
  t.AskForPromotion();
  d.Work();
  t.Work();
  std::cout << "\n" << std::endl;

  // Polymorphism
  std::cout << "Polymorphism" << std::endl;
  Employee* e1 = &d;
  Employee* e2 = &t;

  e1->Work();
  e2->Work();
}

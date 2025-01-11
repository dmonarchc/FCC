#include <iostream>
using std::string;

class Employee {
public:
  string Name;
  string Company;
  int Age;

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
};
int main()
{
  Employee employee1("Daniel", "dmonach", 34);
  employee1.IntroduceYourself();

  Employee employee2("John", "Amazon", 35);
  employee2.IntroduceYourself();
}

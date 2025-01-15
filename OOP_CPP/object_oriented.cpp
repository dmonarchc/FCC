#include <iostream>
using std::string;

class AbstractEmployee {
  virtual void AskForPromotion()=0;
};
class Employee:AbstractEmployee {
private:
  string Name;
  string Company;
  int Age;
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
};
int main()
{
  Employee employee1("Daniel", "dmonach", 25);
  Employee employee2("John", "Amazon", 35);

  employee1.AskForPromotion();
  employee2.AskForPromotion();
}

#include <iostream>

/*
1. Access Modifier = 1.Public 2. Private 3. Protected. (by default set by compiler is Private)

2. Encapsulation =  using setter and getter

3. Abstraction = It mean only show which is required and hide important stuffs which is not necessary for user to show them.

4. Polymorphism = Poly-> Many and Morphism-> Forms
   1.Compile time polymorphism
        a.Function overloading
        b.Operator overloading

   2.Runtime polymorphism
      a.Function overriding -> Means same function in parent class and child class it decide in runtime which one is executed.
        Also important thing we use (virtual) keyword to achieve the function overriding
        virtual Function_Name
        We create pointer object for overriding
        Class_Name *employee = &Child_Class_Name
        employee->Funtion_Name

5. Inheritance = Parent class and its derived class(Child class)

   It has many type like single,multiple,multi-level,hierarchical,hybrid inheritance 
*/

using namespace std;

  class abstractEmployee{
    virtual void askForPromotion() = 0;
  };
 

  class Employee:abstractEmployee{

    private:
    string Company;
    int Age;

    protected:
    string Name;

    public:

     void setName(string name){
      if(name !="Ankit Shrestha" and name != "ankit shrestha"){
          Name = name;
      } 
      else{
        cout<<"Ankit Shrestha or ankit shrestha name should not be accepted!!!"<<endl;
      }
    }

    string getName(){
      return Name;
    }

    void setCompany(string comapny){
      Company = comapny;
    }

    string getCompany(){
      return Company;
    }

    void setAge(int age){
      if(age>=18)
        Age = age;
      else{
        cout<<"Employee should not be less than 18!!!"<<endl;
      }
    }

    int getAge(){
      return Age;
    }

    void introduceYourself(){
     cout<<"Name: "<<Name<<endl;
     cout<<"Age: "<<Age<<endl;
     cout<<"Company: "<<Company<<endl<<endl;
    }

    Employee(string n, string c, int a){
      Name = n;
      Company = c;
      Age = a;
    }

  //  Employee(){
  //    Name = "Invalid";
  //    Age = 0;
  //  }

    
  void askForPromotion(){
    if(Age>=30){
      cout<<Name<<" got Promoted...."<<endl;
    }
    else{
      cout<<Name<<" Oops, No Promotion for you..."<<endl;
    }
  }

 virtual void Work(){
    cout<<Name<<" is checking mails, task backlog and performing tasks......."<<endl;
  }

  };

  class Developer: public Employee{
     public:
     string favProgrammingLanguage;
     Developer(string n, string c, int a, string favLanguage)
      : Employee(n,c,a)
      {
        favProgrammingLanguage = favLanguage;
      }

      void fixBug(){
        cout<<Name<<" is fixed bug using "<<favProgrammingLanguage<<endl;
      }

     void Work(){
    cout<<Name<<" is writing "<<favProgrammingLanguage<<endl;
  }

  };

  class Teacher: public Employee{
    public:

    string Subject;

    void lesson(){
      cout<<Name<<" is preparing "<<Subject<<" lesson"<<endl;
    }

    Teacher(string n, string c, int a, string subject)
      :Employee(n,c,a)

    {
      Subject = subject;
    }

     void Work(){
    cout<<Name<<" is teaching "<<Subject<<endl;
  }
  };


int main()
{
  // Employee Ankit = Employee("Ankit Shrestha","Google",20);
  // Employee Shrestha = Employee("Shrestha","Apple",35);
  Developer john = Developer("Ankit","Google",25,"C++");
  Teacher t = Teacher("Jack","Cool School",35,"English");
  
  Employee e = Employee("Jo","Youtube",40);
  e.Work();
  john.Work();








  



  


  return 0;
}
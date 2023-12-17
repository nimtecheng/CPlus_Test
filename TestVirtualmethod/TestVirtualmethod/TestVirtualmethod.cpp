// TestVirtualmethod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class base {
public:
  virtual  void GetName() {
        std::cout << "My Name is Base CLass\n";
    }
  void GetName(int i) {
  
      std::cout << "My Name is Base Class, and this is a overload version\n";

  }

    void GetName2() {
        std::cout << "My Name is 2 Base CLass\n";
    }
    void GetName3() {
        std::cout << "My Name is 3 Base CLass\n";
    }
    virtual void Test() {
        std::cout << "My Name is Base Virtual test\n";
    }
};


class derived:public base {
public:
    using base::GetName;
    virtual void GetName() {
        std::cout << "My name is Derived Class\n";
    }
 void GetName2() {
     std::cout << "My Name is 2 Derived CLass\n";
 }
 void GetName4() {
     std::cout << "My Name is 4 Derived CLass\n";
 }
 void Test(int a) {
     std::cout << "My Name is Derived test with parameter\n";
 }

};
class test {

public:
    void GetName() { std::cout << "This is a Test Class Without Virtual Function\n"; }
};
int main()
{
    std::cout << "--------------Test Point--------------\n";
    //base point can be convert to derived point
    std::cout << "--------------base point can be convert to derived point--------------\n";
    //base point can be convert to derived point
    auto a = new base();
    derived* b = (derived *)a;
    b->GetName2();
    //derived class can convert to base class
    std::cout << "--------------derived class can convert to base class--------------\n";
    auto t = (base*)b;
    t->GetName2();
   // a->GetName2();
//virtual fuction take the upper class value whatever base or derived class
    std::cout << "--------------virtual fuction take the upper class value whatever base or derived class--------------\n";
    base* s = new derived();
    t = new derived();
    t->GetName();
    s->GetName();
    std::cout << "--------------Test Entity--------------\n";
    derived c;

    c.base::GetName2();
    c.GetName2();
    c.base::GetName();
    base d;
    d = c;
    test e;
    d.GetName2();
    std::cout << "--------------Test Same Name differnet parameter,So hide function--------------\n";
    c.Test(1);
    c.base::Test();
    std::cout << "--------------Test Size--------------\n";
    std::cout << sizeof(c) << "\n";
    std::cout << sizeof(d) << "\n";
    std::cout << sizeof(e) << "\n";
    std::cout << "--------------Test Base class with overload method--------------\n";
    std::cout << "c.base::GetName(1)\n";
    c.base::GetName(1);
    std::cout << "--------------Test Base class with overload method-after USING in derived class--------------\n";
    std::cout << "c.GetName(1)\n";
    c.GetName(1);
    std::cout << "c.GetName();\n"; ;
    c.GetName();

    std::cin.get();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

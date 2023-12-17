// inializerList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define test
class P
{
public:
     P(int a, int b)
        {
         std::cout << "This is Normal Constructor\n";
         std::cout << "a=" << a << "\tb=" << b << std::endl;
         std::cout << "------------------------------\n";
    }
#ifdef test
     P(std::initializer_list<int> initlist)
     {
         std::cout << "This is Initialize List Constructor\n";
         for (auto i: initlist)
         {
             std::cout << i << ' ';
         }
         std::cout << std::endl;
         std::cout << "------------------------------\n";
     }
#endif
     explicit P(int, int, int)
     {

         std::cout << "Explicit 3 arguments\n";
     }
};
int main()
{
  
    P p(1, 2);
    P q{ 3,4 };
    P r{ 5,6,7,8 };
    P s = { 9,10 };
    P t = { 11,12,13 };
    P u(14, 15, 16);
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

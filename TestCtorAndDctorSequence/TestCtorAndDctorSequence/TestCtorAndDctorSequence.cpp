// TestCtorAndDctorSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Base
{
public:
	Base() {
		std::cout << "Base Class Construted!!\n";
	};
	~Base() {

		std::cout << "Base Class Deconstructed!!\n";
	};

private:

};

class A
{
public:
	A() { std::cout << "A is Constructed!!\n"; };
	~A() { std::cout << "A is Deconstructed!!\n"; };


private:

};
class B
{
public:
	B() { std::cout << "B is Constructed!!\n"; };
	~B() { std::cout << "B is Deconstructed!!\n"; };

private:

};


class Derived :public Base
{
public:
	Derived() { std::cout << "Derived is Constructed!!\n"; };
	~Derived() { std::cout << "Derived is DeConstructed!!\n"; };
	A a;
	B b;

private:

};

int main()
{

	{
		Derived test;
	}
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

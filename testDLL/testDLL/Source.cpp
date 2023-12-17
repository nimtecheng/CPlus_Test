#include "dll.h"
#include<thread>
#include<iostream>


void test()
{
	testfunc();
}
int a() { return 0; }
int main()
{
	std::cout << "begin...." << std::endl;
	test();
	int b = a();
	std::cout << "end...." << std::endl;

	std::cin.get();
}
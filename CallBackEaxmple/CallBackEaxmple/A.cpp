#pragma once
#include "A.h"
INTEFACE a = nullptr;
void MakeFriends()
{
	char* Name=new char();
	std::cout << "Input Name you want to Make Friends With:\n";
	std::cin >> Name;
	a(Name);
}
void GetInteface(INTEFACE b)
{
	std::cout << __FUNCTION__<<" in "<<__FILE__ <<std::endl;
	if (b)
		a = b;
}
void SayHi(const char* name)
{
	std::cout << "Hi," << name << "!I want to make friends with you!\n";
}
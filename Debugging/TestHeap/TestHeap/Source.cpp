#include<iostream>

int main()
{

	char* p = (char*)malloc(1024);
	//char* p = new char[1024];
	p[1024] = 'a';

	std::cout << p[1024] << std::endl;

	std::cin.get();
}
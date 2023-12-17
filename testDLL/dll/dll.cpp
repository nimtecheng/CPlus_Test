#include "dll.h"
#include<iostream>
#include<thread>

#include<Windows.h>

void test()
{

	while (1)
	{
		std::cout << ".........test.............." << std::endl;
		Sleep(500);
	}

}
void  testfunc()
{
	std::thread testThread(test);
	testThread.detach();

};

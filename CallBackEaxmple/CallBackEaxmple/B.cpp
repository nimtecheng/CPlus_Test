#pragma once
#include"B.h"
CALLBACK b = nullptr;
const char* Name[5] = { "Stephen","Draymond","Looney","Thompson","Wiggins" };
void GetCallback(CALLBACK a)
{
	std::cout << __FUNCTION__ << " in " << __FILE__ << std::endl;
	if (a)
		b = a;
}
void FindName(const char* name)
{
	bool nameFound = false;
	for (size_t i = 0; i < 5; i++)
	{
		if (!strcmp(name, Name[i]))
		{
			b(name);
			nameFound = true;
			break;
		}
	}
	if(!nameFound)
		std::cout << "Name Not Found!!\n";


}

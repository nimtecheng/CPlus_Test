#include<iostream>
#include<vector>
#include<thread>

void getVecData(std::vector<int>* data,int* normData)
{
	std::vector<int> d;
	int a = 9;
	*normData = a;
	d.push_back(1);
	d.push_back(2);
	*data = d;
}
void testThread() { while (1); }
int main()
{
	std::vector<int> data;
	int a = 0;
	getVecData(&data,&a);
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << std::endl;
	}

	std::cout << a << std::endl;

	//std::cin.get();
	std::thread t(testThread);
	t.detach();
	return 0;
}


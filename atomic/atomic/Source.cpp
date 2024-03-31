#include<iostream>
#include<thread>
#include<atomic>
int main()
{
#pragma region traditional



	int sum = 0;
	auto f = [&sum]() {
		for (int i = 0; i < 10000; i++)
			sum += 1;
	};

	std::thread t1(f);
	std::thread t2(f);

	t1.join();
	t2.join();
	std::cout << "the sum of 2 threads is: " << sum << std::endl;
#pragma endregion
#pragma region atomic

	std::atomic<int> sum1 = 0;
	auto f1 = [&sum1]() {
		for (int i = 0; i < 10000; i++)
			sum1+=1;
	};

	std::thread t3(f1);
	std::thread t4(f1);

	t3.join();
	t4.join();
	std::cout << "the sum of 2 threads with atomic is: " << sum1 << std::endl;
#pragma endregion


	std::cin.get();
	return 0;




}
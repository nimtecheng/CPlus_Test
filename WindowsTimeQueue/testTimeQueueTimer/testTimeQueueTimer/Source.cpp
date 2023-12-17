#include<windows.h>
#include<iostream>
#include<thread>
HANDLE h1;
HANDLE h2;

void CALLBACK test(PVOID l, BOOLEAN t)
{
	std::cout << "This a test function excuted by Thread:" << std::this_thread::get_id()<< std::endl;
	//std::cout << "Here we try to delete timer in Thread:" << std::this_thread::get_id() << std::endl;
	if (0 == DeleteTimerQueueTimer(NULL, h1, NULL))
	{
		std::cout << "Timer  Deleted Failed in Thread:" << std::this_thread::get_id() << std::endl;
	}
	std::cout << "Timer  Deleted Successfully in Thread:" << std::this_thread::get_id() << std::endl;

}
void CALLBACK test1(PVOID l, BOOLEAN t)
{
	std::cout << "This a test1 function excuted by Thread:" << std::this_thread::get_id() << std::endl;
}

int main()
{
	
	std::cout << "******This is a Test for TimeQueueTimer in Windows API******" << std::endl;
	std::cout << "Main thread is executed by thread: " << std::this_thread::get_id() << std::endl;
	//test(PVOID(1), TRUE);
	try
	{
		CreateTimerQueueTimer(&h1, NULL, WAITORTIMERCALLBACK(test), NULL, 0, 1000, WT_EXECUTEINTIMERTHREAD);
		//Sleep(1000);

		CreateTimerQueueTimer(&h2, NULL, WAITORTIMERCALLBACK(test1), NULL, 0, 1000, WT_EXECUTEINTIMERTHREAD);


		//CreateTimerQueueTimer(&h1, NULL, [](PVOID lpParameter, BOOLEAN TimerOrWaitFired) {
		//	test(lpParameter, TimerOrWaitFired); // Call your original test function from within the lambda
		//	}, NULL, 0, 1000, WT_EXECUTEINTIMERTHREAD);

	}
	catch (const std::exception& e)
	{
		std::cout << "something error with the timer: " << e.what() << std::endl;
	}


	if (std::cin.get())
	{
		if (0 == DeleteTimerQueueTimer(NULL, h1, INVALID_HANDLE_VALUE))
		{
			std::cout << "Timer  Deleted Failed in Thread:" << std::this_thread::get_id() << std::endl;
		}
		std::cout << "Timer  Deleted Successfully in Thread:" << std::this_thread::get_id() << std::endl;

	};
	Sleep(1000);

	return 0;
}
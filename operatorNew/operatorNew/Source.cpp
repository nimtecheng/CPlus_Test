#include<iostream>

class A
{
public:
	A() { std::cout << "A is Constructed!\n"; };
	~A() { std::cout << "A is Deconstructed!\n";};

void* operator new(size_t size)
	{
		std::cout << "allocat memory for A is take over!Size is:" <<size<<'\n';
		//return ::operator new(size);
		return malloc(size);
	}
void operator delete(void* p)
{
	std::cout << "recycle memory for A is take over!\n";
	//::operator delete(p);
	free(p);

}
private:
	int n;


};

int main()
{
	
	A* a=new A();
	delete a;
	





	std::cin.get();

}
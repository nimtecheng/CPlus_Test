#include<iostream>

class MyString {
public:
	MyString() = default;
	MyString(const char* data)
	{		
		printf("%s", "MyString Constructed!!\n");
		size = strlen(data);
		m_data = new char[size];
		memcpy(m_data, data, size);	
	}
	~MyString()
	{
		if (m_data)
		{
			printf("%s", "MyString Destroyed!!\n");
			delete m_data;
		}	
	}
	//copy constructor
	MyString(const MyString& other) noexcept
	{
		printf("%s", "MyString Copyed!!\n");
		size = other.size;
		m_data = new char[size];
		memcpy(m_data, other.m_data, size);
	}
	//move constructor

	MyString(MyString&& other) noexcept
	{
		printf("%s", "MyString Moved!!\n");
		size = other.size;
		m_data = other.m_data;

		//clear origin data
		//other.size = 0;
		//other.m_data = nullptr;
	}

	//void OutPut() const
	//{
	//	for (int i = 0; i < size; i++)
	//	{
	//		printf("%c", m_data[i]);
	//	}

	//	printf("%c",'\n');
	//}

private:
	char* m_data;
	int size;
};


//void OutPutString(MyString string)
//{
//	string.OutPut();
//}

class Entity
{
public:
	//constructor
	Entity(const MyString& string):m_string(string) {}

	Entity(MyString&& string) :m_string(std::move(string)) {}

private:
	MyString m_string;
};

int main()
{	
	//OutPutString("Hello");
	Entity entity("Hello");
	return 0;
}
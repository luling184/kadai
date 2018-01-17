# include <iostream>
# include <vector>
# include <conio.h>
# include <functional>
# include <olebind.h>
# define Exit(Error_Num) _getch(); return Error_Num;

using namespace std;

class Dog
{
public:
	Dog() = default;
	Dog(int arg)
	{
		m_num = arg;
	}

	void bark(int value) const
	{
		cout << "‚í‚ñ‚í‚ñ : " << m_num << endl;
	}

private:
	int m_num;
};

class Cat
{
public:
	Cat() = default;
	Cat(int arg)
	{
		m_num = arg;
	}
	void run(int value) const
	{
		cout << m_num << "Žü‘–‚é‚É‚á[" << endl;;
	}

private:
	int m_num;
};

class Delegate
	: public DelegateBase
{
public:
	Delegate() {}
	virtual ~Delegate() { }

	virtual void operator() (int value)
	{
		for (const auto& it : m_eventList)
		{
			it(value);
		}
	}

	void set(std::function<void(int)> func)
	{
		m_eventList.push_back(func);
	}

protected:
	std::function<void(int)> m_func;
	std::vector<std::function<void(int)>> m_eventList;
};


int main()
{
	Delegate onOpenDoorHandler;
	Dog dog(10);
	Cat cat(20);

	onOpenDoorHandler.set(std::bind(&Dog::bark, &dog, std::placeholders::_1));
	onOpenDoorHandler.set(std::bind(&Cat::run, &cat, std::placeholders::_1));
	
	int value = 0;
	onOpenDoorHandler(value);

	Exit(0);
}
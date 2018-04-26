#include <stdio.h>

template <class Derived>
class Base
{
public:
	Base() {};
	void OpenMenu()
	{
		return static_cast<Derived*>(this)->OpenMenu();
	}

};

template<class Derived>
class MyClass : public Base<Derived>
{
public:
	OpenMenu() { printf("We did it statically!"); };
}
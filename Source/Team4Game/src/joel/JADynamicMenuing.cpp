#include <stdio.h>

class Menu
{
public:
	virtual void vOpenMenu();//displays the current menu
}

class Derived : public Menu
{
public:
	void vOpenMenu();
}

void vOpenMenu({ printf("A dynamic Message") });

main()
{
	Base * pBase = new Derived();
	pBase->vOpenMenu();
}
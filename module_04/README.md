# Module_03

* [Sub-typing_Polymorphism](#Sub-typing_Polymorphism)
* [exercises notes](#notes)

## Sub-typing_Polymorphism


```cpp

class Character
{
	public:
		void sayHello(std::string const &target);
};

class Warrior : public Character
{
	public:
		void sayHello(std::string const &target);//function overwriter
};

class Cat
{
	//...
}

int main()
{
	Warrior *a = new Warrior(); //OK
	a->sayHello("you"); //will display the warrior's msg
	
	Character *b = new Warrior(); //OK all warrior is a character
	b->sayHello("you"); //will display the character's msg, cause is a pointer to a character
	
	Warrior *c = new Character(); //WRONG! a character isn't necessarily a warrior
	Warrior *d = new Cat(); //WRONG! a cat has nothing to do with Warrior class
}

```

`virtual` in front of a member function tell the compiler the link will be dinamic and not static

static uses the type of the variable
dinamic can change, I can use my character pointer to point to diferents characters along the way, even in a dinamic way with the users input. Even if is a character during the compilation, the resolution of the function call will be dinamic during the execution

```cpp

class Character
{
	public:
		virtual void sayHello(std::string const &target);
};

class Warrior : public Character
{
	public:
		virtual void sayHello(std::string const &target);
};

int main()
{
	Warrior *a = new Warrior(); //OK
	a->sayHello("you"); //will display the warrior's msg
	
	Character *b = new Warrior(); //OK all warrior is a character
	b->sayHello("you"); //will display the warrior's msg

}
```

`virtual member function` == `method` == member function wich resolution will be dinamic (done during the execution)

## notes

From [virtual-destructor geeksforgeeks](https://www.geeksforgeeks.org/virtual-destructor/)

> Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor.

> Making base class destructor virtual guarantees that the object of derived class is destructed properly, i.e., both base class and derived class destructors are called.

more from virtual destructor on [this stackoverflow thread](https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors)

>To sum up, always make base classes' destructors virtual when they're meant to be manipulated polymorphically.

>If you want to prevent the deletion of an instance through a base class pointer, you can make the base class destructor protected and nonvirtual; by doing so, the compiler won't let you call delete on a base class pointer.

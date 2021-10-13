# Module_04

* [Sub-typing_Polymorphism](#Sub-typing_Polymorphism)
* [exercises notes](#notes)
* [Abstract_classes_and_interfaces](#abstract_classes_and_interfaces)

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

## abstract_classes_and_interfaces

```cpp
class ACharacter //A to indicates is an abtract class
{
	public:
		virtual void	attack(std::string const & target) = 0; //not implemented, the class that inherited from this will have to implement her own attacks. All children classes must have the attack behaviour. Also, the abstract class can't be instaciated
		void			sayHeloo(std::string const & target);
};
```

the abstract class can't be instaciated

```cpp
int main()
{
	ACharacter* a = new Warrior();//ok
	ACharacter* b = new ACharacter();//not possible because ACharacter is an abstract class
}
```

>There’s no interface in C++98 (not even in C++20) but it’s common to call pure abstract class Interface

interface is an abstract class with only abstracts behaviours

```cpp
class ImyInterface //I is also a convetion for interfaces
{
	public:
		virtual void abstractBehaviour() = 0;
		virtual void anotherAbstractBehaviour() = 0;
};
```
An abstract class can have atributes, but only the classes that derives from her will be able to use it (hence only them can be instanciated)

In the other hand, interfaces can't have atributes, only behaviours (like the example, a coffe maker). Contracts between developers

## notes

From [virtual-destructor geeksforgeeks](https://www.geeksforgeeks.org/virtual-destructor/)

> Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor.

> Making base class destructor virtual guarantees that the object of derived class is destructed properly, i.e., both base class and derived class destructors are called.

more from virtual destructor on [this stackoverflow thread](https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors)

>To sum up, always make base classes' destructors virtual when they're meant to be manipulated polymorphically.

>If you want to prevent the deletion of an instance through a base class pointer, you can make the base class destructor protected and nonvirtual; by doing so, the compiler won't let you call delete on a base class pointer.

From Siddhartha Rao - Sams Teach Yourself C in one Hour a Day

>A base class that cannot be instantiated is called an abstract base class. Such a base class fulfills only one purpose, that of being derived from. C++ allows you to create an abstract base class using pure virtual functions.

What class AbstractBase does is that it enforce class Derived to supply an implementation for virtual method's. This functionality where a base
class can enforce support of methods with a specified name and signature in classes that derive from it is that of an interface.

Even if an abstract base class cannot be instantiated, you can use it as a reference or a pointer.

>Abstract Base Classes are often simply called ABCs.

the usage of keyword `final` ensures that a class cannot be used as a base class.

```cpp

class Platypus final:public Mammal, public Bird, public Reptile
{
	//...
}

```

The `virtual` keyword in C++ often is used in different contexts for different purposes:

* A **function** declared `virtual` means that an existing overriding function in a derived class is invoked

* An **inheritance relationship** declared using keyword `virtual` between classes *Derived1* and *Derived2* that **inherits from class Base** means that another class *Derived3* that **inherits from Derived1 and Derived2** still results in the creation of **only one instance of Base** during instantiation of type Derived3.

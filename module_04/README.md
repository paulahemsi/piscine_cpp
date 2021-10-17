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

abstract function:

**virtual** void	attack(std::string const & target) **= 0**

```cpp
class ACharacter //A to indicates is an abtract class
{
	public:
		virtual void	attack(std::string const & target) = 0; //not implemented, the class that inherited from this will have to implement her own attacks. All children classes must have the attack behaviour. Also, the abstract class can't be instaciated
		void			sayHeloo(std::string const & target);
};
```

**abstract classses**

* can't be instanciated 
* at least one pure virtual function (method)

```cpp
int main()
{
	ACharacter* a = new Warrior();//ok
	ACharacter* b = new ACharacter();//not possible because ACharacter is an abstract class
}
```

>There’s no interface in C++98 (not even in C++20) but it’s common to call pure abstract class Interface

interface is an abstract class with **only** abstracts behaviours

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

From [C++FAQ](http://www.cs.technion.ac.il/users/yechiel/c++-faq/virtual-dtors.html)

**When should my destructor be virtual?**

* When someone will delete a derived-class object via a base-class pointer

In particular, here's when you need to make your destructor virtual:

* if someone will **derive** from your class,
* and if someone will say **new Derived**, where **Derived** is *derived from your class*,
* and if someone will say **delete p**, where the **actual object's** type is **Derived** but the pointer **p's type** is **your class**

Confused? Here's a simplified rule of thumb that usually protects you and usually doesn't cost you anything: 

> make your destructor virtual if your class has any virtual functions. Rationale:

* that usually protects you because most base classes have at least one virtual function.
* that usually doesn't cost you anything because there is no added per-object space-cost for the second or subsequent virtual in your class. In other words, *you've already paid all the per-object space-cost* that you'll ever pay once you add the *first virtual function*, so the virtual destructor doesn't add any additional per-object space cost. (Everything in this bullet is theoretically compiler-specific, but in practice it will be valid on almost all compilers.)

**Note:** in a derived class, if your **base class** has a *virtual destructor*, your *own destructor is automatically virtual*. You might need an explicitly defined destructor for other reasons, but *there's no need to redeclare a destructor simply to make sure it is virtual*. 

> No matter whether you declare it with the virtual keyword, declare it without the virtual keyword, or don't declare it at all, it's still virtual.


here are the mechanical details of why you need a virtual destructor when someone says delete using a Base pointer that's pointing at a Derived object: When you say `delete p`, and the class of `p` has a *virtual destructor*, the destructor that gets *invoked* is the one associated with the **type of the object *p**, not necessarily the one associated with the type of the pointer. This is A Good Thing. In fact, violating that rule makes your program undefined. The technical term for that is, "Yuck."

From Siddhartha Rao - Sams Teach Yourself C in one Hour a Day :

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

From qingqingqingli [Wiki](https://github.com/qingqingqingli/CPP/wiki/Module04)

>  A derived class can only be instantiated when it implements all of the pure virtual functions

> If a function/constructor is virtual in the base class, it's a better practice to label the same function / constructor virtual, to provide more visibilities.

**Shallow vs Deep Copies**

* A **shallow** copy of an object copies *all of the member field values*. This works well if the fields are values, but may not be what you want for fields that point to *dynamically allocated memory*. The pointer will be copied, but **the memory it points to will not be copied** -- the field in both the original object and the copy will then point to the same dynamically allocated memory, which is not usually what you want. **The default copy constructor and assignment operator make shallow copies**

* A **deep** copy copies all fields, and **makes copies of dynamically allocated memory pointed to by the fields**. To make a deep copy, you must **write a copy constructor and overload the assignment operator**, otherwise the copy will point to the original, with disasterous consequences.

> If an object has pointers to dynamically allocated memory, and the dynamically allocated memory needs to be copied when the original object is copied, then a deep copy is required.

A class that requires deep copies generally needs: 
* A constructor to either make an initial allocation or set the pointer to NULL.
* A destructor to delete the dynamically allocated memory.
* A copy constructor to make a copy of the dynamically allocated memory. 
* An overloaded assignment operator to make a copy of the dynamically allocated memory.

The best practice is to use **assignation operation** *inside* the *copy constructor*, so there's no duplication
It is important to remember that the copy constructor is a constructor : it initialises data i.e you have to initialise const attributes and call parent classes' constructors in it. Don't remember to initialise values.

> Canonical form should always include a constructor that takes in no parameter. So if one class can only need to instantiated with parameters, That means either the default constructor must be private, or it must be declared but non-implemented, to comply with Canonical form.

[About Abstract Base Classes](https://isocpp.org/wiki/faq/abcs#pure-virtual-fns)

**Random**

About how to make [random numbers generators more random](https://www.dreamincode.net/forums/topic/29294-making-pseudo-random-number-generators-more-random/)

A random number generated from the `rand()` function isn't actually random. It simply is a transformation. Every time we call `rand()` it takes the seed and/or the last random number(s) generated, runs a mathematical operation on those numbers, and returns the result. So if the **seed state** is the **same** each time (as it is if you don't call **srand with a truly random number**), then you will always get the same 'random' numbers out.

[StackOverflow thread](https://stackoverflow.com/questions/9459035/why-does-rand-yield-the-same-sequence-of-numbers-on-every-run)

# Module_03

* [Inheritance](#Inheritance)
* [exercises notes](#notes)

## Inheritance

A class can inherit from another

```cpp
class Animal
{
	private:
		int	_numberOfLegs;

	public:
		Animal();
		Animal(Animal const&);
		Animal &operator=(Animal const &);
		~Animal();

		void	run(int distance);
		void	call();
		void	eat(std::string const &food);
		void	walk(int distance);
};

class Cat : public Animal //inherited from Animal publicly
{
	public:
		Cat();
		Cat(Cat const&);
		Cat	&operator=(Cat const&);
		~Cat();

		void	scornSomeone(std::string const &target);
		void	walk(int distance);//overload Animal method walk
}
```
To instanciate a cat, first we will instanciate an Animal, then what is unique for the cat

```cpp
class Quadruped //Can access name, run() and legs
{
	private:
		std::string	name; //Only accessible from a Quadruped object
	protected:
		Leg	legs[4];//Accessible from a Quadruped or derived objects
	public:
		void	run();//Accessible from wherever
};

Class Dog : public Quadruped //Can access run() and legs
{
	//code
};

int main() //Can only access run()
{
	//code
}
```

## notes

>inheritance allows classes that are similar to derive from a base class that contains common attributes and implements common functionality, overriding this base functionality to implement behavior that makes each class unique.

>The is-a relationship between a derived class and its base is applicable only to public inheritance

ScavTrap **is-a** ClapTrap

```cpp
class Base
{
// ... base class members
};

class Derived: access-specifier Base
{
// ... derived class members
};
```

The access-specifier can be one of *public* (most frequently used) where a “derived class **is** a base class” relationship; *private* or *protected* for a “derived class **has** a base class” relationship.

`inherits from` or `derives from` essentially mean the same.

`base class` is also called `super class`. 

The class that *derives from the base*, also known as the `derived class`, can be called the `subclass`.

`protected` `public` `private` - **specifiers**

`protected` class attribute or function is accessible to classes that derive (and friends) and inaccessible to everyone else outside the class

> protected is the access specifier you should use if you want a certain attribute in a base class to be accessible to classes that derive from this base

> To ensure maximum security, if the derived classes don’t need to access a base class attribute, remember to mark the attribute private

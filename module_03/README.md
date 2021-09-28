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


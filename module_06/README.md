# Module_06

* [c_type_conversion](#c_type_conversion)
* [c_type_reinterpretation](#c_type_reinterpretation)
* [c_type_qualifier_reinterpretation](#c_type_qualifier_reinterpretation)
* [upcast_and_downcast](#upcast_and_downcast)
* [static_cast](#static_cast)
* [dynamic_cast](#dynamic_cast)
* [reinterpret_cast](#reinterpret_cast)
* [const_cast](#const_cast)
* [cast_operators](#cast_operators)
* [explicit_keyword](#explicit_keyword)


* [exercises_notes](#notes)

Casting is a mechanism by which the programmer can temporarily or
permanently change the interpretation of an object by the compiler.
Note that this does not imply that the programmer changes the object
itself—he simply changes the interpretation thereof. Operators that
change the interpretation of an object are called casting operators.






|     Cast         |  Conv . |  Reint . |  Upcast |  Downcast  |  Type qual .  |
| -----------------|---------|----------|---------|------------|------------- |
| implicit         | :heavy_check_mark: |   :x:   | :heavy_check_mark: | :x: | :x: |
| static_cast      | :heavy_check_mark: |   :x:   | :heavy_check_mark: | :heavy_check_mark:  | :x: |
| dynamic_cast     |   :x:   |   :x:    | :heavy_check_mark: | :heavy_check_mark: |:x:     |
| const_cast       |   :x:   |   :x:    |   :x:   |    :x:     | :heavy_check_mark: |
| reinterpret_cast |   :x:   | :heavy_check_mark: | :heavy_check_mark: |  :heavy_check_mark:   |  :x:  |
| legacy C cast    | :heavy_check_mark: | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |


|     Cast         |  Semantics check   |   Reliable at run    | tested at run  |
| -----------------|------------------- | -------------------- | -------------  |
| implicit         | :heavy_check_mark: | :heavy_check_mark:  |        :x:      |
| static_cast      | :heavy_check_mark: |          :x:        |        :x:      |
| dynamic_cast     | :heavy_check_mark: | :heavy_check_mark:  |:heavy_check_mark: |
| const_cast       |      :x:           |          :x:        |        :x:      |
| reinterpret_cast |      :x:           |          :x:        |        :x:      |
| legacy C cast    |      :x:           |          :x:        |        :x:      |


## c_type_conversion

```c++

int main(void)
{
	int a = 42;

	double b = a; // Implicit conersion cast 
	double c = (double)a; // Explicit conersion cast 

	double d = a; // Implicit promotion -> OK 
	int e = d; // Implicit demotion -> KO 
	int f = (int) d // Explicit demotion -> guarantee is a dev choice 
}

```
a: 00000000 00000000 00000000 00101010
b: 0 10000000100 0101000000000000000000000000000000000000000000000000
c: 0 10000000100 0101000000000000000000000000000000000000000000000000
d: 0 10000000100 0101000000000000000000000000000000000000000000000000
e: 00000000 00000000 00000000 00101010
f: 00000000 00000000 00000000 00101010

## c_type_reinterpretation

identity conversion

```c++

float a = 420.042f;

void *b = &a; // Implicit reintrepretetion
void *c = (void*)&a; //Explicit reinterpretation

void *d = &a; // Implicit promotion -> ok 
int  *e = d; // Implicit demotion -> KO 
int  *f = (int*)d; // Explicit demotion -> devs choice 

&a 0x7fff52
a  42.041992

b  0x7fff52
c  0x7fff52

d  0x7fff52
e  0x7fff52
*e 1137837408 //! totaly diferent number
f  0x7fff52
*f 1137837408 //! totaly diferent number

```

## c_type_qualifier_reinterpretation

the bits remain the same

```c++


int a = 420.042f;

int const *b = &a; // Implicit type qualifier cast
int const *c = (int const*)&a; //Explicit type qualifier cast

int const *d = &a; // Implicit promotion -> ok 
int  *e = d; // Implicit demotion -> KO compiler will refuse it because is a const, read only 
int  *f = (int*)d; // Explicit demotion -> devs choice, compilers does

//rare situation, maybe using a library that the programmer forgot to use const and you variable is const

```

## upcast_and_downcast

the same up and downcast logic aplys in classes with parents and childs

```cpp

#include <iostream>

class Parent                {}
class Child1: public Parent {};
class Child2: public Parent {};

int main(void)
{
	Child1 a;

	Parent *b = &a;
	Parent *c = (Parent *)&a;

	Parent *d = &a;
	Child1 *b = d; //wont compile
	Child2 *b = (Child2)d; //Explicit downcast in C style will compile but can be a desaster

	return (0);
}


```

C++ offers many types of casts and a new cast sintaxe allowing us to choose a specific cast for every situation, avoiding this kind of problems


## static_cast

simple conversion between direct values, upcasts and downcasts

**type of casts:**

* conversion
* reinterpretation
* type qualifier changes
* downcast
* upcast

```cpp

int		a = 42;

double	b = a; //implicit promotion
int		c = static_cast<int>(b); //explicit demotion (lost of precision etc)

```
```cpp

class Parent				{};
class Child1: public Parent	{};
class Child2: public Parent	{};

class Unrelated				{};


int main(void)
{
	Child1 a;
	
	Parent		*b = &a; //Implicit upcast - OK
	Child		*c = b; //Implicit downcast - KO
	Child		*d = static_Cast<Child2 *>(b); // Explicit downcast - ok, devs choice

	Unrelated	*e = static_Cast<Unrelated *>(&a); // Explicit conversion - not allowed, static cast protect us in this situations of unrelated classes (but dont protect in the above situation)
}



```

## dynamic_cast

runtime cast (all other casts are made during the compilation, in the static way)

can failed in runtime, so we need to build and architecture that detects the case where the dynamic cast will failed and handle it properly.

only work with polimorphic instances, unless one of the member functions should be virtual (to activate runtime type info rtti)

only for downcast, and it checks if the downcast is possible or not 

```cpp

class Parent				{public: virtual ~Parent(void){}};
class Child1: public Parent {};
class Child2: public Parent {};

int main(void)
{
	Child1	a;			//reference value
	Parent	*b = &a;	//implicit upcast - ok
	
	//explicit downcast ok:
	Child1	*c = dynamic_cast<Child1 *>(b); //ok, cause it comes from Child1
	if (c == NULL) //as is a pointer, any problem the dynamic cast will return null
	{
		std::cout << "Conversion is not ok" << std::endl;
	}
	else
	{
		std::cout << "Conversion is ok" << std::endl;
	}
	
	//explicit downcast ko (was Child1):
	try 
	{
		Child2 &d = dynamic_cast<Child2 &>(*b); //reference, hence the null return is not possible, but we can use a try catch
		std::cout << "Conversion is Ok" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		std::cout << "Conversion is not ok: " << bc.what() << std::endl;
		return (0);
	}
	return (0);
}

```

Usefull when using plugins: the code will be grouped under a class and we use the dynamic cast to can make sure that we are dealing with the right type, otherwise output an error message

## reinterpret_cast

reinterpretation, downcasts and upcast

the most open one, with it we are able to reinterpret any address as any other address (and deal with the consequences, so better to know what you are doing)

useful, for example, when reciving a void * bytes from a stream, the documentation says it's char but we can reinterpreted as string

simple use case:

```cpp

int main(void)
{
	float	a = 420.042f;						//Reference value

	void	*b = &a;							//Implicit promotion - ok
	int		*c = reinterpret_cast<int *>(b);	//Explicit demotion - ok, devs choice
	int		&d = reinterpret_cast<int &>(b);	//Explicit demotion - ok, devs choice
	
	return (0);
}

```

## const_cast

able to do a transformation of the type qualifyers

```cpp

int main(void)
{
	int			a = 42;						//Reference value
	
	int const	*b = &a;					// Implicit promotion - ok
	int			*c = b;						// Implicit demotion - won't compile
	int			*d = const_cast<int *>(b);	// Explicit demotion - ok, devs choice
	
	return (0);
}

```

Need a const_cast in the program can a be sign of a bad design, why it was a const type at the first place?!

## cast_operators

New sintax that will allow us to define in our classes specific operators in order to make implicit conversion of yout class in a type we are interested in

```cpp

class MyClass
{
	public:
		MyClass (float const value) : _value(value) {}
		
		float		getValue(void)					{return this->_value;}
		
		operator	float()							{return this->_value;} //allow us to assign an instance of our class to a float value
		operator	int()						    {return static_cast<int>(this->_value);} //allow us to assign an instance of our class to an int value with the cast we pre determined

	private:
	
		float _value;
}

int main(void)
{
	MyClass	a(420.042f);
	float	b = a;
	int		c = a;

	std::cout << a.getValue() << std::endl; //420.042
	std::cout << b << std::endl;			//420.042
	std::cout << c << std::endl;			//420

	return (0);
}

```

## explicit_keyword

prevent the implicit construction of our instance

```cpp

class A {};
class B {};

class C 
{
	public:
		C(A const & _) {return;}
		explicit C(B const & _) {return;}

};

void f (C const & _)
{
	return ;
}

int main(void)
{
	f(A()); //Implicit conversion ok
	f(B()); //Implicit conversion not ok because the constructor using a B class has the explicit keyword
	
	rerturn (0);
}

```

## notes

cast originated from one particular cast action: the conversion, wich allow us to transform the bits from one value after the coding of another value

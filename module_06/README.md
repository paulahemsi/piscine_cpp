# Module_06

* [intro](#intro)
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
* [study_resources](#study_resources)

## intro

> Casting is a mechanism by which the programmer can temporarily or permanently change the interpretation of an object by the compiler. Note that this does not imply that the programmer changes the object itself—he simply changes the interpretation thereof. Operators that change the interpretation of an object are called casting operators.

> In a perfectly type-safe and type-strong world comprising well-written C++ applications, there should be no need for casting and for casting operators. However, we live in a real world where modules programmed by a lot of different people and vendors often using different environments have to work together. To make this happen, compilers very often need to be instructed to interpret data in ways that make them compile and the application function correctly.

- Siddhartha Rao *"Sams Teach Yourself C++ in One Hour a Day"*

The four C++ casting operators are

* static_cast
* dynamic_cast
* reinterpret_cast
* const_cast

The usage syntax of the casting operators is consistent:

```cpp
destination_type result = cast_operator<destination_type> (object_to_cast);
```

**DO**

* remember that casting a Derived* to a Base* is called upcasting and this is safe
* remember that casting a Base* directly to a Derived* is called downcasting, and this can be unsafe unless you use dynamic_cast, and check for success.
* remember that the objective of creating an inheritance hierarchy is typically in having virtual functions that when invoked using base class pointers ensure that the available derived class versions are invoked
* mark conversion operators as explicit to avoid implicit conversions.

**DON'T**

* forget to check the pointer for validity after using dynamic_cast
* design your application around RTTI using dynamic_cast

|     Cast         | Conversion | Reinterpretation |  Upcast |  Downcast  |  Type qualifier |
| -----------------|---------|----------|---------|------------| ------------- |
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

![image](https://user-images.githubusercontent.com/63563271/141655477-af119393-1c7d-4116-9651-4212c9f335b9.png)


## c_type_conversion

```c++

int main(void)
{
	int a = 42;

	double b = a; // Implicit conversion cast 
	double c = (double)a; // Explicit conversion cast 

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


## static_cast

simple conversion between direct values, upcasts and downcasts

* used to convert pointers between related types, and perform explicit type conversions for standard data types that would otherwise happen automatically or implicitly
* implements a basic compile-time check to ensure that the pointer is being cast to a related type
* improvement over a C-style cast that allows a pointer to one object to be cast to an
absolutely unrelated type without any complaint
* Apart from helping in upcasting or downcasting, static_cast can, in many cases, help make implicit casts explicit and bring them to the attention of the programmer or reader

>a mechanism that can be used to convert pointers between related types, and perform explicit type conversions for standard data types that would otherwise happen automatically or implicitly. As far as pointers go, static_cast implements a basic compile-time check to ensure that the pointer is being cast to a related type. This is an improvement over a C-style cast that allows a pointer to one object to be cast to an absolutely unrelated type without any complaint. Using static_cast, a pointer can be upcasted to the base type, or can be downcasted to the derived type


## dynamic_cast

runtime cast (all other casts are made during the compilation, in the static way)

can failed in runtime, so we need to build and architecture that detects the case where the dynamic cast will failed and handle it properly.

only work with polimorphic instances, unless one of the member functions should be virtual (to activate runtime type info rtti)

only for downcast, and it checks if the downcast is possible or not 


```cpp

class Parent {public: virtual ~Parent(void){}};
class Child1: public Parent {};
class Child2: public Parent {};

int main(void)
{
	Child1	a; //reference value
	Parent	*b = &a; //implicit upcast - ok
	
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
Another example, by Siddhartha Rao in *"Sams Teach Yourself C++ in One Hour a Day"*

```cpp

#include <iostream>
using namespace std;

class Fish
{
	public:
	virtual void Swim()
	{
	cout << "Fish swims in water" << endl;
	}
	// base class should always have virtual destructor
	virtual ~Fish() {}
};

class Tuna: public Fish
{
	public:
	void Swim()
	{
	cout << "Tuna swims real fast in the sea" << endl;
	}
	void BecomeDinner()
	{
	cout << "Tuna became dinner in Sushi" << endl;
	}
 };

 class Carp: public Fish
 {
	public:
	void Swim()
	{
	cout << "Carp swims real slow in the lake" << endl;
	}

	void Talk()
	{
	cout << "Carp talked Carp!" << endl;
	}
 };

 void DetectFishType(Fish* objFish)
 {
	Tuna* objTuna = dynamic_cast <Tuna*>(objFish);
	if (objTuna) // check success of cast
	{
	cout << "Detected Tuna. Making Tuna dinner: " << endl;
	objTuna->BecomeDinner();
	}

	Carp* objCarp = dynamic_cast <Carp*>(objFish);
	if(objCarp)
	{
	cout << "Detected Carp. Making carp talk: " << endl;
	objCarp->Talk();
	}

	cout << "Verifying type using virtual Fish::Swim: " << endl;
	objFish->Swim(); // calling virtual function Swim
 }

 int main()
 {
	Carp myLunch;
	Tuna myDinner;

	DetectFishType(&myDinner);
	cout << endl;
	DetectFishType(&myLunch);

	return 0;
}
```
```
$
Detected Tuna. Making Tuna dinner:
Tuna became dinner in Sushi
Verifying type using virtual Fish::Swim:
Tuna swims real fast in the sea

Detected Carp. Making carp talk:
Carp talked Carp!
Verifying type using virtual Fish::Swim:
Carp swims real slow in the lake
$
```

Usefull when using plugins: the code will be grouped under a class and we use the dynamic cast to can make sure that we are dealing with the right type, otherwise output an error message

>actually executes the cast at runtime—that is, at application execution time. The result of a dynamic_cast operation can be checked to see whether the attempt at casting succeeded.

>for example, when a pointer of type Derived* is passed to a function that accepts type Base*. The function can use dynamic_cast given a base-class pointer type to detected type and then perform operations specific to the types detected. Thus, dynamic_cast helps determine the type at runtime and use a casted pointer when it is safe to do so. 

## reinterpret_cast

`reinterpret_cast` is the closest a C++ casting operator gets to the C-style cast.

reinterpretation, downcasts and upcast

forces a reinterpretation of type

the most open one, with it we are able to reinterpret any address as any other address (and deal with the consequences, so better to know what you are doing)

useful, for example, when reciving a void * bytes from a stream, the documentation says it's char but we can reinterpreted as string

> This cast actually forces the compiler to accept situations that static_cast would normally not permit. It finds usage in certain low-level applications (such as drivers, for example) where data needs to be converted to a simple type that an API—Application Program Interface—can accept (for example, some OS-level APIs require data to be sent as a BYTE array, that is, unsigned char*)
- Siddhartha Rao in *"Sams Teach Yourself C++ in One Hour a Day"*


simple use case:

```cpp

int main(void)
{
	float	a = 420.042f; //Reference value

	void	*b = &a; //Implicit promotion - ok
	int		*c = reinterpret_cast<int *>(b); //Explicit demotion - ok, devs choice
	int		&d = reinterpret_cast<int &>(b); //Explicit demotion - ok, devs choice
	
	return (0);
}

```

>reinterpret_cast is the closest a C++ casting operator gets to the C-style cast. It really does allow the programmer to cast one object type to another, regardless of whether or not the types are related; that is, it forces a reinterpretation

>It finds usage in certain low-level applications (such as drivers, for example) where data needs to be converted to a simple type that an API—Application Program Interface—can accept (for example, some OS-level APIs require data to be sent as a BYTE array, that is, unsigned char*)

> As far as possible, you should refrain from using reinterpret_cast in your applications because it allows you to instruct the compiler to treat type X as an unrelated type Y, which does not look like good design or implementation.
- Siddhartha Rao in *"Sams Teach Yourself C++ in One Hour a Day"*

## const_cast

enables to turn off the const access modifier to an object

```cpp

int main(void)
{
	int			a = 42; //Reference value
	
	int const	*b = &a; // Implicit promotion - ok
	int			*c = b; // Implicit demotion - won't compile
	int			*d = const_cast<int *>(b); // Explicit demotion - ok, devs choice
	
	return (0);
}

```

Need a const_cast in the program can a be sign of a bad design, why it was a const type at the first place?!

But in many cases the not-using-const error might belong to a third-party library, and making changes to it is
not possible. In situations such as these, const_cast is the savior.

## cast_operators

New sintax that will allow us to define in our classes specific operators in order to make implicit conversion of yout class in a type we are interested in

```cpp

class MyClass
{
	public:
		MyClass (float const value) : _value(value) {}
		
		float		getValue(void) {return this->_value;}
		
		operator	float() {return this->_value;} //allow us to assign an instance of our class to a float value
		operator	int() {return static_cast<int>(this->_value);} //allow us to assign an instance of our class to an int value with the cast we pre determined

	private:
	
		float _value;
}

int main(void)
{
	MyClass	a(420.042f);
	float	b = a;
	int		c = a;

	std::cout << a.getValue() << std::endl; //420.042
	std::cout << b << std::endl; //420.042
	std::cout << c << std::endl; //420

	return (0);
}

```

## explicit_keyword

To avoid implicit conversions, we can use `explicit` keyword at the beginning of an operator declaration

Using explicit would force the programmer to assert his intention to convert using a cast

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

`scalar types: arithmetic types and pointer types`

`arithmetic types: integer types and floating types`

```
Floating-point types may support special values:

infinity (positive and negative), see INFINITY
the negative zero, -0.0. It compares equal to the positive zero, but is meaningful in some arithmetic operations, e.g. 1.0/0.0 == INFINITY, but 1.0/-0.0 == -INFINITY)
not-a-number (NaN), which does not compare equal with anything (including itself). Multiple bit patterns represent NaNs, see nan, NAN. Note that C takes no special notice of signaling NaNs (specified by IEEE-754), and treats all NaNs as quiet.
```

**uintptr_t**

Integer type capable of holding a value converted from a void pointer and then be converted back to that type with a value that compares equal to the original pointer


## study_resources

* [Type Punning in C++](https://www.youtube.com/watch?v=8egZ_5GA9Bc)
* [Casting in C++](https://www.youtube.com/watch?v=pWZS1MtxI-A)

>"You can include any header you need to handle numeric limits and special values."

* [C++ setprecision doc](https://www.cplusplus.com/reference/iomanip/setprecision/)
* [c++ fixed](https://en.cppreference.com/w/cpp/io/manip/fixed)



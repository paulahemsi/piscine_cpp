# Module_07

* [From C: Parametric macros](#From_C:_Parametric_macros)
* [Templates](#Templates)
* [Default type](#Default_type)
* [Specialization](#Specialization)

## From_C:_Parametric_macros

```c

#include <stdio.h>

//function does the same, but need to be three cause receive diferents parameters
int max_int (int x, int y) {return (x>=y ? x : y);}
float max_float (float x, float y) {return (x>=y ? x : y);}
char max_char (char x, char y) {return (x>=y ? x : y);}


// parametric macro seems to solve the problem
#define max(x, y) (((x) > = (y))? (x) : (y))
// everything begining with a # is a instruction to the pre precessor
// in defines, the cpp (c pre processor) will replace in the code

// macros can be a problem in an edge case, like this function:
int foo(int x) {printf("Long computing time\n"); return x; }


int main(void)
{
	int a = 21;
	int b = 42;

	//using the function and the macro, the result is the same in this case
	printf("Max of %d and %d is %d\n", a, b, max_int(a, b));
    printf("Max of %d and %d is %d\n", a, b, max(a, b));

    float c = -1.7f;
    float d = 4.2f;

	//using the function and the macro, the result is the same in this case
    printf("Max of %f and %f is %f\n", c, d, max_float(c, d));
    printf("Max of %f and %f is %f\n", c, d, max(c, d));

	char e = 'a';
	char f = 'b';

	//using the function and the macro, the result is the same in this case
	printf("Max of %c and %c is %c\n", e, f, max_int(e, f));
	printf("Max of %c and %c is %c\n", e, f, max(e, f));

	//*but .....
	printf("Max of %d and %d is %d\n", a, b, max_int(foo(a), foo(b)));
	printf("Max of %d and %d is %d\n", a, b, max(foo(a), foo(b))); //in this case the long computing time will be done an extra time
	// when the expression is evaluated, instead of just placing the result the macro will replace x again with the whole long-time-function, increasing the time of the program. Also a problem with databases searches and other cases

	return (0);
}

```

same problem with linked lists, creating a struct and functions for each type or using a void * struct but adding an extra size information to the struct and functions to know the chosen type size and also forcing the use of pointer that wont be necessary in scalar types. The use of the pointer for those types will lead in a lot of unreferences, which can make the program slower (eg. games with lag)

## Templates

allow us to write code that will be fill with diferents type variables

function templates, class templates or struct templates

```cpp

int max(int x, int y)
{
	return (x >= y ? x : y);
}

```

to make this function a template, we need a line to tag the template and define the name for the the generic type we will now use in the function 

this generic type can be replaced by any type, including an instance of a class, so, to save memory, is better not to take parameters by copy but take references instead

And as the function doesn't make changes in the values, is better to make them constants

```cpp

template<typename T>
T max(T const &x, T const &y)
{
	return (x >= y ? x : y);
}

```

And since we are working with consts and references, we can return also in this way

```cpp

template<typename T>
T const & max(T const & x, T const & y)
{
	return (x >= y ? x : y);
}

```

> A template is a cake mold, not the actual cake. We want the compiler to take the cake mold and make a cake for us

template in use:

```cpp


#include <iostream>

template<typename T> 

T & max(T const & x, T const & y) //in this case, not const return cause he wants a copy
{
	return (x >= y? x : y);
}

int foo(int x) {
	std::cout << "Long computing time" << std::endl;
	return x;
}

int main(void)
{
	int a = 21;
	int b = 42;

	//we need to instanciate our template
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max<int>(a, b) << std::endl; // explicit instantiation using the < > (casting!) to inform the type
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << max(a, b) << std::endl; // implicit instantiation, compiler deduce by the arguments types. Can be a problem in complex situations

    float c = -1.7f;
    float d = 4.2f;

    std::cout << "Max of " << c << " and " << d << " is ";
    std::cout << max<float>(c, d) << std::endl; // explicit instantiation
    std::cout << "Max of " << c << " and " << d << " is ";
    std::cout << max(c, d) << std::endl; // implicit instantiation

	char e = 'a';
	char f = 'z';

	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << max<char>(e, f) << std::endl; // explicit instantiation
	std::cout << "Max of " << e << " and " << f << " is ";
    std::cout << max(e, f) << std::endl; // implicit instantiation

    // no problem here, cause is not a macro but a template instead :

    int ret = max<int>(foo(a), foo(b)); // explicit instantiation
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << ret << std::endl;

	return 0;
}

```

template for linked lists class:

```cpp

template<typename T>
class List {

public:
    List<T>(T const & content) {
    	// etc...
    }

    List<T>(List<T> const & list) {
    	//etc...
    }

    ~List<T>(void) {
        //etc...
    }

    //etc...

private:
	T * _content; // we can remove the * if it will be not needed
    List<T> * _next;
};

/*******************************************************/

int main(void)
{
	List<int> a(42); //list of int
	List<float> b(3.14f); //list of float
	List<List<int>> c(a); //list of list of integers

	//etc...

	return 0;
}


```

It's also possible declare a template with more than one type 

```template<typename T, typename U>```

```List<int, float>```

Cpp standart library has excelents data structers (STL) (standart template library)

## Default_type

is possible to pass default values to the types in our templates

```cpp


Template<typename T = float> //float is the default type, if we don't tell the type the compiler will assume it's float
class Vertex {
public:
	Vertex (T const & x, T const & y, T const & z): _x(x), _y(y), _z(z) {}
	~Vertex(void){}

	T const & getx(void) const {return this->_x};
    T const & gety(void) const {return this->_y};
    T const & getz(void) const {return this->_z};

    // Etc...

private:
	T const _x;
    T const _y;
    T const _z;

    Vertex(void);
};

template<typename T>
std::ostream & operator<<(std::ostream & o, Vertex<T> const & v) {
	std::cout.precision(1);
	o << setiosflag(std::ios::fixed);
	o << "Vertex( ";
	o << v.getX() << ", ";
	o << v.getY() << ", ";
	o << v.getZ();
	o << " )";
	return o;
}



int main(void)
{
	Vertex<int> v1(12, 23, 34); //three integers
	Vertex<> v2(12, 23, 34); // three integers that will be implicitly converted to floats(default)

	std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    return 0;
}


```

```
Output:

Vertex( 12, 23, 34)
Vertex( 12.0, 23.0, 34.0)

```

## Specialization

partial ou full

```cpp

//template:

template <typename T, typename U>
class Pair {

public:
	Pair<T, U>(T const & lhs, U const & rhs) : _lhs(lhs), _rhs(rhs) {
		std::cout << "Generic template" << std::endl;
		return;
	}

	~Pair<T, U>(void) {}

	T const & fst(void) const {return this->lhs;}
    U const & snd(void) const {return this->rhs;}

private:

	T const & _lhs;
    U const & _rhs;

    Pair<T, U>(void);
};

```

```cpp

//specialization for cases when we want to use a fix int type and a generic type, changing the code accondingly:

template <typename U> //now, only one generic type
class Pair<int, U> { //type diferences between < >

    public:
    Pair<int, U>(int & lhs, U const & rhs) : _lhs(lhs), _rhs(rhs) {
        std::cout << "Int partial specialization" << std::endl;
        return;
    }

    ~Pair<int, U>(void) {}

    int     & fst(void) const {return this->lhs;}
    U const & snd(void) const {return this->rhs;}

    private:

    int     & _lhs;
    U const & _rhs;

    Pair<int, U>(void);
};


//full especalization for booleans:

template <> //no need of type variables
class Pair<bool, bool> { 

public:
    Pair<bool, bool>(bool lhs, bool rhs) : _lhs(lhs), _rhs(rhs) {
        std::cout << "bool/ bool full specialization" << std::endl;
        this->_n = 0;
        this->_n |= static_cast<int>(lhs) << 0;
		this->_n |= static_cast<int>(rhs) << 1;
        return;
    }

    ~Pair<bool, bool>(void) {}

	bool fst(void) const {return (this->_n & 0x01);}
	bool snd(void) const {return (this->_n & 0x02);}

private:

    int     _n;

    Pair<bool, bool>(void);
};


template<typename T, typename U>
std::ostream & operator<<(std::ostream & o, Pair<T, U> const & p) {
    o << "Pari(" << p.fst() << ", " << p.snd() << " )";
    return o;
}

std::ostream & operator<<(std::ostream & o, Pair<bool, bool> const & p) {
    o << std::boolalpha << "Pari(" << p.fst() << ", " << p.snd() << " )";
	return o;
}


int main(void){
	Pair<int, int> p1(4, 2); // partial specialization
	Pair<std::string, float> p2(std::string "Pi", 3.14f); // generic template
	Pair<float, bool> p3(4.2f, true); // generic template
	Pair<bool, bool> p4(true, false);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;

    return 0;
}

```

```
Output:
Int partial specialization
Generic template
Generic template
bool/ bool full specialization
Pair(4, 2)
Pair(Pi, 3.14f)
Pair(4.2f, 1) // 1 and not true because it dont have the std::boolalpha
Pair(true, false) // std::boolalpha was userd, so false and not 0, true and not 1
```

boost library uses a lot of templates

templates can generate hard to debug errors

templates can be very unreadable, so we need to be carefull

code more readable with:

* typedefs
* smaller functions
* smaller templates
* more atomic things
* design it correctly to be able to reuse-it later

## notes


**ex02**

`(Tip: try to compile int * a = new int();, then
display *a.)`

new int dynamically allocates an object of type int, and gives a pointer to that.

```cpp
int main(void)
{
	int *a = new int();
	std::cout << *a << std::endl; //0
	int *b = new int(4);
	std::cout << *b << std::endl; //4
	int *c = new int(33333);
	std::cout << *c << std::endl; //33333
	int *d = new int[6];
	for (int i = 0; i < 6; i++)
		std::cout << *(d + i) << std::endl; //0 (undefined values)
	for (int i = 0; i < 6; i++)
		std::cout << d[i] << std::endl; //0 (undefined values)
	int *e = new int[6](); //initializes the int values to 0
	for (int i = 0; i < 6; i++)
		std::cout << e[i] << std::endl; //0
}
```

```
int *p_scalar = new int(5); //allocates an integer, set to 5. (same syntax as constructors)
int *p_array = new int[5];  //allocates an array of 5 adjacent integers. (undefined values)
int *cpp11_array = new int[5] {1, 2, 3, 4, 5};  //allocates an array of 5 adjacent integers initialized to {1, 2, 3, 4, 5}. (C++11 only)
```

>In C++98 initializers cannot be specified for arrays created with new. When no initializer list is provided all elements of an array are initialized with the default constructor of the type. If the type does not have a default constructor, this is a compile-time error.

from [new and delete (C++)](https://en.wikipedia.org/w/index.php?title=New_and_delete_(C%2B%2B)&oldid=690112349)

`new int[100]();` This will allocate an array of int and zero-initialize its elements.

-------------------------

about the error **argument list for class template "Array" is missing**:

> When you separate method definitions from their declarations for a templated class, you have to include the same template declaration on every method definition, and quality the class name with the template argument(s), eg:

```cpp

template <typename T>
class Array
{
private:
    //code
public:
    //code
};

template <typename T>
Array<T>::~Array()
{

}

template <typename T>
int Array<T>::isValidIndex(int index) const
{

}

// and so on..

```

from [this stackoverflow thread](https://stackoverflow.com/questions/48999185/argument-list-for-class-template-is-missing-cpp)

--------------------------

`new int[0]`

>When the value of the expression in a direct-new-declarator is zero, the allocation function is called to allocate an array with no elements.

>The effect of dereferencing a pointer returned as a request for zero size is undefined.

>That means you can do it, but you can not legally (in a well defined manner across all platforms) dereference the memory that you get - you can only pass it to array delete - and you should delete it.

>The intent is to have operator new() implementable by calling malloc() or calloc(), so the rules are substantially the same. C++ differs from C in requiring a zero request to return a non-null pointer.

from [this stackoverflow thread](https://stackoverflow.com/questions/1087042/c-new-int0-will-it-allocate-memory)

# piscine_cpp
Dive into C++ | école 42

```
"C++ was an object-oriented extension to C that kept most of the basic C features and semantics.
Indeed its implementation was as a preprocessor to existing C compilers.
Its key insight was to allow the C struct to encapsulate both data and
functions with added key words for data hiding,
and to add resource handlers called constructors and destructors."

Ira Pohl
```

```
And the crucial thing that makes OO languages so powerful is,
they allow type extensibility that allows you to program naturally with the new types.
```

C++98 is simpler nad easier to beggin

## Module_00

### Namespaces

In each scope, a name can only represent one entity. So, there cannot be two variables with the same name in the same scope. Using namespaces, we can create two variables or member functions having the same name.

Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope. This allows organizing the elements of programs into different logical scopes referred to by names.

* Namespace declarations appear only at global scope.
* Namespace declarations can be nested within another namespace.
* Namespace declarations don’t have access specifiers. (Public or private)
* No need to give semicolon after the closing brace of definition of namespace.
* We can split the definition of namespace over several units.

```c
int my_var = 3;
int my_function(void) {return 3;}

namespace my_namespace {

int my_var = 5;
int my_function(void) {return 6;}

}

namespace alias = my_namespace;
```

`::` scope resolution operator

```c
[namespace]::[var]

alias::my_var
```

`std::` standart library namespace

`::my_var` == `my_var`

### in_out

`std::cout << "Hello, C++!" << std::endl;` == `write(1, "Hello, C++!\n", 15);`

`std::cin >> buffer;` -> reads from stdin

`std::cout << "you sayed:" << buffer << "!" << std::endl;`

### Class and instance

`.class` pre extension to better organize and makes class files explicit
`My_class.class.hpp`
`My_class.class.cpp`

constructors and distructors don´t have a return type, they are producers

```cpp
#ifndef MY_CLASS_H
# define MY_CLASS_H

class My_class {
	My_class(void); //Constructor - is called when the class is instaciated
	~My_class(void); //Destructor - is called when the instance get destroyed
};

#endif
```

constructors can also accept parameters
```cpp

class My_class {
	My_class(char c, int i, float f); //Constructor - is called when the class is instaciated
	~My_class(void); //Destructor - is called when the instance get destroyed
};

```

class is a static part, a model

the incante will be the dynamic part

the class is the molde and the instance is the cake

instanciating:

```cpp
int main(void) {
	My_class my_instance;
	
	return(0);
}

```

## Member attributes and member functions

`member attribute` a variable that you have in your class that you may use in a instance

`member functions` are functions that you can use in your instances

```cpp

void Class_name::function_name(void) {
	//function body
	return ;
}

```

```cpp
int main(void) {
	Class_name	my_instance;

	my_instance.function_name();
	return (0);
}
```

## This

`this` is a pointer to the current instance
We use `this` inside the constructor

```cpp
My_class::My_class(void) {
	this->my_var = 42;
	this->my_func();
	return ;
}
```

## Initialization

```cpp

class My_class {
	char	my_char;
	int		my_int;
	float	my_float;

	My_class(char c, int i, float f); //Constructor - is called when the class is instaciated
	~My_class(void); //Destructor - is called when the instance get destroyed
};

```

this:

```cpp

My_class::My_class(char c, int i, float f) {
	this->my_char = c;
	this->my_int = i;
	this->my_float = f;
	return ;
}

```

with initialization list sintax became this:

```cpp

My_class::My_class(char c, int i, float f) : my_char(c), my_int(i), my_float(f){
	return ;
}

```

## const

`const` cannot be changed
in c++ we can declare a const in out class and define a different value for each object in the constructor

```cpp
class My_class {
	public:
	
		float const pi;
		
		My_class(float const f);
		~My_class(void);
}
```
```cpp
My_class::My_class(float const f) : pi(f) {
	return ;
}
```
It's also possible to use constante in a functions, meaning that the instance of the class cannot be changed in this function
```cpp
class My_class {
	public:

		float const	pi;
		int			i;

		My_class(float const f);
		~My_class(void);

		void my_func(void) const; // read-only mode
}
```

```cpp
void My_class::my_func(void) const {
	this->i = 0; //compiler error! We can't assign any value for our instance
	return ;
}
```

## Visibility

`public` and `private` control the encapsulation of the members of the class

`public` available outside the class
`private` only available inside the class

`_my_private_var_`
`_my_private_function`
`_` before the name: convention for privates variables and functions

Expose outside only the parts will be usefull for the user
Keep private as much as possible

## Structs x Class

Class and structs works in the same way in C++, but the scope of the structure is public by default and the scope of the class is private by the default

## Getter

Proxy pattern is a software design pattern. A proxy, in its most general form, is a class functioning as an interface to something else.

get and set are getters functions, a interface to interact with a private variable

```cpp

class My_class {
public:

	My_class(void);
	~My_class(void);

	int get_var(void) const; //getter, read only mode
	bool set_var(int value); //setter with bool return to indicates if the value has changed
	
private:
	int _var;
}
```

with the getters we get control over the class variables, returning a copy when needed and making rules to the setter

```cpp

(...)

int My_class::get_var(void) const {
	return this->_var;
}

bool My_class::set_var(int value) {
	if (value >= 0)
	{
		this->_var = value;
		return (true);
	}
	return (false);
}
```

## Comparisons

it's possible not only to compare adresses but also structural equality

in class header:

```cpp
int compare(My_class *other) const;
```

in class implementation:

```cpp
int My_class::compare(My_class *other) const {
	if (this->_var < other->get_var())
		return (-1);
	else if (this->_var > other->get_var())
		return (1);
	return (0);
}
```

## Non Member Attributes and functions

or Class attributes and functions (not-instances attributes and functions)

`static`: functions and variables from the class, and not for each instance

```cpp

class My_class {

public:

	My_class(void);
	~My_class(void);
	
	static int	get_number_of_instances(void);
	
private:

	static int	_number_of_instances;
}

```

```cpp

My_class::My_class(void) {
	My_class::_number_of_instances += 1;
	return ;
}

My_class::~My_class(void) {
	My_class::_number_of_instances -= 1;
	return ;
}

//static func dont have the instance as a secret argument, therefore we can't use THIS keyword
int My_class::get_number_of_instances(void) {
	return My_class::_number_of_instances;
}

int My_class::_number_of_instances = 0; //initializing the static non-member variable

```
## Pointers to members and members functions

```cpp

class My_class {

public:

	int var;

	My_class(void);
	~My_class(void);

	void func(void) const; //non-member function
}

```

```cpp

int main(void) {
	
	My_class	instance;
	My_class	*instance_ptr;

	int			My_class::*ptr = NULL; //pointer to a int from My_class
	void		(My_class::*func_ptr)(void) const; //pointer to a non-member function from My_class

	ptr = &My_class::var; //assigning the var address from My_class to the pointer, without specifiyng an instance

	instance.*ptr = 21; //using the pointer to assign 21 to var from instance
	instance_ptr->*ptr = 42; //using the pointer to the var and the pointer to the instance to assign 42 to var
	func_ptr = &My_class::func; //assigning the func address to My_class-function-pointer

	(instance.*func_ptr)(); //using the function pointer to call func from instance
	(instance_ptr->*func_ptr)(); //using the function pointer and instance pointer to call func

	return 0;
}

```

## ex01

Why I choose `a_string == other_string` over `a_string.compare(other_string)`:

`std::string::compare()` works pretty much like `strcmp` and returns `0` if the string are equal, `< zero` if a_string is less than other_string and ` > 0` if a_string is greater than other_string.

In the other hand, the equality operator only tests for equality and returns a `bool`. Hence I was not interested in how the strings are related, but in the equality between then, I choose `==` (it's also more straight forward and readable than `!a_string(other_string)` and still a huge improvement over C, beeing able to make this comparsion is such a simple way)

________________

I have to options to ask the user for an input, and booth of them have some issues:

`std::getline(std::cin, input)` stores in the `input` string variable the hole string, until the user press enter. But this method stores the `\n` in the `cin` buffer, therefore when the *getline* is called again, it reads the `\n` and exits the function without the user have the chance to write anything.

In the other hand, `std::cin >> input` doesn't handle well spaces, only beeing able to store a word without any space.

To solve this problem, I used [std::cin.ignore()](https://www.cplusplus.com/reference/istream/istream/ignore/) function. 


> Extracts characters from the input sequence and discards them, until either n characters have been extracted, or one compares equal to delim.

> The function also stops extracting characters if the end-of-file is reached. If this is reached prematurely (before either extracting n characters or finding delim), the function sets the eofbit flag.


It's a tricky function, though, cause in loops it can ignore the first letter of the words, so be carefull where you place it.

[this](https://stackoverflow.com/questions/4745858/stdcin-getline-vs-stdcin) and [this other](https://stackoverflow.com/questions/61007300/why-is-cin-ignore-ignoring-the-first-character-of-my-getline-input) threads in stackoverflow give's a good overview of the issue.

## ex02

initializing the four static non-member variable:

```cpp
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
```

and member variables in the constructor

```cpp
Account::Account( int initial_deposit )	:	_amount(initial_deposit),
											_accountIndex(_nbAccounts),//cause we initialize _nbAccount in 0 and keep track of this number in each instance created
											_nbDeposits(0),
											_nbWithdrawals(0)
{
	Account::_nbAccounts++; //next instance index will be the next one
	Account::_amount += this->_amount; // == initial_deposit
}
```

```cpp
Account::~Account( void )
{
	Account::_nbAccounts--; //destructor needs to subtract the instance from the total accounts
	Account::_amount -= this->_amount; //same with total amount from all accounts
}
```

log clue: `[19920104_091532] index:0;p_amount:47;withdrawal:refused`
when the withdrawal is more than the value, it is refused

compiler clue: `error: field '_amount' will be initialized after field '_accountIndex' [-Werror,-Wreorder-ctor]`

log clue:
```
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] index:2;amount:957;created
[19920104_091532] index:3;amount:432;created
[19920104_091532] index:4;amount:1234;created
[19920104_091532] index:5;amount:0;created
[19920104_091532] index:6;amount:754;created
[19920104_091532] index:7;amount:16576;created
```
when each account (instance) is created, infos are logged
the values match with amount array

log clue:
```
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
[19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
[19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
[19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
[19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
[19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
[19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0
```
between created and deposits, display account general infos and each account info, ~~hence the display account function also displays each account informations~~ 
Account info are displayed in displayStatus function inside `std::for_each` loop =D

In order to solve the mistery, I inserted some printf in key lines of the code, it was very enlightening

deciphering tests.cpp

```cpp
int		main( void ) {

	//creating account vector (~= array)
	typedef std::vector<Account::t>							  accounts_t;

	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	//initial amounts array
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	//????
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	//stores accounts beggining and end?
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	//deposits array
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	//withdrawals array
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}
```
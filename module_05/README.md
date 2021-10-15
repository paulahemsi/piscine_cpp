# Module_05

* [Nested_classes](#Nested_classes)
* [Exceptions](#Exceptions)
* [exercises notes](#notes)

## Nested_classes

Define a class in the definition of another class

```cpp
class Cat
{
	public:
		class Leg
		{
			//(...)
		};
};

class Dog
{
	public:
		class Leg
		{
			//(...)
		};
};

int main(void)
{
	Cat			someCat;
	Cat::Leg	someCatLeg;
}

```

## Exceptions

Exceptions are a way of handling errors, reporting with a message (instead of the negative return as we were used to do in C)

`std::exception` base type for all exceptions

`throw` keyword will look for a `catch` block and enters it

```cpp

void my_function(void)
{
	try
	{
		//(...)
		if (/*error situation*/)
		{
			throw std::exception();
		}
		else
		{
			//(...)
		}
	}
	catch (std::exception e)
	{
		//handle the error
		e.what();//returns a message describing what happened
		//write some message in stdout
		//dealocate memory
		//etc
	}
}

```
```cpp

void my_function(void)
{
	//(...)
	if (/*error*/)
	{
		throw std::exception();
	}
	else
	{
		//(...)
	}
}

void another_function(void)
{
	try
	{
		my_function();
	}
	catch (std::exception& e) //this will catch the error throw in my_function by reference
	{
		//Handle error
	}
}

```

`throw` in the end of a function definition a way to specify which exceptions a method can throw

```cpp

void test()
{
	class MYCUSTOMException : public std::exception //polymorphism, MYCUSTOMException is also an exception
	{
		public:
			virtual const char* what() const throw() //throw in the end determines if throw something or not (like this one, empty)
			{
				return ("My custom problem");
			}
	};
	try
	{
		another_function();
	}
	catch (MYCUSTOMException& e) //specific catch
	{
		//Handle the custom exception
	}
	catch (std::exception &e) //generic exception
	{
		//Handle other exceptions that are like std::exception
	}
}

```

>exception is for use exceptionaly

throwing exception is resource consuming, so in case of errors that occurs very often we should use return value indicating it, like a boolean to return *ok* or *not ok*

in the case in which it doesnt return an error often, not part of the normal behaviour of the program, return throw exceptions (like `bad allock` exception in `new`)

## notes

**std::endl vs \n**

std::endl flushes the buffer and writes your output immediately while '\n' allows the outfile to put all of your output into a buffer and maybe write it later.

**Steps to copy one file to another in C++:**

* Create objects of ifstream and ofstream classes.
* Check if they are connected to their respective files. If so, go ahead otherwise check the filenames twice.
* Read the contents of the source file using the getline() method and write the same to the destination using the << operator ( i.e. 
* Copy each line from ifstream object to ofstream object).
* Close files after the copy using the close() method.

From [pencilprogrammer](https://pencilprogrammer.com/cpp-programs/copy-one-file-to-another/)

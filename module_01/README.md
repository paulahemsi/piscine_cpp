## Module_01

* [New_and_delete](#New_and_delete)
* [References](#References)
* [file_stream](#file_stream)
* [ex04 notes](#ex04)

### New_and_delete

`new` amd `delete` are the keywords to allocate and desallocate instances in the heap, they are using malloc and free under the hood but to us is much more simple.

Is even possible to allocate a whole array in this simple line:

```cpp
Class *varName = new Class[42];
```

And deallocate:

```cpp
delete [] varName;
```

### References

reference is like an alias for an existing variable

a pointer that constant and always unreferenced and never void

reference is like a dereferenced pointer

`int& ref_var` ref_var is a reference to int, and we assign the int variable to this var, not the adress

```cpp

int main(void) {
	int number = 42;

	int	*numberPtr = &number;
	int	&numberRef = number; //like a constant, the reference can never be changed, it will always be pointing to the same var. Either can be inicialized withou assigning a value.

	std::cout << number << " " << *numberPtr << " " << numberRef << std::endl; // 42 42 42

	*numberPtr = 7;
	std::cout << number << std::endl; // 7
	numberRef = 666;
	std::cout << number << std::endl; // 666
	
	return (0);
}

```

passing a reference as parameter

```cpp

void byRef(std::string& str)
{
	str += "other thing";
}

int main(void)
{
	std::string str = "something";
	byRef(str);
}

```

returning a reference *vs* returning a pointer

```cpp

std::string &getStringRef()
{
	return this->_str;
}

std::string const &getStringRefConst() const
{
	return this->_str;
}

std::string *getStringPtr()
{
	return &(this->_str);
}

std::string const *getStringPtrConst() const
{
	return &(this->_str);
}

```

use a **pointer** if at some point it shouldn't exist or if it should change
use a **reference** if it should always axist and never change

### file_stream

>Objects of this class maintain a filebuf object as their internal stream buffer, which performs input/output operations on the file they are associated with (if any).


`ifs` input file stream
`ofs` output file stream

```cpp
# include <iostream>
# include <fstream>

int main()
{
	std::ifstream	ifs("numbers");//open numbers file and link it to the stream ifs.open also exists
	unsigned int	dts;
	unsigned int	dst2;

	ifs >> dst >> dst2; //saving in the variables what was read from the file
	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();
	
	std::ofstream ofs("test.out");
	
	ofs << "writing to a file" << std::endl;
	ofs.close();
}
```

### ex04

**npos**

(`std::string::npos`)

```
npos is a static member constant value with the greatest possible value for an element of type size_t.

This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".

As a return value, it is usually used to indicate no matches.

This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type.
```
**.find**

(`(*text).find(replacebleStr, i + 1)`)

```
Searches the string for the first occurrence of the sequence specified by its arguments.

When pos is specified, the search only includes characters at or after position pos, ignoring any possible occurrences that include characters before pos.

Notice that unlike member find_first_of, whenever more than one character is being searched for, it is not enough that just one of these characters match, but the entire sequence must match.
```

**.erase**

(`(*text).erase(i, (*replacebleStr).length())`)

```
(1) sequence
Erases the portion of the string value that begins at the character position pos and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.
Notice that the default argument erases all characters in the string (like member function clear).
(2) character
Erases the character pointed by p.
(3) range
Erases the sequence of characters in the range [first,last].
```

**insert**

(`(*text).insert(i, (*newStr))`)

```
(1) string
Inserts a copy of str.
(2) substring
Inserts a copy of a substring of str. The substring is the portion of str that begins at the character position subpos and spans sublen characters (or until the end of str, if either str is too short or if sublen is npos).
(3) c-string
Inserts a copy of the string formed by the null-terminated character sequence (C-string) pointed by s.
(4) buffer
Inserts a copy of the first n characters in the array of characters pointed by s.
(5) fill
Inserts n consecutive copies of character c.
(6) single character
Inserts character c.
(7) range
Inserts a copy of the sequence of characters in the range [first,last), in the same order.
(8) initializer list
Inserts a copy of each of the characters in il, in the same order.
```

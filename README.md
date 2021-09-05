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
And the crucial thing that makes OO languages so powerful is, they allow type extensibility that allows you to program naturally with the new types.
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
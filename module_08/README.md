# Module_08

* [containers](#containers)
* [iterators](#iterators)
* [algorithm_function](#algorithm_function)
* [functor_class](#functor_class)
* [Sequential_containers](#Sequential_containers)
* [Ordered_associative_containers](#Ordered_associative_containers)
* [Unordered_associative_containers](#Unordered_associative_containers)
* [Adapters](#Adapters)
* [STL_containers_overview](#STL_containers_overview)
* [resources](#resources)


STL: Standard template library

Put in simple terms, the standard template library (STL) is a set of template classes and functions that supply the programmer with:

* Containers for storing information
* Iterators for accessing the information stored
* Algorithms for manipulating the content of the containers


## containers

holds elements and iterators (the containers equivalents of pointers, providing structured access to elements)

a set of values and a set of cohersive operations on these values

Containers are STL classes that are used to store data. STL supplies two types of container classes:
* *Sequential containers*
* *Associative containers*

*Container Adapters* are variants of the same with reduced functionality to support a specific purpose

| Sequential | Associative | Adapters  |
|------------|-------------|-----------|
|  vector    |     set     |   stack   |
|   deque    |   multi set |   queue   |
|    list    |    map      |piority queue|
|            |  multi map  |           |

all containers are parameterized by the types they contain

```cpp

template <typename T, typename Container = deque<T>>

class stack
{
	public:
		explicit stack(const Container&);
		bool empty() const;
		//etc
}

```

## iterators

Iterators in STL are template classes that in some ways are a generalization of pointers.
These are template classes that give the programmer a handle by which he can work with and manipulate STL containers and perform operations on them. Note that operations could as well be STL algorithms that are template functions, Iterators are the bridge that allows these template functions to work with containers, which are template classes, in a consistent and seamless manner.

Iterators let us view a non-linear collection in a linear manner. The whole point of iterators was to have a standard interface to iterate over data in any container. But we still had to specify what type of data this iterator was pointing to.

each container declares a trait for the type of iterator ir provides

* input
* output
* forward
* bidirection
* random access

iterators and const iterators ate the most common traits that are associated with the containers

each container provides factory methods for creating iterators:

* `begin()` `end()`: for traversing from front to back
* `rbegin()` `rend()`: for traversing from back to front

Better to be pre-increment if you don't need the value before it incremented

Postincrement must return the value the iterator had BEFORE it was incrementing; so, that previous value needs to be copied somewhere before altering it with the increment proper, so it's available to return.
The extra work may be a little or a lot, but it certainly can't be less than zero, compared to a preincrement, which can simply perform the incrementing and then return the just-altered value -- no copying // saving // etc necessary.
So, unless you specifically MUST have postincrement (because you're using the "value before increment" in some way), you should always use preincrement instead.

## algorithm_function

performs action indirectly on container's elements, using iterators, optionally guided by a functor

generic algorithms
* mutating (changing the content)
* non-mutating (only reads the content)
* sorting
* numeric

Some of the most used STL algorithms are:

* `std::find` : Helps find a value in a collection
* `std::find_if` : Helps find a value in a collection on the basis of a specific
user-defined predicate
* `std::reverse` : Reverses a collection
* `std::remove_if` : Helps remove an item from a collection on the basis of a
user-defined predicate
* `std::transform` : Helps

## functor_class

function objects

result used to guide algorithm, guide algorithm behaviors

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <list>

class IOperation;

int main()
{
	std::list<int>  lst1;
	std::map<std::string, IOperation*>  map1; //defining key values type for our map (hashtable)
	std::vector<int>    v1; //like an array powerfull
	std::vector<int>    v2(42, 100);

	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);

	map1["opA"] = new OperationA;
	map1["opB"] = new OperationB;

	std::list<int>::const_iterator  it;
	
	std::list<int>::const_iterator  ite = lst1.end(); //one after the last, like '\0' in strings

	for (it = lst1.begin(); it != ite; ++it)
    {
		std::cout << *it << std::endl; //dereference like pointers
    }
	return 0;
}
```

## Sequential_containers

* arrange the data in a linear manner
* element order has nothing to do with element value
* fast insertion, slow find operations

| container| characteristics |
|----------|----------------------------------|
|   **vector** | Linear and contiguos storage like an array that allows fast insertions and removals at the end only |
|   **list**  | *Doubly linked list* that allows fast insertions and removals anywhere |
|**foward_list**|*single linked list* that allows fast insertions and removals anywhere |
| **deque (double ended queu)** | Linear but non-contiguous storage that allows fast insertions and romovals at both ends |

**vector**

use contiguous storage locations

compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way

Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end. For operations that involve inserting or removing elements at positions other than the end, they perform worse than the others, and have less consistent iterators and references than lists and forward_lists.


## Ordered_associative_containers

* support efficient operations on elements using keys ordered by `operator<`
* implemented as balanced binary trees (red black tree)
* slow insertion, fast find operations

| container| characteristics |
|----------|----------------------------------|
|   **set** | elements values are the keys, duplicates not allowed. It has fast lookup using the key |
|   **multiset**  | same as set but with duplicates allowed |
|**map**|key-values pairs where a single key can only be mapped to one value|
| **multimap** |same as map but a single key can be mapped to many values|

## Unordered_associative_containers

* maintain data in structures suitable for fast associative operations
* implemented as hash tables
* slow insertion, fast find operations


| container| characteristics |
|----------|----------------------------------|
|   **unordered_set** | elements values are the keys, duplicates not allowed. It has fast lookup using the key |
|   **unordered_multiset**  | same as set but with duplicates allowed |
|**unordered_map**|key-values pairs where a single key can only be mapped to one value|
| **unordered_multimap** |same as map but a single key can be mapped to many values|

## Adapters

* provide alternative access sequential and associative containers

| container| characteristics |
|----------|----------------------------------|
|   **stack** | First in, last out data structure |
|   **queue**  | First in, first out data structure |
|**priority_queue**| Queue that maintains items in a sorted order based on a priority value|


## STL_containers_overview

* The standard containers
	* Sequence containers (used for data structures that store objects of the same type in a linear manner)
		* **array**: a static contiguous array
		* **vector**: a dynamic contiguous array
		* **forward_list**: a single-linked list
		* **list**: a doubly-linked list
		* **deque**: a double-ended queue, where elements can be added to the front or back of the queue
	* Container adapters (Not full container classes on their own, but wrappers around other container types. They encapsulate the underlying container type and limit the user interfaces accordingly.)
		* **stack**: provides an LIFO data structure
		* **queue**: provides a FILO data structure
		* **priority_queue**: provides a priority queue, which allows for constant-time lookup of the largest element (by default)
	* Associative containers
		* *keys are unique*
			* **set**: a collection of unique keys, sorted by keys
			* **map**: a collection of key-value pairs, sorted by keys
		* *Multiple entries for the same key are permitted*
			* **multiset**: a collection of unique keys, sorted by keys
			* **multimap**: a collection of key-value pairs, sorted by keys
	* Unordered associative containers
		* *Keys are unique*
			* **unordered set**: a collection of keys, hashed by keys
			* **unordered_map**: a collection of key-value pairs, hashed by keys
		* *Multiple entries for the same key are permitted*
			* **unordered_multiset**: a collection of keys, hashed by keys
			* **unordered_multimap**: a collection of key-value pairs, hashed by keys

|                 | Array | Vector | Deque | List | Forward List | Associative Containers | Unordered Containers |
|-----------------|-------|--------|-------|------|--------------|------------------------|----------------------|
| Available since |  TR1  |  C++98 | C++98 | C++98|    C++11     |         C++98          |         TR1          |
| Element type    | Value | Value  | Value |Value |    Value     |Set: value Map: key/value|Set: value Map: key/value|
|Duplicates allowed|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|Only multiset or multimap|Only multiset or multimap|
|Iterator category|Random access|Random access|Random access|Bidirectional|Forward|Bidirectional(element/key constant)|Forward(element/key constant)|
|Growing/Shrinking|Never|At one end|At both ends|Everywhere|Everywhere|Everywhere|Everywhere|
|Random access available|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|:x:|:x:|:x:|Almost|
|Search/find elements|Slow|Slow|Slow|Very Slow|Very Slow|Fast|Very Fast|
|Inserting/removing invalidates iterators| --- |On reallocation|Always|Never|Never|Never|On rehashing|
|Inserting/removing references, pointers| --- |On reallocation|Always|Never|Never|Never|Never|
|Allows memory reservation| --- |:heavy_check_mark:|:x:| --- | --- | --- | :heavy_check_mark: (buckets)|
|Frees memory for removed elements| --- | Only with `shrink_to_fit()`|Sometimes|Always|Always|Always|Sometimes|
|Transaction safe (success or no effect)|:x:|Push/pop at the end| Push/pop at the begining and the end|All insertions and all erasures|All insertions and all erasures|Single-element insertions and all erasures if comparing doesn't throw|Single-element insertions and all erasures if hashing and comparing doesn't throw|

![image](https://user-images.githubusercontent.com/63563271/141655399-05e73cdb-1ec9-4fb9-9441-c5e77128b8b2.png)


## resources

* [Overview of C++ STL Containers - video](https://www.youtube.com/watch?v=M1Zj8M48AvY)
* [qingqingqingli wiki](https://github.com/qingqingqingli/CPP/wiki/module08)
* [C++ STL's: When to use which STL](https://www.hackerearth.com/practice/notes/c-stls-when-to-use-which-stl/)
* [C++ STL Containers: Choose your containers wisely](https://dev.to/pratikparvati/c-stl-containers-choose-your-containers-wisely-4lc4)
* [Introducing iterators](https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter16_014.html)
* Sams Teach Yourself C++ in one Hour a Day
* [stack docs](https://en.cppreference.com/w/cpp/container/stack)
* [this stackoverflow thread](https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators)to ex02 - stack with iterators
* [std::stack implementation on different containers](https://coderedirect.com/questions/444298/stdstack-implementation-on-different-containers-what-is-the-actual-difference)

## notes

>The std::stack does expose its underlying container (and therefore iterators) to subclasses through its protected interface. The std::stack's underlying container object corresponds to the (protected) data member c.

`typedef Container::iterator iterator;`:
` error: need ‘typename’ before ‘Container::iterator’ because ‘Container’ is a dependent scope`

`iterator begin() {return std::begin(c);}`:
` note: ‘std::begin’ is only available from C++11 onwards`

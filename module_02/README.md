# Module_02

* [Ad-hoc_polymorphism](#Ad-hoc_polymorphism)
* [Operator_overload](#Operator_overload)
* [Canonical_form](#Canonical_form)
* [ex00 notes](#ex00)

## Ad-hoc_polymorphism

functions that have the same name put accepts different parameters

## Operator_overload

### Infix

An infix expression is an expression in which operators (+, -, *, /) are written between the two operands

```cpp
1 + 1
42 / 2
7 * 7
22 - 13
```

### Postfix

The postfix operator also contains operator and operands. In the postfix expression, the operator is written after the operand. It is also known as Reverse Polish Notation
Allows to make stack calculation

```cpp
A B +
A B + C -
A B C * +
A B + C * D -
```

[More about infix and prefix and how to convert them](https://www.javatpoint.com/program-to-convert-infix-to-postfix-expression-in-cpp-using-the-stack-data-structure)

### Prefix

prefix notation = functional notation

+ 1 1 ~= +(1, 1) ~= 1.+(1)

>Prefix and Postfix expressions can be evaluated faster than an infix expression. This is because we don’t need to process any brackets or follow operator precedence rule. In postfix and prefix expressions which ever operator comes before will be evaluated first, irrespective of its priority. Also, there are no brackets in these expressions. As long as we can guarantee that a valid prefix or postfix expression is used, it can be evaluated with correctness.
font:[evaluation prefix expressions](https://www.geeksforgeeks.org/evaluation-prefix-expressions/)

### unary, binary, ternary

how many operands an operator takes?

* unary operator -- has one operand
* binary operator -- has two operands
* ternary operator -- has three operands

![image](https://user-images.githubusercontent.com/63563271/134781968-da52ffe4-f166-4b19-ad11-5c4090720c58.png)

[More about operators](https://www.cs.fsu.edu/~myers/c++/notes/basics2.html)


### overloading an operator

```cpp

class Integer
{
	public:
		Integer(int const n);
		~Integer(void);
		
		int	getValue(void) const;
		
		Integer	&operator=(Integer const &right_hand_side); //operator is a key word that allow us to make operator overload. Cannot be void to allow operations like a = b = c = d;
		Integer	operator+(Integer const &right_hand_side) const; //like teh above func, here we have two arguments, hence the class instance is always passed as parameter too. If we want to overload an unary operator, no arguments will be needed. This is const cause we are not changing any of the two operand (the current instance is never changed)
	
	private:
		int _n;
};

std::ostream &operator << (std::ostream & o, Integer const &rhs); //stream redirector operator overload

```

```cpp

int Integer::getValue(void) const
{
	return this->_n;
}

Integer &Integer::operator=(Integer const &right_hand_side)
{
	this->_n = right_hand_side.getValue(); //since right_hand_side is an instage from class Integer
	return *this;
}

Integer Integer::operator+(Integer const &right_hand_side) const
{
	return Integer(this->_n + right_hand_side.getValue());
}

std::ostream &operator<<(std::ostream &outputFile, Integer const &right_hand_side)
{
	outputFile << right_hand_side.getValue();
	return outputFile;
}

```

the << overload allow us to output a number

```cpp
int main(void)
{
	Integer x(22);
	
	std::cout << "Value of x:" << x << std::endl;
	return (0);
}

```

>operator overloaded must be natural (with the expected behaviour)

>the cases when operator overload are justified are rare

### Canonical_form

be sure that theres certain number os fuctions available in all our class allowing uniform process

*at least a default constructor

```cpp

class MyClass
{
	public:
		MyClass(void);						//canonical - default constructor
		MyClass(int const n);
		MyClass(MyClass const &src);		//canonical - copy constructor, to make copys of the instance, receiving an instance as parameter MyClass instance2(instance1)
		~MyClass(void);						//canonical (missing something we will learn in the nexts lists)

		MyClass	&operator=(MyClass const &right_hand_side);	//canonical to assign values between instances, like instance3 = instance1

		int	getVar(void)const;
	
	private:
		int _var;
}

std::ostream &operator<<(std::ostream &outputFile, MyClass const &i); //not canonical but very commom and recomended
```

> orthodox canonical form: At least one default constructor, a copy contructor, an assignation operator overload and a destructor

## ex00

>Accuracy and precision are two concepts in measurement that nicely capture the different properties of ints and floats

`Accuracy` refers to how close a measurement is to the true value
`Precision` has to do with how much information you have about a quantity, how uniquely you have it pinned down

Integer arithmetic enjoys the property of complete accuracy, however, integers lack precision.
Floating point numbers are the exact opposite. They have good precision, since they never deliberately discard information representing your numbers. But floating point numbers have poor accuracy.

>Consider the number 1/3. No finite decimal digit representation (e.g. 0.333333) can ever be equal to 1/3; we can never have enough 3's. Thus it is more than likely that the computed result you need cannot be represented accurately by a finite floating point variable—you're going to be wrong by at least a little bit no matter what you do.

[understanding floating point](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)

[Introduction to Fixed Point Number Representation](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html)

To define a fixed point type conceptually, all we need are two parameters:

* width of the number representation, and
* binary point position within the number

diagram made by [Paulo Cunha](https://github.com/PCC19) 
![image](https://user-images.githubusercontent.com/63563271/134776413-5785a206-bc82-4aec-bb4f-b939962c89dd.png)

To convert from floating-point to fixed-point:

* Calculate x = floating_input * 2^(fractional_bits)
* Round x to the nearest whole number
* Store the rounded x in an integer container

`2^(fractional_bits)` == `1 << fractional_bits`

To convert from fixed to float, is the oposite: 
`(float)fixed_number / (float)(1 << fractional_bits)`

[Simple Fixed-Point Conversion in C](https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/)
